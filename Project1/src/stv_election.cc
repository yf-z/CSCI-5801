/* stv_election.cc
* Implementations of the methods for the STVElection class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "stv_election.h"

STVElection::STVElection(std::string type, int seats, std::vector<Candidate*> cands, std::vector<Ballot*> bals, bool shuffle) : Election(type, seats, cands, bals),                  
                                                                                                                                                shuffle_(shuffle) {
  calculateDroop();
  std::srand(time(NULL));
  for(int i = 0; i < 100; i++) {
    std::rand();
  }

  for(int i = 0; i < (int)(bals.size()); i++) {
    shuffledBallots_.push_back(i);
  }
}

STVElection::~STVElection() {}

void STVElection::runAlgorithm() {
  // shuffle the ballots if necessary
  if(shuffle_ == true) {
    shuffleBallots();
  }

  time_t timer = time(NULL);
  int candidates_assigned = 0;

  // set up header for audit file
  auditText_ << "STV algorithm:\nCandidate names and Ids:";
  for(int i = 0; i < (int)(candidates_.size()); i++) {
    auditText_ << "\nName: " << candidates_[i]->getName() << "\tId: " << candidates_[i]->getId();
  }
  auditText_ << "\nNumber of seats: " << numSeats_ << "\nNumber of ballots: " << ballots_.size();
  auditText_ << "\nShuffled ballot order (by ballot Id) with ranks (highest->lowest):";
  for(int i = 0; i < (int)(shuffledBallots_.size()); i++) {
    auditText_ << "\n" << (i+1) << ". " << ballots_[shuffledBallots_[i]]->getId();
    std::vector<Candidate*> ranks = ballots_[shuffledBallots_[i]]->getCandidates();
    auditText_ << ": ";
    for(int i = 0; i < (int)ranks.size(); i++) {
      if(i == (int)ranks.size()-1) {
        auditText_ << ranks[i]->getName();
      }
      else {
        auditText_ << ranks[i]->getName() << ", ";
      }
    }
  }
  auditText_ << "\n";

  // initial distribution of ballots
  for(int i = 0; i < (int)(shuffledBallots_.size()); i++) {
    // get the current Candidate choice on the ballot
    Candidate* choice = ballots_[shuffledBallots_[i]]->getCandidates()[ballots_[shuffledBallots_[i]]->getCurrentChoice()];

    // make sure the ballot has a valid choice that it can be used to vote for
    bool has_valid_choice = true;

    // get first choice off ballot that hasn't already won
    while(choice->getAssignedStatus() == true) {
      // set ballot to next candidate choice and make sure it didn't run out
      ballots_[shuffledBallots_[i]]->nextChoice();
      if(ballots_[shuffledBallots_[i]]->getCurrentChoice() == -1) {
        has_valid_choice = false;
        break;
      }
      else {
        // if it didn't run out get the next choice
        choice = ballots_[shuffledBallots_[i]]->getCandidates()[ballots_[shuffledBallots_[i]]->getCurrentChoice()];
      }
    }

    // if the ballot didn't run out of options add it to the appropriate candidate
    if(has_valid_choice) {
      choice->addBallot(ballots_[shuffledBallots_[i]]);
      if(choice->getBallotsForSize() == 1) {
        choice->setWhenGotFirstBallot(difftime(time(NULL), timer));
      }
    }
    
    // add a candidate to the winners if they hit the droop quota
    if(choice->getBallotsForSize() == getDroop() && choice->getAssignedStatus() == false) {
      addWinner(choice);
      candidates_assigned += 1;
      choice->setAssignedStatus(true);
    }
  }

  // info for audit file after the initial distribution of ballots
  auditText_ << "\nAfter Initial Ballot Distribution:";
  auditText_ << "\nCandidate names and their ballots in assigned order (by Id): ";
  for(int i = 0; i < (int)(candidates_.size()); i++) {
    auditText_ << "\n" << candidates_[i]->getName() << ": ";
    std::list<Ballot*> bals = candidates_[i]->getBallotsFor();
    for(auto it = bals.cbegin(); it != bals.cend(); ++it) {
      if(it == bals.cbegin()) {
        auditText_ << (*it)->getId();
      }
      else {
        auditText_ << ", " << (*it)->getId();
      }
    }
  }
  auditText_ << "\nWinners (in order of victory): ";
  for(int i = 0; i < (int)(winners_.size()); i++) {
    if(i == (int)(winners_.size())-1) {
      auditText_ << winners_[i]->getName();
    }
    else {
      auditText_ << winners_[i]->getName() << ", ";
    }
  }

  // redistribution until all candidates are assigned to be a winner or loser
  int redistribution_count = 0;
  while(candidates_assigned < (int)(getCandidates().size())) {
    // find a losing candidate
    Candidate* loser = NULL;
    int loseBallotCount = 100001;
    for(int j = 0; j < (int)(getCandidates().size()); j++) {
      // make sure candidate hasn't been assigned winner or loser lists
      if(getCandidates()[j]->getAssignedStatus() == false) {
        if(getCandidates()[j]->getBallotsForSize() < loseBallotCount) {
          loser = getCandidates()[j];
          loseBallotCount = getCandidates()[j]->getBallotsForSize();
        }
        // if need to break a tie
        else if(getCandidates()[j]->getBallotsForSize() == loseBallotCount) {
          if(loseBallotCount == 0) {
            // pick a loser at random
            int rand_num = std::rand() % 10;
            if(rand_num < 5) {
              loser = getCandidates()[j];
              loseBallotCount = getCandidates()[j]->getBallotsForSize();
            }
          }
          else {
            // check who got a ballot first
            if(getCandidates()[j]->getWhenGotFirstBallot() > loser->getWhenGotFirstBallot()) {
              loser = getCandidates()[j];
              loseBallotCount = getCandidates()[j]->getBallotsForSize();
            }
          }
        }
      }
    }

    // add to loser list and redistribute their ballots
    addLoser(loser);
    candidates_assigned += 1;
    loser->setAssignedStatus(true);

    // add loser info to audit information in correct order followed by start of redistribution info
    auditText_ << "\nLosers (in order of defeat): ";
    for(int i = 0; i < (int)(losers_.size()); i++) {
      if(i == (int)(losers_.size())-1) {
        auditText_ << losers_[i]->getName();
      }
      else {
        auditText_ << losers_[i]->getName() << ", ";
      }
    }
    redistribution_count += 1;
    auditText_ << "\n\nAfter Redistribution " << redistribution_count << ":";

    redistribute(loser, timer);

    // increment candidates_assigned based on counts of winners and losers lists
    candidates_assigned = (int)(getWinners().size()) + (int)(getLosers().size());
  }

  // finish up loser info for audit file after final redistribution
  auditText_ << "\nLosers (in order of defeat): ";
  for(int i = 0; i < (int)(losers_.size()); i++) {
    if(i == (int)(losers_.size())-1) {
      auditText_ << losers_[i]->getName();
    }
    else {
      auditText_ << losers_[i]->getName() << ", ";
    }
  }
  auditText_ << "\n";

  // write to audit file
  this->writeToAuditFile();
}

int STVElection::getDroop() {
  return droopQuota_;
}

bool STVElection::getShuffleStatus() {
  return shuffle_;
}

std::vector<int> STVElection::getShuffledBallots() {
  return shuffledBallots_;
}

std::string STVElection::getResults() {
  std::string strResult;
  std::stringstream result;
  // add winners_vector to stringstream result
  result << "\nWinners vector:";

  // check if winners_ vector is empty
  if (!this->winners_.empty()) {
    for (int i = 0; i < (int)(this->winners_.size()); i++) {
      result << "\n" << i+1 << "."
        << "\tId: " << this->winners_.at(i)->getId()
        << "\tName: " << this->winners_.at(i)->getName();
    }
  }

  // add losers_ vector to stringstream result
  result << "\nLosers vector:";

  // check if winners_ vector is empty
  if (!this->losers_.empty()) {
    for (int i = 0; i < (int)(this->losers_.size());i++) {
      result << "\n" << i+1 << "."
        << "\tId: " << this->losers_.at(i)->getId()
        << "\tName: " << this->losers_.at(i)->getName();
    }
  }

  std::vector<Candidate*> final_winner;
  std::vector<Candidate*> final_losers;
  final_winner = this->winners_;
  final_losers = this->losers_;
  // check if the elction result has enough winners
  int temp = this->numSeats_ - (int)(this->winners_.size());

  // if it doesn't have enough winners, pull out last added losers to be winners
  if (temp > 0) {
    for (int i = 0; i < temp; i++) {
        //check if final_loses vector is empty
        if (!final_losers.empty()) {
          Candidate* temp  = final_losers.back();
          final_losers.pop_back();
          final_winner.push_back(temp);
        }
        else {
          break;
        }
    }
  }
  
  // add final winners to stringstream result
  result << "\nWinners of Seats in order:  ";

  // check if final winners vector is empty
  if (!final_winner.empty()) {
    for (int i = 0; i < (int)(final_winner.size()); i++) {
      result << "\n" << i+1 << '.'
        << "\tId: " << final_winner.at(i)->getId()
        << "\tName: " << final_winner.at(i)->getName();
    }
  }
  
  // add final losers to stringstream result
  result << "\nLosers in Order: ";
  
  // check if final losers vector is empty
  if (!final_losers.empty()) {
    for (int i = 0; i < (int)(final_losers.size()); i++) {
      result << "\n" << i+1 << '.'
        << "\tId: " << final_losers.at(i)->getId()
        << "\tName: " << final_losers.at(i)->getName();
    }
  }
  
  strResult = result.str();
  return strResult;
}

void STVElection::calculateDroop() {
  // if number of seats is non positive
  if (this->numSeats_ <= 0) {
    // if ballots is not empty
    if (!this->ballots_.empty()) {
      this->droopQuota_ = (int)(this->ballots_.size()) + 1;
    }
    // else, if ballots is empty
    else {
      this->droopQuota_ = 1;
    }
  }
  // else if number of seats is positive
  else {
    // if ballots is not empty
    if (!this->ballots_.empty()) {
      int numBallots = (int)(this->ballots_.size());
      int droopQuota = floor(numBallots/(this->numSeats_+1))+1;
      this->droopQuota_ = droopQuota;
    }
    // if ballots is empty
    else {
      this->droopQuota_ = 1;
    }
  }

}

void STVElection::shuffleBallots() {
  std::vector<int>::iterator it;

  // shullfe index if ballots_ is not empty
  if (!this->ballots_.empty()) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(this->shuffledBallots_.begin(), this->shuffledBallots_.end(), std::default_random_engine(seed));
  }
  else {
    return;
  }
}

void STVElection::redistribute(Candidate* loser, time_t timer) {
  // remove and redistribute ballots in the order they were assigned
  int bals_count = loser->getBallotsForSize();
  for(int i = 0; i < bals_count; i++) {
    Ballot* curr_bal = loser->removeBallot();

    // this choice is no longer valid but will be overriden shortly
    Candidate* choice = curr_bal->getCandidates()[curr_bal->getCurrentChoice()];

    // used make sure the ballot has a valid choice that it can be used to vote for
    bool has_valid_choice = true;

    // get first choice off ballot that hasn't already won/lost
    // will enter this loop once for sure
    while(choice->getAssignedStatus() == true) {
      // set ballot to next candidate choice and make sure it didn't run out
      curr_bal->nextChoice();
      if(curr_bal->getCurrentChoice() == -1) {
        has_valid_choice = false;
        break;
      }
      else {
        // if it didn't run out get the next choice
        choice = curr_bal->getCandidates()[curr_bal->getCurrentChoice()];
      }
    }

    // if the ballot didn't run out of options add it to the appropriate candidate
    if(has_valid_choice) {
      choice->addBallot(curr_bal);
      if(choice->getBallotsForSize() == 1) {
        choice->setWhenGotFirstBallot(difftime(time(NULL), timer));
      }
    }
    
    // add a candidate to the winners if they hit the droop quota
    if(choice->getBallotsForSize() == getDroop() && choice->getAssignedStatus() == false) {
      addWinner(choice);
      choice->setAssignedStatus(true);
    }  
  }

  // info for audit file after the redistribution of ballots
  auditText_ << "\nCandidate names and their ballots in assigned order (by Id): ";
  for(int i = 0; i < (int)(candidates_.size()); i++) {
    auditText_ << "\n" << candidates_[i]->getName() << ": ";
    std::list<Ballot*> bals = candidates_[i]->getBallotsFor();
    for(auto it = bals.cbegin(); it != bals.cend(); ++it) {
      if(it == bals.cbegin()) {
        auditText_ << (*it)->getId();
      }
      else {
        auditText_ << ", " << (*it)->getId();
      }
    }
  }
  auditText_ << "\nWinners (in order of victory): ";
  for(int i = 0; i < (int)(winners_.size()); i++) {
    if(i == (int)(winners_.size())-1) {
      auditText_ << winners_[i]->getName();
    }
    else {
      auditText_ << winners_[i]->getName() << ", ";
    }
  }
  
}

Candidate* STVElection::removeLastLoser() {
  // if losers_ is not empty
  if (!this->losers_.empty()) {
    Candidate* temp = this->losers_.back();
    this->losers_.pop_back();
    return temp;
  }
  // if losers_ is empty
  else {
    Candidate* temp = new Candidate(-1, "none");
    return temp;
  }
}
