/* <test_election_calculateDroop.cc>
* Unit test for <calculateDroop()> in the <STVElection> class
* Author: <Yifan Zhang (zhan4372)> **/

#include "election.h"
#include "stv_election.h"
#include "candidate.h"
#include "ballot.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_calculate_droop {
  public:
   
    STVElection* setup(int testNumber) {
      if (testNumber == 1) {
        STVElection *temp =  new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        return temp;
      }
      else if (testNumber == 2) {
        std::vector<Ballot *> tempB;
        tempB.push_back(new Ballot(0, std::vector<Candidate*>()));
        STVElection *temp =  new STVElection(std::string(), 5, std::vector<Candidate*>(), tempB, false);
        return temp;
      }
      else if (testNumber == 3) {
          std::vector<Ballot *> tempB;
          for (int i = 0; i < 100; i++)
            tempB.push_back(new Ballot(0, std::vector<Candidate*>()));
          STVElection *temp =  new STVElection(std::string(), 5, std::vector<Candidate*>(), tempB, false);
          return temp;
      }
      return new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
    }

    void test_1() {
      STVElection *temp = this->setup(1);
      temp->calculateDroop();
      assertm(temp->getDroop() == 1, "Test with standard number of seats and empty ballots");
      std::cout << "Test with standard number of seats and empty ballots passed." << std::endl;
    }

    void test_2() {
      STVElection *temp = this->setup(2);
      temp->calculateDroop();
      assertm(temp->getDroop() == 1, "Test with standaed number of seats and ballot size of 1");
      std::cout << "Test with standaed number of seats and ballot size of 1 passed." << std::endl;
    }

    void test_3() {
      STVElection *temp = this->setup(3);
      temp->calculateDroop();
      assertm(temp->getDroop() == 17, "Test with standaed number of seats and ballot size of 100");
      std::cout << "Test with standaed number of seats and ballot size of 100 passed." << std::endl;
    }
};

int main()
{
  Test_calculate_droop test;
  test.test_1();
  test.test_2();
  test.test_3();
  return 0;
}