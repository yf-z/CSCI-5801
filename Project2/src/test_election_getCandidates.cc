/* <test_election_getCandidates.cc>
* Unit test for <getCandidates()> in the <Election> class
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

class Test_getCandidates {
  public:
   
    Election* setup(int testNumber) {
      if (testNumber == 1) {
        Election *temp =  new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        return temp;
      }
      else if (testNumber == 2) {
        std::vector<Candidate*> tempC;
        tempC.push_back(new Candidate(1, "test"));
        Election *temp = new PluralityElection("test", 1, tempC, std::vector<Ballot*>());
        return temp;
      }
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup(1);
      assertm(temp->getCandidates().empty(), "Test with empty vector of candidates");
      std::cout << "Test with empty vector of candidates passed." << std::endl;
    }

    void test_2() {
      Election *temp = this->setup(2);
      assertm(temp->getCandidates().size() == 1 && temp->getCandidates().at(0)->getId() == 1 && temp->getCandidates().at(0)->getName().compare("test") == 0 && temp->getCandidates().at(0)->getBallotsFor().empty(), "Test with vector of candidates with size 1, and the only candidate's id is 1, name is \"test\" and its vector of ballots is empty");
      std::cout << "Test with vector of candidates with size 1, and the only candidate's id is 1, name is \"test\" and its vector of ballots is empty passed." << std::endl;
    }
};

int main()
{
  Test_getCandidates test;
  test.test_1();
  test.test_2();
  return 0;
}