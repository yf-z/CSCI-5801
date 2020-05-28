/* test_candidate_getName.cc
* Unit test for getName() in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_getName {
  public:
    
    Candidate setup(int testNumber) {
      int id = 1;
      std::string name = "Test";
       return Candidate(id, name);
    }
  
    void test_1() {
      Candidate temp = setup(1);
      assertm(temp.getName().compare("Test") == 0, "Test of Candidate getName: incorrect value returned");
      std::cout << "Test of Candidate getName passed." << std::endl;
    }
};

int main()
{
  Test_Candidate_getName test;
  test.test_1();
  return 0;
}


