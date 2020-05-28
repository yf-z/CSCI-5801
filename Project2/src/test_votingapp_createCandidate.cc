/* test_votingapp_createCandidate.cc
* Unit test for createCandidate methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>


#define assertm(exp, msg) assert (((void)msg, exp))

class Test_createCandidate{
    public:

    void test1(){
        VotingApp votingapp(false);
        std::string candidates = "Mary";
        std::vector <Candidate*> vCand;
        std::string name;

        int i = 1;

        vCand = votingapp.createCandidate(i, candidates);

        assertm(vCand.size() == 1, "Failed input string of 1 name");
        assertm(vCand[0]->getName() == "Mary", "Failed string name");
        std::cout << "Passed input string of 1 name" << std::endl;
        return;
    }

    void test2(){
        VotingApp votingapp(false);
        std::string candidates = "Mary,John";
        std::vector <Candidate*> vCand;
        int i = 1;

        vCand = votingapp.createCandidate(i, candidates);

        assertm(vCand.size() == 2, "Failed input string of 1 name");
        assertm(vCand[0]->getName() == "Mary", "Failed string name vCand[0]");
        assertm(vCand[1]->getName() == "John", "Failed string name vCand[1]");
        std::cout << "Passed input string of 2 name" << std::endl;

        return;
    }

    void test3(){
        VotingApp votingapp(false);
        std::string candidates = "Mary,John,Susan,Karen,Cathy,Debbie,Collin,Dugg,Jack,Pat";
        std::vector <Candidate*> vCand;
        int i = 1;

        vCand = votingapp.createCandidate(i, candidates);

        assertm(vCand.size() == 10, "Failed input string of 10 name");
        assertm(vCand[0]->getName() == "Mary", "Failed string name vCand[0]");
        assertm(vCand[1]->getName() == "John", "Failed string name vCand[1]");
        assertm(vCand[2]->getName() == "Susan", "Failed string name vCand[2]");
        assertm(vCand[3]->getName() == "Karen", "Failed string name vCand[3]");
        assertm(vCand[4]->getName() == "Cathy", "Failed string name vCand[4]");
        assertm(vCand[5]->getName() == "Debbie", "Failed string name vCand[5]");
        assertm(vCand[6]->getName() == "Collin", "Failed string name vCand[6]");
        assertm(vCand[7]->getName() == "Dugg", "Failed string name vCand[7]");
        assertm(vCand[8]->getName() == "Jack", "Failed string name vCand[8]");
        assertm(vCand[9]->getName() == "Pat", "Failed string name vCand[9]");
        std::cout << "Passed input string of 10 name" << std::endl;

        return;

    }


};


int main(){
    Test_createCandidate test;
    test.test1();
    test.test2();
    test.test3();
}