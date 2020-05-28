/* plurality_election.cc
* Implementations of the methods for the PluralityElection class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "plurality_election.h"

#include <iostream>
#include <algorithm>

PluralityElection::PluralityElection(std::string type, int seats, std::vector<Candidate*> cands, std::vector<Ballot*> bals) : Election(type, seats, cands, bals) {}

PluralityElection::~PluralityElection() {}

void PluralityElection::runAlgorithm() {

  auditText_ << "Plurality algorithm:\nCandidate names and Ids:";
  
  // audit the initial state of the election
  for (int i = 0; i < (int)(candidates_.size()); i++) {
    auditText_ << "\nName: " << candidates_.at(i)->getName()
      << "\tId: " << candidates_.at(i)->getId();
  }
  
  auditText_ << "\nNumber of seats: " << numSeats_
    << "\nNumber of ballots: " << ballots_.size()
    << "\n";
  
  // assign the ballots to the candidates and audit the process
  for (int j = 0; j < (int)(candidates_.size()); j++) {
    int id = candidates_.at(j)->getId();
    for (int k = 0; k < (int)(ballots_.size()); k++){
      std::vector<Candidate*> c = ballots_.at(k)->getCandidates();
      // the callot belongs to the candidate
      if(c[0]->getId() == id) {
        candidates_.at(j)->addBallot(ballots_.at(k));
        auditText_ << "\nBallot ID " << ballots_.at(k)->getId()
          << " assigned to " << "candidate ID " << c[0]->getId();
      }
    }
  }
  
  // sort the candidates by their number of ballots
  sortCandidates();
  
  // since the vector of candidates had been sorted, divide the candidates into winners and losers by order
  for (int m = 0; m < numSeats_ && m < (int)(candidates_.size()); m++){
    winners_.push_back(candidates_.at(m));
  }
  
  for (int n = numSeats_; n < (int)(candidates_.size()); n++){
    losers_.push_back(candidates_.at(n));
  }

  // wirte audit file
  this->writeToAuditFile();
  return;
}

// get the result of the election including the percentage for each candidate and the list of winners and losers
// this is to be called in the displayResult() method
std::string PluralityElection::getResults() {
  std::string temp;
  std::stringstream result;
  std::vector<float> p = calculatePercentages();
  
  result << "\nCandidates Id, name and their percentage: ";
  
  for (int i = 0; i < (int)(candidates_.size()); i++)
    result << "\nId: " << candidates_.at(i)->getId()
      << "\nName: " << candidates_.at(i)->getName()
      << "\nPercentage: " << p.at(i);
  
  result << "\n\n\nWinners: ";
  
  for (int j = 0; j < (int)(winners_.size()); j++)
    result << "\nId: " << winners_.at(j)->getId()
      << "\nName: " << winners_.at(j)->getName();
  
  result << "\n\n\nLosers: ";
  
  for (int j = 0; j < (int)(losers_.size()); j++)
    result << "\nId: " << losers_.at(j)->getId()
      << "\nName: " << losers_.at(j)->getName();
  
  temp = result.str();
  
  return temp;
}

//calculate the percentage of the ballots each candidate got to the total number of ballots
std::vector<float> PluralityElection::calculatePercentages() {
  std::vector<float> percentage;
  float temp;
  
  for (int i = 0; i < (int)(candidates_.size()); i++){
    temp = (float)candidates_.at(i)->getBallotsForSize()/(float)(ballots_.size());
    percentage.push_back(temp);
  }
  return percentage;
}

//sort the candidates_ vector by their number of ballots
void PluralityElection::sortCandidates(){
  if(candidates_.empty())
    return;
  else {
    auto dec = [](Candidate* c1, Candidate* c2) {

      if (c1->getBallotsForSize() > c2->getBallotsForSize())
        return 1;
      else return 0;
  };
  
  sort(candidates_.begin(), candidates_.end(), dec);
  
  return;
  }
}
