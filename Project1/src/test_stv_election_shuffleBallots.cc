/* <test_election_shuffleBallots.cc>
* Unit test for <shuffleBallots()> in the <STVElection> class
* Author: <Yifan Zhang (zhan4372)> **/

#include "election.h"
#include "stv_election.h"
#include "candidate.h"
#include "ballot.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <chrono>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_shuffleBallots {
  public:
   
    bool is_not_same(std::vector<int> v1, std::vector<int>v2) {
      auto it1 = v1.begin();
      auto it2 = v2.begin();
      while (it1 != v1.end() && it1 != v2.end()) {
        if ((*it1) != (*it2)) {
          return true;
        }
        it1++;
        it2++;
      }

      if (it1 == v1.end() && it1 == v2.end()) {
        return false;
      }

      return true;
    }

    Election* setup(int testNumber) {
      if (testNumber == 1) {
        std::vector<Ballot*> tempB;
        for (int i = 0; i < 100; i++) {
          tempB.push_back(new Ballot(i, std::vector<Candidate*>()));
        }
        Election *temp = new STVElection(std::string(), 5, std::vector<Candidate*>(), tempB, false);
        return temp;
      }
      else if (testNumber == 2) {
        Election *temp = new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        return temp;
      }
      else if (testNumber == 3) {
        std::vector<Ballot*> tempB;
        for (int i = 0; i < 100000; i++) {
          tempB.push_back(new Ballot(i, std::vector<Candidate*>()));
        }
        Election *temp = new STVElection(std::string(), 5, std::vector<Candidate*>(), tempB, false);
        return temp;
      }
      Election *temp = new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
      return temp;
    }

    void test_1() {
      STVElection *temp = (STVElection*)(this->setup(1));
      temp->shuffleBallots();
      std::vector<int> v1 = temp->getShuffledBallots();
      temp->shuffleBallots();
      std::vector<int> v2 = temp->getShuffledBallots();
      assertm(is_not_same(v1, v2), "Test with shuffled ballots at different time");
      std::cout << "Test with shuffled ballots at different time passed." << std::endl;
    }

    void test_2() {
      STVElection *temp = (STVElection*)(this->setup(2));
      assertm(temp->getShuffledBallots().empty(), "Test with empty shuffled ballots");
      std::cout << "Test with empty shuffled ballots passed." << std::endl;
    }
};

int main()
{
  Test_shuffleBallots test;
  test.test_1();
  test.test_2();
  return 0;
}