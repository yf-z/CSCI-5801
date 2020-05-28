/* test_stv_election_constructor.cc
* Unit test for STVElection(std::string type, int seats, std::vector<Candidate*> cands, std::vector<Ballot*> bals, bool shuffle) in the STVElection class
* Author: Brendan Ritchie (ritch167) **/

#include "stv_election.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_STVElection_Constructor {
  public:
   
    STVElection* setup(int testNumber) {
      std::string type = "STV";
      int seats = 3;
      std::vector<Candidate*> cands;
      std::vector<Ballot*> bals;
      bool shuffle = false;
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
      assertm(temp->getType().compare("STV") == 0, "Test of STVElection Constructor: type not set properly");
      assertm(temp->getNumSeats() == 3, "Test of STVElection Constructor: number of seats not set properly");
      assertm(temp->getShuffleStatus() == false, "Test of STVElection Constructor: shuffle status not set properly");
      assertm(temp->getCandidates().size() == 4, "Test of STVElection Constructor: candidates vector not set properly");
      for(int i = 0; i < 4; i++) {
        assertm(temp->getCandidates()[i]->getId() == i, "Test of STVElection Constructor: candidates vector not set properly");
      }
      assertm(temp->getBallots().size() == 10, "Test of STVElection Constructor: ballots vector not set properly");
      for(int i = 0; i < 10; i++) {
        assertm(temp->getBallots()[i]->getId() == i, "Test of STVElection Constructor: ballots vector not set properly");
      }
      assertm(temp->getAuditFilePath().compare("") == 0, "Test of STVElection Constructor: audit file path not set properly");
      assertm(temp->getDroop() == 3, "Test of STVElection Constructor: droop quota not set properly");
      assertm(temp->getShuffledBallots().size() == 10, "Test of STVElection Constructor: shuffled ballots vector not set properly");
      for(int i = 0; i < (int)temp->getShuffledBallots().size(); i++) {
        assertm(temp->getShuffledBallots()[i] == i, "Test of STVElection Constructor: shuffled ballots vector not set properly");
      }
      std::cout << "Test of STVElection Constructor passed." << std::endl;
    }

};

int main()
{
  Test_STVElection_Constructor test;
  test.test_1();
  return 0;
}
