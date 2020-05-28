/* test_votingapp_displayerror.cc
* Unit test for displayError() methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class TEST_displayError{
    public:

    void test1(){
        VotingApp votingapp(false);
        votingapp.displayErrorMessage("Error");
        return;
    }

    void test2(){
        VotingApp votingapp(false);

        votingapp.displayErrorMessage("");
        return;
    }
    void test3(){
        VotingApp votingapp(false);

        votingapp.displayErrorMessage("This is an error messgae");
    }
};

int main(){
    TEST_displayError test;
    test.test1();
    test.test2();
    test.test3();
    

    return 0;
}