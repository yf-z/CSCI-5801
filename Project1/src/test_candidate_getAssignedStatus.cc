/* test_candidate_getAssignedStatus.cc
* Unit test for getAssignedStatus() in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_getAssignedStatus {
  public:
    
    Candidate setup(int testNumber) {
      int id = 1;
      std::string name = "Test";
      Candidate temp = Candidate(id, name);
      return temp;
    }
  
    void test_1() {
      Candidate temp = setup(1);
      assertm(temp.getAssignedStatus() == false, "Test of Candidate getAssignedStatus: incorrect value returned");
      std::cout << "Test of Candidate getAssignedStatus passed." << std::endl;
    }
};

int main()
{
  Test_Candidate_getAssignedStatus test;
  test.test_1();
  return 0;
}


