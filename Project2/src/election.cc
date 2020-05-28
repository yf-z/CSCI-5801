/* election.cc
* Implementations of the methods for the Election class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "election.h"

Election::Election(std::string type, int seats, std::vector<Candidate*> cands, std::vector<Ballot*> bals) : type_(type), numSeats_(seats), 
                                                                                        candidates_(cands), ballots_(bals), auditFilePath_("") {}

Election::~Election() {}

std::string Election::getType() {
  return type_;
}

int Election::getNumSeats() {
  return numSeats_;
}

std::vector<Candidate*> Election::getCandidates() {
  return candidates_;
}

std::vector<Ballot*> Election::getBallots() {
  return ballots_;
}

std::vector<Candidate*> Election::getWinners() {
  return winners_;
}

std::vector<Candidate*> Election::getLosers() {
  return losers_;
}

std::string Election::getAuditFilePath() {
  return auditFilePath_;
}

void Election::setAuditFilePath(std::string name) {
  auditFilePath_ = name;
}

std::string get_timestamp(){
  // helper function to get current UNIX timestamp
  return std::to_string(std::chrono::seconds(std::time(NULL)).count());
}

void Election::writeToAuditFile() {
  std::ofstream auditFile;
  std::string fileName;

  // check if auditFilePath_ is empty, if it is, set the auditFilePath_
  if (this->auditFilePath_.empty()) {
    this->auditFilePath_ = this->type_ + "_" + get_timestamp() + ".txt";
  }

  // write audit file
  auditFile.open(this->auditFilePath_);
  if (!this->auditText_.str().empty()) {
    auditFile << this->auditText_.str();
  }

  std::string result = this->getResults();
  if (!result.empty()) {
    auditFile << this->getResults();
  }
  auditFile.close();
}

void Election::addWinner(Candidate *win) {
  this->winners_.push_back(win);
}

void Election::addLoser(Candidate *lose) {
  this->losers_.push_back(lose);
}