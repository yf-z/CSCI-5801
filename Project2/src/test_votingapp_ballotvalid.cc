#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))


class testBallotValididty{
    public:

        //valid file even candidates
        void test1(){
            VotingApp votingapp(false);
            std::string votes = "1,2,3,4";
            bool returnval = false;

            //create candidates for testing
            votingapp.candidates_=votingapp.createCandidate (1, "John,Adam,Suzie,Susan");

            returnval = votingapp.checkBallotValidity(votes);

            assertm(returnval == true, "valid file with even candidates" );
            std::cout << "test 1 passed valid votes with even candidates"<< std::endl;
            


        }
        //valid file odd candidates
        void test2(){
            VotingApp votingapp(false);
            std::string votes = "1,,2";
            bool returnval = false;

            //create candidates for testing
            votingapp.candidates_=votingapp.createCandidate (1, "John,Adam,Suzie");

            returnval = votingapp.checkBallotValidity(votes);

            assertm(returnval == true, "valid file with odd candidates" );
            std::cout << "test 2 passed valid votes with odd candidates"<< std::endl;



        }

        //invalid file even candidates
        void test3(){
            VotingApp votingapp(false);
            std::string votes = "1,,,";
            bool returnval = true;

            //create candidates for testing
            votingapp.candidates_=votingapp.createCandidate (1, "John,Adam,Suzie,Susan");

            returnval = votingapp.checkBallotValidity(votes);

            assertm(returnval == false, "invalid file with even candidates" );
            std::cout << "test 3 passed invalid votes with even candidates"<< std::endl;


        }

        //invalid file odd candidates
        void test4(){
            VotingApp votingapp(false);
            std::string votes = "1,,,";
            bool returnval = true;

            //create candidates for testing
            votingapp.candidates_=votingapp.createCandidate (1, "John,Adam,Suzie");

            returnval = votingapp.checkBallotValidity(votes);

            assertm(returnval == false, "invalid file with odd candidates" );
            std::cout << "test 4 passed invalid votes with odd candidates"<< std::endl;

        }

};

int main(){
    testBallotValididty test;
    test.test1();
    test.test2();
    test.test3();
    test.test4();



}