/* <test_election_getBallots.cc>
* Unit test for <getBallots()> in the <Election> class
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

class Test_getBallots {
  public:
   
    Election* setup(int testNumber) {
      if (testNumber == 1) {
        Election *temp =  new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        return temp;
      }
      else if (testNumber == 2) {
        std::vector<Ballot*> tempB;
        tempB.push_back(new Ballot(1, std::vector<Candidate*>()));
        Election *temp = new PluralityElection("test", 1, std::vector<Candidate*>(), tempB);
        return temp;
      }
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup(1);
      assertm(temp->getBallots().empty(), "Test with empty vector of ballots");
      std::cout << "Test with empty vector of ballots passed." << std::endl;
    }

    void test_2() {
      Election *temp = this->setup(2);
      assertm(temp->getBallots().size() == 1 && temp->getBallots().at(0)->getId() == 1 && temp->getBallots().at(0)->getCandidates().empty(), "Test with vector of ballots with size 1, and the only ballot's id is 1 and its vector of candidates is empty");
      std::cout << "Test with vector of ballots with size 1, and the only ballot's id is 1 and its vector of candidates is empty passed." << std::endl;
    }
};

int main()
{
  Test_getBallots test;
  test.test_1();
  test.test_2();
  return 0;
}