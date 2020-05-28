/* candidate.cc
* Implementations of the methods for the Candidate class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "candidate.h"

Candidate::Candidate(int id, std::string name) : id_(id), name_(name), ballotsForSize_(0), whenGotFirstBallot_(-1.0), assigned_(false) {}

Candidate::~Candidate() {}

int Candidate::getId() {
  return id_;
}

std::string Candidate::getName() {
  return name_;
}
    
std::list<Ballot *> Candidate::getBallotsFor() {
  return ballotsFor_;
}


//add a Ballot to the end of the forward_list
void Candidate::addBallot(Ballot* new_ballot) {
  ballotsFor_.push_back(new_ballot);
  ballotsForSize_++;
  return;
}

//remove a Ballot from the front of the forward_list
Ballot* Candidate::removeBallot() {
  Ballot* temp = NULL;
  ballotsForSize_--;
  temp = ballotsFor_.front();
  ballotsFor_.pop_front();
  return temp;
}

int Candidate::getBallotsForSize() {
  return ballotsForSize_;
}

double Candidate::getWhenGotFirstBallot() {
  return whenGotFirstBallot_;
}

void Candidate::setWhenGotFirstBallot(double time) {
  whenGotFirstBallot_ = time;
}

bool Candidate::getAssignedStatus() {
  return assigned_;
}

void Candidate::setAssignedStatus(bool status) {
  assigned_ = status;
}
