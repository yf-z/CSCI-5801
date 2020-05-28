/* <test_election_getNumSeats.cc>
* Unit test for <getNumSeats()> in the <Election> class
* Author: <Yifan Zhang (zhan4372)> **/

#include "election.h"
#include "plurality_election.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_getNumSeats {
  public:
   
    Election* setup() {
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup();
      assertm(temp->getNumSeats() == 1, "Test with number of seats as 1");
      std::cout << "Test with number of seats as 1 passed." << std::endl;
    }
};

int main()
{
  Test_getNumSeats test;
  test.test_1();
  return 0;
}