/* test_votingapp_processFiles.cc
* Unit test for processFiles methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class Test_processFiles{
    public: 

        
        void test1(){
            VotingApp votingapp(false);
            std::string file1 = "../testing/test_data/test1.csv";
            votingapp.files_.push_back(file1);
            assertm(votingapp.files_.size() == 1, "file push_back failed");
            std::cout << "File push_back passed" << std::endl;

            votingapp.processFiles("Plurality");


            assertm(votingapp.ballots_.size() == 3, "Test1 with 3 ballots");

            assertm(votingapp.candidates_.size() == 3, "Test1 with 3 candidates");

            std::cout << "Test 1 passed, file contained 3 ballots of 3 candidates" << std::endl;

            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");

            return;
        }
        void test2(){
            VotingApp votingapp(false);
            std::string file2 = "../testing/test_data/test2.csv";
            votingapp.files_.push_back(file2);
            assertm(votingapp.files_.size() == 1, "file push_back failed");

            votingapp.processFiles("Plurality");

            assertm(votingapp.ballots_.size() == 1, "Test2 with 1 ballot");
            assertm(votingapp.candidates_.size() == 1, "Test2 with 1 candidate");
            std::cout << "Test 2 passed, 1 file with 1 ballot and 1 candidate" << std::endl;
            
            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");
            return;
        }

        void test3(){
            VotingApp votingapp(false);
            std::string file3 = "../testing/test_data/test3.csv";

            votingapp.files_.push_back(file3);

            votingapp.processFiles("Plurality");

            assertm(votingapp.ballots_.size() == 100000, "Test 3, max ballots" );
            assertm(votingapp.candidates_.size() == 10, "Test 3, max candidates");
            std::cout << "Test 3 passed, max ballot number " << std::endl;

            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");
            return;
        }

        void test4(){
            VotingApp votingapp(false);
            std::string file1 = "../testing/test_data/test1.csv";
            std::string file4 = "../testing/test_data/test4.csv";


            votingapp.files_.push_back(file1);
            votingapp.files_.push_back(file4);
            assertm(votingapp.files_.size() == 2, "file push_back failed");

            votingapp.processFiles("Plurality");

            assertm(votingapp.ballots_.size() == 8, "Test3 with 3 files, ballot size");
            assertm(votingapp.candidates_.size() == 3, "Test3 with 3 files, candidate number");

            std::cout << "Test 4 passed, 2 files" << std::endl;

            votingapp.files_.clear();
            assertm(votingapp.files_.empty(), "clear files_");
            return;
        }


        
};


int main(){
    Test_processFiles test;
    std::cout << "point1" << std::endl;
    test.test1();
    test.test2();
    test.test3();
    test.test4();
}