/* test_ballot_constructor.cc
* Unit test for constructor in the Ballot class
* Author: Yiwen Xu (xu000515) **/
#include "ballot.h"
#include "candidate.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Ballot_Constructor {
  public:
    
    Ballot setup(int testNumber) {
      int id = 1;
      std::vector<Candidate*> cands;
      Candidate *c1 = new Candidate(1, "Test");
      cands.push_back(c1);
      return Ballot(id, cands);
    }
  
    void test_1() {
      Ballot temp = setup(1);
      assertm(temp.getId() == 1, "Test of Ballot Constructor: Id not set properly");
      assertm(temp.getCurrentChoice() == 0, "Test of Ballot Constructor: CurrentChoice not set properly");
      assertm(temp.getCandidates()[0]->getId() == 1, "Test of Ballot Constructor: candidates not set properly");
      std::cout << "Test of Ballot Constructor passed." << std::endl;
    }
};

int main()
{
  Test_Ballot_Constructor test;
  test.test_1();
  return 0;
}
