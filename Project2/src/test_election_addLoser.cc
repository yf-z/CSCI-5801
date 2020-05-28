/* <test_election_addLoser.cc>
* Unit test for <addLoser()> in the <Election> class
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

class Test_addLoser {
  public:
   
    Election* setup() {
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup();
      Candidate *tempC = new Candidate(1, "test");
      temp->addLoser(tempC);
      assertm(temp->losers_.size() == 1 && temp->losers_.at(0)->getId() == 1 && temp->losers_.at(0)->getName().compare("test") == 0, "Test with vector of losers with size == 1, its candidate id = 1. name = \"test\"");
      std::cout << "Test with vector of losers with size == 1, its candidate id = 1. name = \"test\" passed." << std::endl;
    }
};

int main()
{
  Test_addLoser test;
  test.test_1();
  return 0;
}