/* test_candidate_setWhenGotFirstBallot.cc
* Unit test for setWhenGotFirstBallot() in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_setWhenGotFirstBallot {
  public:
    
    Candidate setup(int testNumber) {
      int id = 1;
      std::string name = "Test";
      Candidate temp = Candidate(id, name);
      return temp;
    }
  
    void test_1() {
      Candidate temp = setup(1);
      temp.setWhenGotFirstBallot(1);
      assertm(temp.getWhenGotFirstBallot() == 1, "Test of Candidate setWhenGotFirstBallot: WhenGotFirstBallot not set properly");
      std::cout << "Test of Candidate setWhenGotFirstBallot passed." << std::endl;
    }
};

int main()
{
  Test_Candidate_setWhenGotFirstBallot test;
  test.test_1();
  return 0;
}


