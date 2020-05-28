/* test_plurality_constructor.cc
* Unit test for constructor in the Plurality class
* Author: Yiwen Xu (xu000515) **/
#include "plurality_election.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Plurality_Constructor {
  public:
    
    PluralityElection* setup(int testNumber) {
      std::string type = "Plurality";
      int seats = 3;
      std::vector<Candidate*> cands;
      std::vector<Ballot*> bals;
      
      for(int i = 0; i < 4; i++) {
        cands.push_back(new Candidate(i, "test"));
      }


      for(int i = 0; i < 10; i++) {
        std::vector<Candidate*> choices;
        for(int j = 0; j < 2; j++) {
          choices.push_back(cands[j]);
        }
        bals.push_back(new Ballot(i, choices));
      }
      PluralityElection* temp = new PluralityElection(type, seats, cands, bals);
      return temp;
  }
  void test_1() {
    PluralityElection* temp = setup(1);
    assertm(temp->getType().compare("Plurality") == 0, "Test of PluralityElection Constructor: type not set properly");
    assertm(temp->getNumSeats() == 3, "Test of PluralityElection Constructor: number of seats not set properly");
    assertm(temp->getCandidates().size() == 4, "Test of PluralityElection Constructor: candidates vector not set properly");
    for(int i = 0; i < 4; i++) {
      assertm(temp->getCandidates()[i]->getId() == i, "Test of PluralityElection Constructor: candidates vector not set properly");
    }
    assertm(temp->getBallots().size() == 10, "Test of PluralityElection Constructor: ballots vector not set properly");
    for(int i = 0; i < 10; i++) {
      assertm(temp->getBallots()[i]->getId() == i, "Test of PluralityElection Constructor: ballots vector not set properly");
    }
    std::cout << "Test of PluralityElection Constructor passed." << std::endl;
  }
};

int main()
{
  Test_Plurality_Constructor test;
  test.test_1();
  return 0;
}
