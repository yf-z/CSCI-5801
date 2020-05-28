/* <test_election_getResult.cc>
* Unit test for <getResult()> in the <STVElection> class
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

class Test_stv_getResults {
  public:
    std::stringstream test;
   
    Election* setup(int testNumber) {
      if (testNumber == 1) {
        this->test.str(std::string());
        this->test << "\nWinners vector:";
        this->test << "\nLosers vector:";
        this->test << "\nWinners of Seats in order:  ";
        this->test << "\nLosers in Order: ";
        Election *temp =  new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        return temp;
      }
      else if (testNumber == 2) {
        Election *temp =  new STVElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        temp->addLoser(new Candidate(0, "loser"));
        temp->addWinner(new Candidate(0, "winner"));
        this->test.str(std::string());
        this->test << "\nWinners vector:";
        this->test << "\n1.\tId: 0\tName: winner";
        this->test << "\nLosers vector:";
        this->test << "\n1.\tId: 0\tName: loser";
        this->test << "\nWinners of Seats in order:  ";
        this->test << "\n1.\tId: 0\tName: winner";
        this->test << "\nLosers in Order: ";
        this->test << "\n1.\tId: 0\tName: loser";
        return temp;
      }
      else if (testNumber == 3) {
        Election *temp =  new STVElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        temp->addWinner(new Candidate(0, "winner"));
        this->test.str(std::string());
        this->test << "\nWinners vector:";
        this->test << "\n1.\tId: 0\tName: winner";
        this->test << "\nLosers vector:";
        this->test << "\nWinners of Seats in order:  ";
        this->test << "\n1.\tId: 0\tName: winner";
        this->test << "\nLosers in Order: ";
        return temp;
      }
      else if (testNumber == 4) {
        Election *temp =  new STVElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
        temp->addLoser(new Candidate(0, "loser"));
        this->test.str(std::string());
        this->test << "\nWinners vector:";
        this->test << "\nLosers vector:";
        this->test << "\n1.\tId: 0\tName: loser";
        this->test << "\nWinners of Seats in order:  ";
        this->test << "\n1.\tId: 0\tName: loser";
        this->test << "\nLosers in Order: ";
        return temp;
      }
      return new STVElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>(), false);
    }

    void test_1() {
      STVElection *temp = (STVElection*)(this->setup(1));
      assertm(temp->getResults().compare(this->test.str()) == 0, "Test with empty losers and winners");
      std::cout << "Test with empty losers and winners passed." << std::endl;
    }

    void test_2() {
      STVElection *temp = (STVElection*)(this->setup(2));
      assertm(temp->getResults().compare(this->test.str()) == 0, "Test with losers of size 1 and winners of size 1");
      std::cout << "Test with losers of size 1 and winners of size 1 passed." << std::endl;
    }

    void test_3() {
      STVElection *temp = (STVElection*)(this->setup(3));
      assertm(temp->getResults().compare(this->test.str()) == 0, "Test with winners of size 1 and empty losers");
      std::cout << "Test with winners of size 1 and empty losers passed." << std::endl;
    }

    void test_4() {
      STVElection *temp = (STVElection*)(this->setup(4));
      assertm(temp->getResults().compare(this->test.str()) == 0, "Test with losers of size 1, and empty winners");
      std::cout << "Test with losers of size 1, and empty winners passed." << std::endl;
    }
};

int main()
{
  Test_stv_getResults test;
  test.test_1();
  test.test_2();
  test.test_3();
  test.test_4();
  return 0;
}