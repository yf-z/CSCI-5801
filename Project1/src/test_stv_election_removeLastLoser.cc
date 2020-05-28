/* <test_election_removeLastLoser.cc>
* Unit test for <removeLastLoser()> in the <STVElection> class
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

class Test_removeLastLoser {
  public:
   
    Election* setup(int testNumber) {
      if (testNumber == 1) {
        Election *temp =  new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        return temp;
      }
      else if (testNumber == 2) {
        Election *temp =  new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        temp->addLoser(new Candidate(0, "test"));
        return temp;
      }
      else if (testNumber == 3) {
          Election *temp =  new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
          for (int i = 0; i < 100; i++)
            temp->addLoser(new Candidate(i, "test"));
          return temp;
      }
      return new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
    }

    void test_1() {
      STVElection *temp = (STVElection*)(this->setup(1));
      assertm((temp->removeLastLoser())->getId() == -1, "Test with empty losers");
      std::cout << "Test with empty losers passed." << std::endl;
    }

    void test_2() {
      STVElection *temp = (STVElection*)(this->setup(2));
      assertm((temp->removeLastLoser())->getId() == 0, "Test with losers of size 1");
      std::cout << "Test with losers of size 1 passed." << std::endl;
    }

    void test_3() {
      STVElection *temp = (STVElection*)(this->setup(3));
      assertm((temp->removeLastLoser())->getId() == 99, "Test with losers of size 100");
      std::cout << "Test with losers of size 100 passed." << std::endl;
    }
};

int main()
{
  Test_removeLastLoser test;
  test.test_1();
  test.test_2();
  test.test_3();
  return 0;
}