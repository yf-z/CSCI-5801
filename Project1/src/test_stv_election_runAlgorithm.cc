/* test_stv_election_runAlgorithm.cc
* Unit test for runAlgorithm() in the STVElection class
* Author: Brendan Ritchie (ritch167) **/

#include "stv_election.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_STVElection_runAlgorithm {
  public:
   
    STVElection* setup(int testNumber) {
      std::string type = "STV";
      int seats = 1;
      bool shuffle = false;
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

      else if(testNumber == 2) {
        // making candidates
        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);
        Candidate* cand1 = new Candidate(1, "B");
        cands.push_back(cand1);

        // making ballots
        std::vector<Candidate*> choices;

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
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

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        Ballot* bal3 = new Ballot(3, choices);
        bals.push_back(bal3);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        Ballot* bal4 = new Ballot(4, choices);
        bals.push_back(bal4);
      }

      else if(testNumber == 3) {
        seats = 2;

        // making candidates
        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);

        // making ballots
        std::vector<Candidate*> choices;

        choices.push_back(cands[0]);
        Ballot* bal0 = new Ballot(0, choices);
        bals.push_back(bal0);
        choices.clear();

        choices.push_back(cands[0]);
        Ballot* bal1 = new Ballot(1, choices);
        bals.push_back(bal1);
        choices.clear();

        choices.push_back(cands[0]);
        Ballot* bal2 = new Ballot(2, choices);
        bals.push_back(bal2);
        choices.clear();

        choices.push_back(cands[0]);
        Ballot* bal3 = new Ballot(3, choices);
        bals.push_back(bal3);
        choices.clear();

        choices.push_back(cands[0]);
        Ballot* bal4 = new Ballot(4, choices);
        bals.push_back(bal4);
      }

      else if(testNumber == 4) {
        seats = 10;

        // making candidates
        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);
        Candidate* cand1 = new Candidate(1, "B");
        cands.push_back(cand1);
        Candidate* cand2 = new Candidate(2, "C");
        cands.push_back(cand2);
        Candidate* cand3 = new Candidate(3, "D");
        cands.push_back(cand3);
        Candidate* cand4 = new Candidate(4, "E");
        cands.push_back(cand4);
        Candidate* cand5 = new Candidate(5, "F");
        cands.push_back(cand5);
        Candidate* cand6 = new Candidate(6, "G");
        cands.push_back(cand6);
        Candidate* cand7 = new Candidate(7, "H");
        cands.push_back(cand7);
        Candidate* cand8 = new Candidate(8, "I");
        cands.push_back(cand8);
        Candidate* cand9 = new Candidate(9, "J");
        cands.push_back(cand9);

        // making ballots
        std::vector<Candidate*> choices;

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal0 = new Ballot(0, choices);
        bals.push_back(bal0);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal1 = new Ballot(1, choices);
        bals.push_back(bal1);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal2 = new Ballot(2, choices);
        bals.push_back(bal2);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal3 = new Ballot(3, choices);
        bals.push_back(bal3);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal4 = new Ballot(4, choices);
        bals.push_back(bal4);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal5 = new Ballot(5, choices);
        bals.push_back(bal5);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal6 = new Ballot(6, choices);
        bals.push_back(bal6);
        choices.clear();

        choices.push_back(cands[0]);
        choices.push_back(cands[1]);
        choices.push_back(cands[2]);
        choices.push_back(cands[3]);
        choices.push_back(cands[4]);
        Ballot* bal7 = new Ballot(7, choices);
        bals.push_back(bal7);
        choices.clear();

        choices.push_back(cands[5]);
        choices.push_back(cands[6]);
        choices.push_back(cands[7]);
        choices.push_back(cands[8]);
        choices.push_back(cands[9]);
        Ballot* bal8 = new Ballot(8, choices);
        bals.push_back(bal8);
        choices.clear();

        choices.push_back(cands[6]);
        choices.push_back(cands[7]);
        choices.push_back(cands[8]);
        choices.push_back(cands[9]);
        choices.push_back(cands[0]);
        Ballot* bal9 = new Ballot(9, choices);
        bals.push_back(bal9);
        choices.clear();

        choices.push_back(cands[4]);
        choices.push_back(cands[5]);
        choices.push_back(cands[6]);
        choices.push_back(cands[7]);
        choices.push_back(cands[8]);
        Ballot* bal10 = new Ballot(10, choices);
        bals.push_back(bal10);
      }

      else if(testNumber == 5) {
        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);
        Candidate* cand1 = new Candidate(1, "B");
        cands.push_back(cand1);
        Candidate* cand2 = new Candidate(2, "C");
        cands.push_back(cand2);
        Candidate* cand3 = new Candidate(3, "D");
        cands.push_back(cand3);
        Candidate* cand4 = new Candidate(4, "E");
        cands.push_back(cand4);

        bals = createBallots(cands, 100);
      }

      else if(testNumber == 6) {
        seats = 2;

        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);
        Candidate* cand1 = new Candidate(1, "B");
        cands.push_back(cand1);
        Candidate* cand2 = new Candidate(2, "C");
        cands.push_back(cand2);
        Candidate* cand3 = new Candidate(3, "D");
        cands.push_back(cand3);
        Candidate* cand4 = new Candidate(4, "E");
        cands.push_back(cand4);

        bals = createBallots(cands, 100);
      }

      else if(testNumber == 7) {
        seats = 2;

        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);
        Candidate* cand1 = new Candidate(1, "B");
        cands.push_back(cand1);
        Candidate* cand2 = new Candidate(2, "C");
        cands.push_back(cand2);
        Candidate* cand3 = new Candidate(3, "D");
        cands.push_back(cand3);
        Candidate* cand4 = new Candidate(4, "E");
        cands.push_back(cand4);
        Candidate* cand5 = new Candidate(5, "F");
        cands.push_back(cand5);
        Candidate* cand6 = new Candidate(6, "G");
        cands.push_back(cand6);
        Candidate* cand7 = new Candidate(7, "H");
        cands.push_back(cand7);
        Candidate* cand8 = new Candidate(8, "I");
        cands.push_back(cand8);
        Candidate* cand9 = new Candidate(9, "J");
        cands.push_back(cand9);

        bals = createBallots(cands, 100);
      }

      else if(testNumber == 8) {
        seats = 5;

        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);
        Candidate* cand1 = new Candidate(1, "B");
        cands.push_back(cand1);
        Candidate* cand2 = new Candidate(2, "C");
        cands.push_back(cand2);
        Candidate* cand3 = new Candidate(3, "D");
        cands.push_back(cand3);
        Candidate* cand4 = new Candidate(4, "E");
        cands.push_back(cand4);
        Candidate* cand5 = new Candidate(5, "F");
        cands.push_back(cand5);
        Candidate* cand6 = new Candidate(6, "G");
        cands.push_back(cand6);
        Candidate* cand7 = new Candidate(7, "H");
        cands.push_back(cand7);
        Candidate* cand8 = new Candidate(8, "I");
        cands.push_back(cand8);
        Candidate* cand9 = new Candidate(9, "J");
        cands.push_back(cand9);

        bals = createBallots(cands, 100);
      }

      else if(testNumber == 9) {
        seats = 3;

        Candidate* cand0 = new Candidate(0, "A");
        cands.push_back(cand0);
        Candidate* cand1 = new Candidate(1, "B");
        cands.push_back(cand1);
        Candidate* cand2 = new Candidate(2, "C");
        cands.push_back(cand2);
        Candidate* cand3 = new Candidate(3, "D");
        cands.push_back(cand3);
        Candidate* cand4 = new Candidate(4, "E");
        cands.push_back(cand4);
        Candidate* cand5 = new Candidate(5, "F");
        cands.push_back(cand5);
        Candidate* cand6 = new Candidate(6, "G");
        cands.push_back(cand6);
        Candidate* cand7 = new Candidate(7, "H");
        cands.push_back(cand7);
        Candidate* cand8 = new Candidate(8, "I");
        cands.push_back(cand8);
        Candidate* cand9 = new Candidate(9, "J");
        cands.push_back(cand9);

        bals = createBallots(cands, 100000);
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

      STVElection* temp = new STVElection(type, seats, cands, bals, shuffle);
      return temp;
    }

    std::vector<Ballot*> createBallots(std::vector<Candidate*> cands, int total) {
      std::srand(time(NULL));
      std::vector<Ballot*> bals;
      // generate a vector of total ballots
      for(int i = 0; i < total; i++) {
        std::vector<Candidate*> choices;
        int minChoices = cands.size() / 2 + 1;
        std::vector<int> chosen;
        // number of rankings on the ballot is half to all
        int numChoices = minChoices + std::rand() % (cands.size() + 1 - minChoices);
        for(int j = 0; j < numChoices; j++) {
          // ensure random non-repeating rankings
          int k = std::rand() % cands.size();
          while(inVector(chosen, k)) {
            k = std::rand() % cands.size();
          }
          chosen.push_back(k);
          choices.push_back(cands[k]);
        }
        bals.push_back(new Ballot(i, choices));
      }
      return bals;
    }

    bool inVector(std::vector<int> nums, int num) {
      if(std::count(nums.begin(), nums.end(), num)) {
        return true;
      }
      else {
        return false;
      }
    }

    void test_1() {
      STVElection* temp = setup(1);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() == 1, "Test 1 of STVElection runAlgorithm() function: winners vector incorrect length");
      assertm(temp->getWinners()[0]->getId() == 0, "Test 1 of STVElection runAlgorithm() function: winners vector has incorrect Candidate");
      assertm(temp->getWinners()[0]->getBallotsForSize() == 1, "Test 1 of STVElection runAlgorithm() function: winning Candidate ballot total not equal to droop quota");
      std::vector<int> balIds{0};
      int idx = 0;
      std::list<Ballot*> ballotsFor = temp->getWinners()[0]->getBallotsFor();
      for(auto it = ballotsFor.cbegin(); it != ballotsFor.cend(); ++it) {
        assertm((*it)->getId() == balIds[idx], "Test 1 of STVElection runAlgorithm() function: winning Candidate ballot ids not correct");
        idx++;
      }
      assertm(temp->getLosers().empty() == true, "Test 1 of STVElection runAlgorithm() function: losers vector not empty");
      assertm(minutes < 5.0, "Test 1 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 1 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    void test_2() {
      STVElection* temp = setup(2);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() == 1, "Test 2 of STVElection runAlgorithm() function: winners vector incorrect length");
      assertm(temp->getWinners()[0]->getId() == 0, "Test 2 of STVElection runAlgorithm() function: winners vector has incorrect Candidate");
      assertm(temp->getWinners()[0]->getBallotsForSize() == 3, "Test 2 of STVElection runAlgorithm() function: winning Candidate ballot total not equal to droop quota");
      std::vector<int> balIds{0,2,3};
      int idx = 0;
      std::list<Ballot*> ballotsFor = temp->getWinners()[0]->getBallotsFor();
      for(auto it = ballotsFor.cbegin(); it != ballotsFor.cend(); it++) {
        assertm((*it)->getId() == balIds[idx], "Test 2 of STVElection runAlgorithm() function: winning Candidate ballot ids not correct");
        idx++;
      }
      assertm((int)temp->getLosers().size() == 1, "Test 2 of STVElection runAlgorithm() function: losers vector has incorrect length");
      assertm(temp->getLosers()[0]->getId() == 1, "Test 2 of STVElection runAlgorithm() function: losers vector has incorrect Candidate");
      assertm(minutes < 5.0, "Test 2 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 2 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    void test_3() {
      STVElection* temp = setup(3);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() == 1, "Test 3 of STVElection runAlgorithm() function: winners vector incorrect length");
      assertm(temp->getWinners()[0]->getId() == 0, "Test 3 of STVElection runAlgorithm() function: winners vector has incorrect Candidate");
      assertm(temp->getWinners()[0]->getBallotsForSize() == 2, "Test 3 of STVElection runAlgorithm() function: winning Candidate ballot total not equal to droop quota");
      std::vector<int> balIds{0,1};
      int idx = 0;
      std::list<Ballot*> ballotsFor = temp->getWinners()[0]->getBallotsFor();
      for(auto it = ballotsFor.cbegin(); it != ballotsFor.cend(); ++it) {
        assertm((*it)->getId() == balIds[idx], "Test 3 of STVElection runAlgorithm() function: winning Candidate ballot ids not correct");
        idx++;
      }
      assertm(temp->getLosers().empty() == true, "Test 3 of STVElection runAlgorithm() function: losers vector not empty");
      assertm(minutes < 5.0, "Test 3 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 3 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    void test_4() {
      STVElection* temp = setup(4);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() == 5, "Test 4 of STVElection runAlgorithm() function: winners vector incorrect length");
      std::vector<int> expWinIds{0,1,2,3,5};
      std::vector<int> expWinBalIds{0,1,2,3,4,5,6,7,8,10};
      int winCanIdx = 0;
      int winBalIdx = 0;
      for(int i = 0; i < (int)temp->getWinners().size(); i++) {
        assertm(temp->getWinners()[i]->getId() == expWinIds[winCanIdx], "Test 4 of STVElection runAlgorithm() function: winners vector has incorrect candidate or order");
        std::list<Ballot*> ballotsFor = temp->getWinners()[i]->getBallotsFor();
        for(auto it = ballotsFor.cbegin(); it != ballotsFor.cend(); ++it) {
          assertm((*it)->getId() == expWinBalIds[winBalIdx], "Test 4 of STVElection runAlgorithm() function: winning Candidate ballot ids not correct or wrong order");
          winBalIdx++;
        }
        winCanIdx++;
      }
      assertm((int)temp->getLosers().size() == 5, "Test 4 of STVElection runAlgorithm() function: losers vector incorrect length");
      for(int i = 0; i < 3; i++) {
        assertm(temp->getLosers()[i]->getBallotsFor().empty() == true, "Test 4 of STVElection runAlgorithm() function: loser candidate ballot vector not empty");
        assertm(temp->getLosers()[i]->getId() == 7 || temp->getLosers()[i]->getId() == 8 || temp->getLosers()[i]->getId() == 9, "Test 4 of STVElection runAlgorithm() function: losers vector has incorrect candidate or order");
      }
      assertm(temp->getLosers()[3]->getBallotsFor().empty() == true, "Test 4 of STVElection runAlgorithm() function: loser candidate ballot vector not empty");
      assertm(temp->getLosers()[3]->getId() == 4, "Test 4 of STVElection runAlgorithm() function: losers vector has incorrect candidate or order");
      assertm(temp->getLosers()[4]->getBallotsFor().empty() == true, "Test 4 of STVElection runAlgorithm() function: loser candidate ballot vector not empty");
      assertm(temp->getLosers()[4]->getId() == 6, "Test 4 of STVElection runAlgorithm() function: losers vector has incorrect candidate or order");
      assertm(minutes < 5.0, "Test 4 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 4 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    // since too big of an election to verify by hand, test 5 checks properties instead of concrete election results
    void test_5() {
      STVElection* temp = setup(5);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() <= temp->getNumSeats(), "Test 5 of STVElection runAlgorithm() function: winners vector too big.");
      assertm((int)temp->getWinners().size() + (int)temp->getLosers().size() == (int)temp->getCandidates().size(), "Test 5 of STVElection runAlgorithm() function: winners length + losers length not equal to total num Candidates.");
      int ballotTotal = 0;
      for(int i = 0; i < (int)temp->getWinners().size(); i++) {
        assertm(temp->getWinners()[i]->getBallotsForSize() == temp->getDroop(), "Test 5 of STVElection runAlgorithm() function: winner ballot count not equal to droop quota.");
        ballotTotal += temp->getWinners()[i]->getBallotsForSize();
      }
      assertm(ballotTotal <= (int)temp->getBallots().size(), "Test 5 of STVElection runAlgorithm() function: total winners' ballot counts not less than or equal to total number of ballots.");
      for(int i = 0; i < (int)temp->getLosers().size(); i++) {
        assertm(temp->getLosers()[i]->getBallotsForSize() == 0, "Test 5 of STVElection runAlgorithm() function: loser ballot count not equal to 0.");
      }
      assertm(minutes < 5.0, "Test 5 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 5 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    // since too big of an election to verify by hand, test 6 checks properties instead of concrete election results
    void test_6() {
      STVElection* temp = setup(6);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() <= temp->getNumSeats(), "Test 6 of STVElection runAlgorithm() function: winners vector too big.");
      assertm((int)temp->getWinners().size() + (int)temp->getLosers().size() == (int)temp->getCandidates().size(), "Test 6 of STVElection runAlgorithm() function: winners length + losers length not equal to total num Candidates.");
      int ballotTotal = 0;
      for(int i = 0; i < (int)temp->getWinners().size(); i++) {
        assertm(temp->getWinners()[i]->getBallotsForSize() == temp->getDroop(), "Test 6 of STVElection runAlgorithm() function: winner ballot count not equal to droop quota.");
        ballotTotal += temp->getWinners()[i]->getBallotsForSize();
      }
      assertm(ballotTotal <= (int)temp->getBallots().size(), "Test 6 of STVElection runAlgorithm() function: total winners' ballot counts not less than or equal to total number of ballots.");
      for(int i = 0; i < (int)temp->getLosers().size(); i++) {
        assertm(temp->getLosers()[i]->getBallotsForSize() == 0, "Test 6 of STVElection runAlgorithm() function: loser ballot count not equal to 0.");
      }
      assertm(minutes < 5.0, "Test 6 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 6 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    // since too big of an election to verify by hand, test 7 checks properties instead of concrete election results
    void test_7() {
      STVElection* temp = setup(7);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() <= temp->getNumSeats(), "Test 7 of STVElection runAlgorithm() function: winners vector too big.");
      assertm((int)temp->getWinners().size() + (int)temp->getLosers().size() == (int)temp->getCandidates().size(), "Test 7 of STVElection runAlgorithm() function: winners length + losers length not equal to total num Candidates.");
      int ballotTotal = 0;
      for(int i = 0; i < (int)temp->getWinners().size(); i++) {
        assertm(temp->getWinners()[i]->getBallotsForSize() == temp->getDroop(), "Test 7 of STVElection runAlgorithm() function: winner ballot count not equal to droop quota.");
        ballotTotal += temp->getWinners()[i]->getBallotsForSize();
      }
      assertm(ballotTotal <= (int)temp->getBallots().size(), "Test 7 of STVElection runAlgorithm() function: total winners' ballot counts not less than or equal to total number of ballots.");
      for(int i = 0; i < (int)temp->getLosers().size(); i++) {
        assertm(temp->getLosers()[i]->getBallotsForSize() == 0, "Test 7 of STVElection runAlgorithm() function: loser ballot count not equal to 0.");
      }
      assertm(minutes < 5.0, "Test 7 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 7 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    // since too big of an election to verify by hand, test 8 checks properties instead of concrete election results
    void test_8() {
      STVElection* temp = setup(8);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() <= temp->getNumSeats(), "Test 8 of STVElection runAlgorithm() function: winners vector too big.");
      assertm((int)temp->getWinners().size() + (int)temp->getLosers().size() == (int)temp->getCandidates().size(), "Test 8 of STVElection runAlgorithm() function: winners length + losers length not equal to total num Candidates.");
      int ballotTotal = 0;
      for(int i = 0; i < (int)temp->getWinners().size(); i++) {
        assertm(temp->getWinners()[i]->getBallotsForSize() == temp->getDroop(), "Test 8 of STVElection runAlgorithm() function: winner ballot count not equal to droop quota.");
        ballotTotal += temp->getWinners()[i]->getBallotsForSize();
      }
      assertm(ballotTotal <= (int)temp->getBallots().size(), "Test 8 of STVElection runAlgorithm() function: total winners' ballot counts not less than or equal to total number of ballots.");
      for(int i = 0; i < (int)temp->getLosers().size(); i++) {
        assertm(temp->getLosers()[i]->getBallotsForSize() == 0, "Test 8 of STVElection runAlgorithm() function: loser ballot count not equal to 0.");
      }
      assertm(minutes < 5.0, "Test 8 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 8 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

    // since too big of an election to verify by hand, test 9 checks properties instead of concrete election results
    // test 9 is also a load test, with max 10 candidates and max 100000 ballots
    void test_9() {
      STVElection* temp = setup(9);
      time_t start = time(NULL);
      temp->runAlgorithm();
      double minutes = difftime(time(NULL), start) / 60;
      assertm((int)temp->getWinners().size() <= temp->getNumSeats(), "Test 9 of STVElection runAlgorithm() function: winners vector too big.");
      assertm((int)temp->getWinners().size() + (int)temp->getLosers().size() == (int)temp->getCandidates().size(), "Test 9 of STVElection runAlgorithm() function: winners length + losers length not equal to total num Candidates.");
      int ballotTotal = 0;
      for(int i = 0; i < (int)temp->getWinners().size(); i++) {
        assertm(temp->getWinners()[i]->getBallotsForSize() == temp->getDroop(), "Test 9 of STVElection runAlgorithm() function: winner ballot count not equal to droop quota.");
        ballotTotal += temp->getWinners()[i]->getBallotsForSize();
      }
      assertm(ballotTotal <= (int)temp->getBallots().size(), "Test 9 of STVElection runAlgorithm() function: total winners' ballot counts not less than or equal to total number of ballots.");
      for(int i = 0; i < (int)temp->getLosers().size(); i++) {
        assertm(temp->getLosers()[i]->getBallotsForSize() == 0, "Test 9 of STVElection runAlgorithm() function: loser ballot count not equal to 0.");
      }
      assertm(minutes < 5.0, "Test 9 of STVElection runAlgorithm() function: algorithm took longer than 5 minutes");
      std::cout << "Test 9 of STVElection runAlgorithm() function passed." << std::endl;
      delete temp;
    }

};

int main()
{
  Test_STVElection_runAlgorithm test;
  test.test_1();
  test.test_2();
  test.test_3();
  test.test_4();
  test.test_5();
  test.test_6();
  test.test_7();
  test.test_8();
  test.test_9();
  return 0;
}