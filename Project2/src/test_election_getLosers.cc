/* <test_election_getLosers.cc>
* Unit test for <getLosers()> in the <Election> class
* Author: <Yifan Zhang (zhan4372)> **/

#include "election.h"
#include "plurality_election.h"
#include "candidate.h"
#include "ballot.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_getLosers {
  public:
   
    Election* setup(int testNumber) {
      if (testNumber == 1) {
        Election *temp =  new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        return temp;
      }
      else if (testNumber == 2) {
        Election *temp = new PluralityElection("test", 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        Candidate *tempC = new Candidate(1, "loser");
        std::vector<Candidate*> tempCV;
        tempCV.push_back(tempC);
        Ballot *tempB = new Ballot(0, tempCV);
        tempC->addBallot(tempB);
        temp->addLoser(tempC);
        return temp;
      }
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup(1);
      assertm(temp->getLosers().empty(), "Test with empty vector of losers");
      std::cout << "Test with empty vector of losers passed." << std::endl;
    }

    void test_2() {
      Election *temp = this->setup(2);
      assertm(temp->getLosers().size() == 1 && temp->getLosers().at(0)->getId() == 1 && temp->getLosers().at(0)->getBallotsFor().front()->getId() == 0 && temp->getLosers().at(0)->getName().compare("loser") == 0, "Test with vector of losers with size 1, and the only candidate's id is 1, name as \"loser\" and its vector of ballots has only one ballot with id == 0");
      std::cout << "Test with vector of losers with size 1, and the only candidate's id is 1, name as \"loser\" and its vector of ballots has only one ballot with id == 0 passed." << std::endl;
    }
};

int main()
{
  Test_getLosers test;
  test.test_1();
  test.test_2();
  return 0;
}