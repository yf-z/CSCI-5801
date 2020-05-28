/* test_plurality_calculatePercentage.cc
* Unit test for calculatePercentage() in the Plurality class
* Author: Yiwen Xu (xu000515) **/
#include "plurality_election.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Plurality_calculatePercentage {
  public:
    
    PluralityElection* setup(int testNumber) {
      if (testNumber == 1){
        std::string type = "Plurality";
        int seats = 3;
        std::vector<Candidate*> cands;
        std::vector<Ballot*> bals;
        for(int i = 0; i < 4; i++) {
          cands.push_back(new Candidate(i, (std::stringstream() << "test" << i).str()));
        }
        for(int i = 0; i < 10; i++){
          std::vector<Candidate*> choices;
          if(i <= 1)
            choices.push_back(cands[0]);
          else if (i <= 4)
            choices.push_back(cands[1]);
          else
            choices.push_back(cands[2]);
          bals.push_back(new Ballot(i, choices));
        }
        
        PluralityElection* temp = new PluralityElection(type, seats, cands, bals);
        return temp;
      }
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
  }
  
  void test_1() {
    PluralityElection* temp = setup(1);
    for (int j = 0; j < (int)(temp->getCandidates().size()); j++) {
      int id = temp->getCandidates().at(j)->getId();
      for (int k = 0; k < (int)(temp->getBallots().size()); k++){
        std::vector<Candidate*> c = temp->getBallots().at(k)->getCandidates();
        // the ballot belongs to the candidate
        if(c[0]->getId() == id) {
          temp->getCandidates().at(j)->addBallot(temp->getBallots().at(k));
        }
      }
    }
    
    std::vector<float> p = temp->calculatePercentages();
    
    float a0 = (float)2/10;
    float a1 = (float)3/10;
    float a2 = (float)5/10;
    float a3 = (float)0;
    float arr[4] = {a0, a1, a2, a3};
    std::vector<float> x(arr, arr+4);
    
    for(int i = 0; i < temp->getCandidates().size(); i++){
      assertm(p.at(i) == x.at(i), "Test of PluralityElection sortCandidate: incorrect value returned.");
    }
    std::cout << "Test of PluralityElection sortCandidate passed." << std::endl;
  }
};

int main()
{
  Test_Plurality_calculatePercentage test;
  test.test_1();
  return 0;
}
