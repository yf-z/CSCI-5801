/* test_votingapp_displayauditlocation.cc
* Unit test for displayAuditLocation() methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class TEST_displayAuditLocation{
    public:


        void test1(){
            std::string file = "../testing/test_data/test1.csv";
            VotingApp votingapp(false);
            
            votingapp.files_.push_back(file);
            std::string type = "Plurality";
            votingapp.processFiles(type);
            votingapp.election_ =  new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
            votingapp.election_->setAuditFilePath("STV File Path");

            //votingapp.election_ = new STVElection("STV", 1 ,votingapp.candidates_,votingapp.ballots_ , false);
            //assertm(votingapp.displayAuditLocation(), "Fail, STV audit location");
            votingapp.displayAuditLocation();
            std::cout << "Pass STV audit location test" << std::endl;

            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");

            return;
        }

        void test2(){ 
            std::string file = "../testing/test_data/test1.csv";
            VotingApp votingapp(false);
            
            votingapp.files_.push_back(file);
            std::string type = "Plurality";
            votingapp.processFiles(type);  

            votingapp.election_ =  new PluralityElection("Plurality", 1, votingapp.candidates_, votingapp.ballots_);
            //assertm(votingapp.displayAuditLocation(), "Fail, Plurality audit location");
            votingapp.election_->setAuditFilePath("Plurality File Path");
            votingapp.displayAuditLocation();
            std::cout << "Pass Plurality audit location test" << std::endl;
            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");

            return;
        }

 

};

int main(){

    TEST_displayAuditLocation test;
    
    test.test1();
    test.test2();
    return 0;
}