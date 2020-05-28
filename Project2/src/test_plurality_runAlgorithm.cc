/* test_plurality_runAlgorithm.cc
* Unit test for runAlgorithm() in the Plurality class
* Author: Yiwen Xu (xu000515) **/
#include "plurality_election.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_Pluralty_runAlgorithm {
  public:
  
    PluralityElection* setup(int testNumber) {
    std::string type = "Plurality";
    int seats = 1;
    std::vector<Candidate*> cands;
    std::vector<Ballot*> bals;

    if(testNumber == 1) {
      // making candidates
      Candidate* cand0 = new Candidate(0, "A");
      cands.push_back(cand0);

      // making ballots
      std::vector<Candidate*> choices;
      choices.push_back(cands[0]);
      Ballot* bal0 = new Ballot(0, choices);
      bals.push_back(bal0);
    }
    else if (testNumber == 2) {
      // making candidates
      Candidate* cand0 = new Candidate(0, "A");
      cands.push_back(cand0);
      Candidate* cand1 = new Candidate(1, "B");
      cands.push_back(cand1);

      // making ballots
      std::vector<Candidate*> choices;

      choices.push_back(cands[0]);
      Ballot* bal0 = new Ballot(0, choices);
      bals.push_back(bal0);
      choices.clear();

      choices.push_back(cands[1]);
      Ballot* bal1 = new Ballot(1, choices);
      bals.push_back(bal1);
      choices.clear();

      choices.push_back(cands[0]);
      Ballot* bal2 = new Ballot(2, choices);
      bals.push_back(bal2);
      choices.clear();

      choices.push_back(cands[1]);
      Ballot* bal3 = new Ballot(3, choices);
      bals.push_back(bal3);
      choices.clear();

      choices.push_back(cands[0]);
      Ballot* bal4 = new Ballot(4, choices);
      bals.push_back(bal4);
    }
    
    else if (testNumber == 3) {
      seats = 2;
      // making candidates
      Candidate* cand0 = new Candidate(0, "A");
      cands.push_back(cand0);
      Candidate* cand1 = new Candidate(1, "B");
      cands.push_back(cand1);

      // making ballots
      std::vector<Candidate*> choices;

      choices.push_back(cands[0]);
      Ballot* bal0 = new Ballot(0, choices);
      bals.push_back(bal0);
      choices.clear();

      choices.push_back(cands[1]);
      Ballot* bal1 = new Ballot(1, choices);
      bals.push_back(bal1);
      choices.clear();

      choices.push_back(cands[0]);
      Ballot* bal2 = new Ballot(2, choices);
      bals.push_back(bal2);
      choices.clear();

      choices.push_back(cands[1]);
      Ballot* bal3 = new Ballot(3, choices);
      bals.push_back(bal3);
      choices.clear();

      choices.push_back(cands[0]);
      Ballot* bal4 = new Ballot(4, choices);
      bals.push_back(bal4);
    }
    
    else if (testNumber == 4) {
      seats = 2;
      // making candidates
      Candidate* cand0 = new Candidate(0, "A");
      cands.push_back(cand0);
      Candidate* cand1 = new Candidate(1, "B");
      cands.push_back(cand1);
      Candidate* cand2 = new Candidate(2, "C");
      cands.push_back(cand2);

      // making ballots
      std::vector<Candidate*> choices;

      choices.push_back(cands[0]);
      Ballot* bal0 = new Ballot(0, choices);
      bals.push_back(bal0);
      choices.clear();

      choices.push_back(cands[2]);
      Ballot* bal1 = new Ballot(1, choices);
      bals.push_back(bal1);
      choices.clear();

      choices.push_back(cands[0]);
      Ballot* bal2 = new Ballot(2, choices);
      bals.push_back(bal2);
      choices.clear();

      choices.push_back(cands[2]);
      Ballot* bal3 = new Ballot(3, choices);
      bals.push_back(bal3);
      choices.clear();

      choices.push_back(cands[0]);
      Ballot* bal4 = new Ballot(4, choices);
      bals.push_back(bal4);
      choices.clear();
      
      choices.push_back(cands[2]);
      Ballot* bal5 = new Ballot(5, choices);
      bals.push_back(bal5);
      choices.clear();
      
      choices.push_back(cands[1]);
      Ballot* bal6 = new Ballot(6, choices);
      bals.push_back(bal6);

      choices.push_back(cands[1]);
      Ballot* bal7 = new Ballot(7, choices);
      bals.push_back(bal7);
      choices.clear();
      
      choices.push_back(cands[1]);
      Ballot* bal8 = new Ballot(8, choices);
      bals.push_back(bal8);
      choices.clear();
      
      choices.push_back(cands[1]);
      Ballot* bal9 = new Ballot(9, choices);
      bals.push_back(bal9);
      choices.clear();
      
    }
    else {
      seats = 3;

      for(int i = 0; i < 4; i++) {
        Candidate* cand0 = new Candidate(i, "test");
        cands.push_back(cand0);
      }

      for(int i = 0; i < 10; i++) {
        std::vector<Candidate*> choices;
        for(int j = 0; j < 2; j++) {
          choices.push_back(cands[j]);
        }
        Ballot* bal0 = new Ballot(i, choices);
        bals.push_back(bal0);
      }
    }
    PluralityElection* temp = new PluralityElection(type, seats, cands, bals);
    return temp;
  }
  
  void test_1() {
    PluralityElection* temp = setup(1);
    temp->runAlgorithm();
    assertm((int)temp->getWinners().size() == 1 && (int)temp->getLosers().size() == 0, "Test 1 of PluralityElection runAlgorithm() function: winners vector incorrect length");
    assertm(temp->getWinners()[0]->getId() == 0, "Test 1 of PluralityElection runAlgorithm() function: winners vector has incorrect Candidate");
    std::cout << "Test 1 of PluralityElection runAlgorithm() function passed." << std::endl;
  }
  
  void test_2() {
    PluralityElection* temp = setup(2);
    temp->runAlgorithm();
    assertm((int)temp->getWinners().size() == 1 && (int)temp->getLosers().size() == 1, "Test 2 of PluralityElection runAlgorithm() function: winners vector incorrect length");
    assertm(temp->getWinners()[0]->getId() == 0 && temp->getLosers()[0]->getId() == 1, "Test 2 of PluralityElection runAlgorithm() function: winners vector has incorrect Candidate");
    std::cout << "Test 2 of PluralityElection runAlgorithm() function passed." << std::endl;
  }
  
  void test_3() {
    PluralityElection* temp = setup(3);
    temp->runAlgorithm();
    assertm((int)temp->getWinners().size() == 2 && (int)temp->getLosers().size() == 0, "Test 3 of PluralityElection runAlgorithm() function: winners vector incorrect length");
    assertm(temp->getWinners()[0]->getId() == 0 && temp->getWinners()[1]->getId() == 1, "Test 3 of PluralityElection runAlgorithm() function: winners vector has incorrect Candidate");
    std::cout << "Test 3 of PluralityElection runAlgorithm() function passed." << std::endl;
  }
  
  void test_4() {
    PluralityElection* temp = setup(4);
    temp->runAlgorithm();
    assertm((int)temp->getWinners().size() == 2 && (int)temp->getLosers().size() == 1, "Test 4 (tie situation) of PluralityElection runAlgorithm() function: winners vector incorrect length");
    assertm((temp->getWinners()[0]->getId() == 1 && temp->getWinners()[1]->getId() == 2) || (temp->getWinners()[0]->getId() == 1 && temp->getWinners()[1]->getId() == 0), "Test 4 (tie situation) of PluralityElection runAlgorithm() function: winners vector has incorrect Candidate");
    std::cout << "Test 4 (tie situation) of PluralityElection runAlgorithm() function passed." << std::endl;
  }
};

int main()
{
  Test_Pluralty_runAlgorithm test;
  test.test_1();
  test.test_2();
  test.test_3();
  test.test_4();
}
