/* test_ballot_getId.cc
* Unit test for getId() in the Ballot class
* Author: Yiwen Xu (xu000515) **/
#include "ballot.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Ballot_getId {
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
    assertm(temp->getId() == 1, "Test of getId() function: incorrect value returned");
    std::cout << "Test of getId() function passed." << std::endl;
  }
};

int main()
{
  Test_Ballot_getId test;
  test.test_1();
  return 0;
}


