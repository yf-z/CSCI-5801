/* <test_election_addWinner.cc>
* Unit test for <addWinner()> in the <Election> class
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

class Test_addWinner {
  public:
   
    Election* setup() {
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup();
      Candidate *tempB = new Candidate(1, "test");
      temp->addWinner(tempB);
      assertm(temp->winners_.size() == 1 && temp->winners_.at(0)->getId() == 1 && temp->winners_.at(0)->getName().compare("test") == 0, "Test with vector of winners with size == 1, its candidate id = 1. name = \"test\"");
      std::cout << "Test with vector of winners with size == 1, its candidate id = 1. name = \"test\" passed." << std::endl;
    }
};

int main()
{
  Test_addWinner test;
  test.test_1();
  return 0;
}