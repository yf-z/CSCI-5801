/* test_candidate_getWhenGotFirstBallot.cc
* Unit test for getWhenGotFirstBallot() in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_getWhenGotFirstBallot {
  public:
    
    Candidate setup(int testNumber) {
      int id = 1;
      std::string name = "Test";
      Candidate temp = Candidate(id, name);
      temp.setWhenGotFirstBallot(1);
      return temp;
    }
  
    void test_1() {
      Candidate temp = setup(1);
      assertm(temp.getWhenGotFirstBallot() == 1, "Test of Candidate getWhenGotFirstBallot: incorrect value returned");
      std::cout << "Test of Candidate getWhenGotFirstBallot passed." << std::endl;
    }
};

int main()
{
  Test_Candidate_getWhenGotFirstBallot test;
  test.test_1();
  return 0;
}

