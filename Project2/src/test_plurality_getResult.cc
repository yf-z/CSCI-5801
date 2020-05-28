/* test_plurality_getResult.cc
* Unit test for getResult() in the Plurality class
* Author: Yiwen Xu (xu000515) **/
#include "plurality_election.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Plurality_getResult {
  public:
  std::stringstream test;
  
    PluralityElection* setup(int testNumber) {
      if (testNumber == 1){
        this->test.str(std::string());
        this->test << "\nCandidates Id, name and their percentage: ";
        this->test << "\n\n\nWinners: ";
        this->test << "\n\n\nLosers: ";
  
        PluralityElection *temp = new PluralityElection(std::string(), 5, std::vector<Candidate*>(), std::vector<Ballot*>());
        return temp;
      }
  
      else if (testNumber == 2){
        PluralityElection *temp = new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
            temp->addLoser(new Candidate(0, "loser"));
            temp->addWinner(new Candidate(0, "winner"));
            this->test.str(std::string());
            this->test << "\nCandidates Id, name and their percentage: ";
            this->test << "\n\n\nWinners: " << "\nId: ";
            this->test << 0 << "\nName: " << "winner";
            this->test << "\n\n\nLosers: " << "\nId: ";
            this->test << 0 << "\nName: " << "loser";
        return temp;
      }
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
  }
  
  void test_1() {
    PluralityElection *temp = setup(1);
    assertm(temp->getResults().compare(this->test.str()) == 0, "Test with empty losers and winners");
    std::cout << "Test of PluralityElection sortCandidate with empty losers and winners passed." << std::endl;
  }
  
  void test_2() {
    PluralityElection *temp = setup(2);
    assertm(temp->getResults().compare(this->test.str()) == 0, "Test with 1 loser and 1 winner");
    std::cout << "Test of PluralityElection sortCandidate with 1 loser and 1 winner passed." << std::endl;
  }
};

int main()
{
  Test_Plurality_getResult test;
  test.test_1();
  test.test_2();
  return 0;
}
