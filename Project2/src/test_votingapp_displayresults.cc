/* test_votingapp_displayresults.cc
* Unit test for displayResults() methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/
#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class TEST_displayResults{
    public:
        void test1(){
            std::string file = "../testing/test_data/test1.csv";
            VotingApp votingapp(false);
            //std::string results;
            
            votingapp.files_.push_back(file);
            votingapp.processFiles("STV");

            votingapp.election_ = new STVElection("STV", 1 ,votingapp.candidates_,votingapp.ballots_ , false);
            assertm(!votingapp.election_->getResults().empty(), "Results is empty");

            votingapp.displayResults();
            std::cout << "Pass STV results test" << std::endl;

            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");

            return;
            }

        void test2(){ 
            std::string file = "../testing/test_data/test1.csv";
            VotingApp votingapp(false);
            
            votingapp.files_.push_back(file);
            votingapp.processFiles("Plurality");  

            votingapp.election_ = new PluralityElection("Plurality", 1, votingapp.candidates_, votingapp.ballots_);
            assertm(!votingapp.election_->getResults().empty(), "Results is empty");
            
            
            votingapp.displayResults();
            std::cout << "Pass Plurality results test" << std::endl;
            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");

            return;
        }
};

int main(){

    TEST_displayResults test;
    test.test1();
    test.test2();

    return 0;
}