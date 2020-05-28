/* test_ballot_getCurrentChoice.cc
* Unit test for getCurrentChoice() in the Ballot class
* Author: Yiwen Xu (xu000515) **/
#include "ballot.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Ballot_getCurrentChoice {
public:
  
  Ballot* setup(int testNumber) {
    if (testNumber == 1){
      Ballot *temp = new Ballot(1,std::vector<Candidate*>());
      return temp;
    }
    return new Ballot(1,std::vector<Candidate*>());
  }
  
  void test_1() {
    Ballot *temp = this->setup(1);
    assertm(temp->getCurrentChoice() == 0, "Test of getCurrentChoice() function: incorrect value returned");
    std::cout << "Test of getCurrentChoice() function passed." << std::endl;
  }
};

int main()
{
  Test_Ballot_getCurrentChoice test;
  test.test_1();
  return 0;
}

