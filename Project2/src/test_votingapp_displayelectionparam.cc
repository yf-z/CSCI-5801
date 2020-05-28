/* test_votingapp_displayelectionparam.cc
* Unit test for displayElectionParams() methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class TEST_displayElectionParams{
    public:


        void test1(){
            VotingApp votingapp(false);
            
            votingapp.displayElectionParams(1, "STV", true);
            return;
        }
        void test2(){
            VotingApp votingapp(false);
            votingapp.displayElectionParams(2, "Plurality", false);
            return;
        }
        void test3(){
            VotingApp votingapp(false);
            votingapp.displayElectionParams(-1, "STV", true);
            return;
        }   
        void test4(){
            VotingApp votingapp(false);
            votingapp.displayElectionParams(-1, "STV", true);
            return;

        }
            

};

int main(){

    TEST_displayElectionParams test;

    test.test1();
    test.test2();
    test.test3();
    test.test4();
    
    return 0;
}

        