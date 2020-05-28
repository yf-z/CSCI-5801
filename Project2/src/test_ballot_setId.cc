/* test_ballot_setId.cc
* Unit test for setId() in the Ballot class
* Author: Yiwen Xu (xu000515) **/
#include "ballot.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Ballot_setId {
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
    temp->setId(3);
    assertm(temp->getId() == 3, "Test of setId() function: Id not set properly");
    std::cout << "Test of setId() function passed." << std::endl;
  }
};

int main()
{
  Test_Ballot_setId test;
  test.test_1();
  return 0;
}

