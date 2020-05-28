/* test_candidate_agetBallotForSize.cc
* Unit test for getBallotForSize() in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"
#include "ballot.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_getBallotsForSize {
  public:
    
    Candidate setup(int testNumber) {
      if (testNumber == 1){
        int id = 1;
        std::string name = "Test";
        Candidate can = Candidate(id, name);
        Ballot *temp = new Ballot(1, std::vector<Candidate*>());
        can.addBallot(temp);
        return can;
      }
      return Candidate(1, "Test");
    }
  
    void test_1() {
      Candidate temp = setup(1);
      assertm(temp.getBallotsForSize() == 1, "Test of Candidate getBallotsForSize: incorrect value returned");
      std::cout << "Test of Candidate getBallotsForSize passed." << std::endl;
    }
};

int main()
{
  Test_Candidate_getBallotsForSize test;
  test.test_1();
  return 0;
}




