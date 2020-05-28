/* test_stv_election_getShuffleStatus.cc
* Unit test for getShuffleStatus() in the STVElection class
* Author: Brendan Ritchie (ritch167) **/

#include "stv_election.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_STVElection_getShuffleStatus {
  public:
   
    STVElection* setup(int testNumber) {
      std::string type = "STV";
      int seats = 3;
      std::vector<Candidate*> cands;
      std::vector<Ballot*> bals;
      bool shuffle = true;
      for(int i = 0; i < 4; i++) {
        Candidate* cand0 = new Candidate(i, "test");
        cands.push_back(cand0);
      }

      for(int i = 0; i < 10; i++) {
        std::vector<Candidate*> choices;
        for(int j = 0; j < 2; j++) {
          choices.push_back(cands[j]);
        }
        Ballot* bal0 = new Ballot(i, choices);
        bals.push_back(bal0);
      }
      STVElection* temp = new STVElection(type, seats, cands, bals, shuffle);
      return temp;
    }

    void test_1() {
      STVElection* temp = setup(1);
      assertm(temp->getShuffleStatus() == true, "Test of getShuffleStatus() function: incorrect value returned");
      std::cout << "Test of getShuffleStatus() function passed." << std::endl;
    }

};

int main()
{
  Test_STVElection_getShuffleStatus test;
  test.test_1();
  return 0;
}