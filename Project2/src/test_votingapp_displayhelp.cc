/* test_votingapp_displayhelp.cc
* Unit test for displayHelp() methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class TEST_displayHelp{
    public:

        void test1(){

            VotingApp votingapp(false);
            votingapp.displayHelp();
            return;
        }

};

int main(){
    TEST_displayHelp test;
    test.test1();
    return 0;
}