/* ballot.cc
* Implementations of the methods for the Ballot class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "ballot.h"

Ballot::Ballot(int id, std::vector<Candidate*> choices) : id_(id), candidates_(choices), currentChoice_(0) {}

Ballot::~Ballot() {}

int Ballot::getId() {
  return id_;
}

void Ballot::setId(int id) {
  id_ = id;
}

std::vector<Candidate*> Ballot::getCandidates() {
  return candidates_;
}

int Ballot::getCurrentChoice() {
  return currentChoice_;
}

void Ballot::nextChoice() {
  currentChoice_++;
  if(currentChoice_ >= (int)(candidates_.size())){
    // Ballot is invalid and needs to be thrown out during redistribution
    currentChoice_ = -1;
  }
  return;
}
