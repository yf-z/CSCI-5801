#include "voting_app.h"
/* test_votingapp_askFor.cc
* Unit test for askFor methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

class askForTests{
    public:

        void ASKFORFILESTEST(){
            VotingApp votingapp(false);

            votingapp.askForFiles();

            return;
        }



        void ASKFORSEATSTEST() {
            VotingApp votingapp(false);
            int test1 = -5;
            int test2 = -5;
            int test3 = -5;
            int test4 = -5;

            test1 = votingapp.askForSeats();
            std::cout << "test 1 results: " << test1 << std::endl;

            test2 = votingapp.askForSeats();
            std::cout << "test 2 results: " << test2 << std::endl;

            test3 = votingapp.askForSeats();
            std::cout << "test 3 results: " << test3 << std::endl;

            test4 = votingapp.askForSeats();
            std::cout << "test 4 results: " << test4 << std::endl;

            return;
        }

        void ASKFORTYPETEST() {
            VotingApp votingapp(false);

            std::string test1 = "";
            std::string test2 = "";
            std::string test3 = "";
            std::string test4 = "";
            std::string test5 = "";

            //input "STV"
            test1 = votingapp.askForType();
            std::cout << "test 1 results: " << test1 << std::endl;
            //input "Plurality"
            test2 = votingapp.askForType();
            std::cout << "test 2 results: " << test2 << std::endl;
            //input "stv"
            test3 = votingapp.askForType();
            std::cout << "test 3 results: " << test3 << std::endl;
            //input "plurality"
            test4 = votingapp.askForType();
            std::cout << "test 4 results: " << test4 << std::endl;
            //input 1
            test5 = votingapp.askForType();
            std::cout << "test 5 results: " << test5 << std::endl;

            return;
        }

        void ASKFORSHUFFLETURNOFFTEST(){
            VotingApp votingapp(false);

            bool test1;
            bool test2;
            bool test3;

            //input true
            test1 = votingapp.askForShuffleTurnOff();
            //input false
            test2 = votingapp.askForShuffleTurnOff();
            //input True
            test3 = votingapp.askForShuffleTurnOff();    

            return;
        }



        void ASKFORCONFIRMATIONTEST(){
            VotingApp votingapp(false);

            bool test1;
            bool test2;
            bool test3;

            //input true
            test1 = votingapp.askForConfirmation();
            //input false
            test2 = votingapp.askForConfirmation();
            //input True
            test3 = votingapp.askForConfirmation();   

            return;
        }


 };

int main(){
    askForTests test;
    test.ASKFORFILESTEST();
    test.ASKFORSEATSTEST();
    test.ASKFORTYPETEST();
    test.ASKFORSHUFFLETURNOFFTEST();
    test.ASKFORCONFIRMATIONTEST();



    return 0;
}





