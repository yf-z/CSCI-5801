/* test_ballot_getCandidates.cc
* Unit test for getCandidates() in the Ballot class
* Author: Yiwen Xu (xu000515) **/
#include "ballot.h"
#include "candidate.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Ballot_getCandidates {
public:
  
  Ballot* setup(int testNumber) {
    if (testNumber == 1){
      std::vector<Candidate*> cands;
      Candidate *c1 = new Candidate(1, "Test");
      cands.push_back(c1);
      Ballot *temp = new Ballot(1, cands);
      return temp;
    }
    return new Ballot(1,std::vector<Candidate*>());
  }
  
  void test_1() {
    Ballot *temp = this->setup(1);
    assertm(temp->getCandidates().size() == 1, "Test of getCandidates() function : incorrect size of vector returned.");
    assertm(temp->getCandidates()[0]->getId() == 1, "Test of getCandidates() function: incorrect value returned");
    std::cout << "Test of getCandidates() function passed." << std::endl;
  }
};

int main()
{
  Test_Ballot_getCandidates test;
  test.test_1();
  return 0;
}


