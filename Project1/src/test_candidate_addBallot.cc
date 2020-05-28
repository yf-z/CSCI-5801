/* test_candidate_addBallot.cc
* Unit test for addBallot() in the Candidate class
* Author: Yiwen Xu (xu000515) **/
#include "candidate.h"
#include "ballot.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Candidate_addBallot {
  public:
    
    Candidate setup(int testNumber) {
      if (testNumber == 1){
        int id = 1;
        std::string name = "Test";
        Candidate can = Candidate(id, name);
        for (int i = 0; i < 1000; i++) {
          Ballot *temp = new Ballot(i, std::vector<Candidate*>());
          can.addBallot(temp);
        }
        return can;
      }
      return Candidate(1, "Test");
    }
  
    void test_1() {
      Candidate temp = setup(1);

      std::list<Ballot*> tempList = temp.getBallotsFor();
      
      int id = 0;

      for (auto iter = tempList.cbegin(); iter != tempList.cend(); iter++) {
        assertm((*iter)->getId() == id, "Test of Candidate addBallot(): invalid value returned");
        id++;
        std::cout << id << "Test of Candidate addBallot() passed." << std::endl;
      }

    }
};

int main()
{
  Test_Candidate_addBallot test;
  test.test_1();
  return 0;
}




