/* test_ballot_nextChoice.cc
* Unit test for nextChoice() in the Ballot class
* Author: Yiwen Xu (xu000515) **/
#include "ballot.h"
#include "candidate.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Ballot_nextChoice {
public:
  
  Ballot* setup(int testNumber) {
    if (testNumber == 1){
      std::vector<Candidate*> cands;
      Candidate *c1 = new Candidate(1, "Test");
      cands.push_back(c1);
      Ballot *temp = new Ballot(1, cands);
      return temp;
    }
    if (testNumber == 2){
      Ballot *temp = new Ballot(1,std::vector<Candidate*>());
      return temp;
    }
    return new Ballot(1,std::vector<Candidate*>());
  }
  
  void test_1() {
    Ballot *temp = this->setup(1);
    temp->nextChoice();
    assertm(temp->getCurrentChoice() == -1, "Test of nextChoice() function: incorrect value returned");
    std::cout << "Test of nextChoice() function passed." << std::endl;
  }
  
  void test_2() {
    Ballot *temp = this->setup(2);
    temp->nextChoice();
    assertm(temp->getCurrentChoice() == -1, "Test of nextChoice() function when current choice > the size of candidate_: incorrect value returned");
    std::cout << "Test of nextChoice() function when current choice > the size of candidate_ passed." << std::endl;
  }
};

int main()
{
  Test_Ballot_nextChoice test;
  test.test_1();
  test.test_2();
  return 0;
}


