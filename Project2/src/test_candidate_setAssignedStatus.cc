/* test_candidate_setAssignedStatus.cc
* Unit test for setAssignedStatus() in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_setAssignedStatus {
  public:
    
    Candidate setup(int testNumber) {
      int id = 1;
      std::string name = "Test";
      Candidate temp = Candidate(id, name);
      return temp;
    }
  
    void test_1() {
      Candidate temp = setup(1);
      temp.setAssignedStatus(true);
      assertm(temp.getAssignedStatus() == true, "Test of Candidate getAssignedStatus: AssignedStatus not set properly");
      std::cout << "Test of Candidate getAssignedStatus passed." << std::endl;
    }
};

int main()
{
  Test_Candidate_setAssignedStatus test;
  test.test_1();
  return 0;
}


