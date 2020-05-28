/* test_votingapp_doesFileExist.cc
* Unit test for doesFileExist() methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class Test_doesFileExist{
    public:

        void test1(){
            VotingApp votingapp(false);
            std::string file1 = "test1.csv";
            bool test1 = false;

            test1 = votingapp.doesFileExist(file1);

            assertm(test1, "File does exist");
            std::cout << "Test 1 passes, file does exist" << std::endl;

            return;
        }

        void test2(){
            VotingApp votingapp(false);
            std::string file2 = "2test.csv";
            bool test2 = true;

            test2 = votingapp.doesFileExist(file2);

            assertm(!test2, "File doesnt exist");
            std::cout << "Test 2 passes, file doesn't exist" << std::endl;

            return;
        }

        void test3(){
            VotingApp votingapp(false);
            std::string file3 = "";
            bool test3 = true;

            test3 = votingapp.doesFileExist(file3);

            assertm(!test3, "NULL string");
            std::cout << "Test 3 passes, empty string" << std::endl;
        }


};

int main(){
    Test_doesFileExist test;
    test.test1();
    test.test2();
    test.test3();

}