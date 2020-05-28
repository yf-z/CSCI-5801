/* test_candidate_constructor.cc
* Unit test for constructor in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_Constructor {
  public:
    
    Candidate setup(int testNumber) {
      int id = 1;
      std::string name = "Test";
       return Candidate(id, name);
    }
  
    void test_1() {
      Candidate temp = setup(1);
      assertm(temp.getId() == 1, "Test of Candidate Constructor: Id not set properly");
      assertm(temp.getName().compare("Test") == 0, "Test of Candidate Constructor: name not set properly");
      assertm(temp.getBallotsForSize() == 0, "Test of Candidate Constructor: ballotForSize not set properly");
      assertm(temp.getWhenGotFirstBallot()== -1.0, "Test of Candidate Constructor: WhenGotFirstBallot not set properly");
      assertm(temp.getAssignedStatus()== false, "Test of Candidate Constructor: assigned status not set properly");
      std::cout << "Test of Candidate Constructor passed." << std::endl;
    }
};

int main()
{
  Test_Candidate_Constructor test;
  test.test_1();
  return 0;
}

