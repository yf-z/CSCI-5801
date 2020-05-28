/* test_votingapp_processFiles.cc
* Unit test for processFiles methods in the VotingApp class
* Author: Sara Nelson (nels8907) **/

#include "voting_app.h"
#include "iostream"
#include <cassert>

#define assertm(exp, msg) assert (((void)msg, exp))

class test_refactor_processFiles{
    public: 

      void test1(){
          VotingApp votingapp(false);
          std::string file1 = "../testing/test_data/test1_invalid_1.csv";
          votingapp.files_.push_back(file1);
          assertm(votingapp.files_.size() == 1, "file push_back failed");
          std::cout << "File push_back passed" << std::endl;

          votingapp.processFiles("STV");


          assertm(votingapp.ballots_.size() == 0, "Test 1 with 0 ballots");

          assertm(votingapp.candidates_.size() == 10, "Test1 with 10 candidates");

          std::cout << "Test 1 passed, file contained 0 valid ballots of 10 candidates" << std::endl;

          std::string tempStr = votingapp.invalidBallotsText_.str();
          std::string count;
          int idx = tempStr.find(':');
          for (int i = idx+2; i < tempStr.size(); i++) {
            count += tempStr.at(i);
          }
          int size = stoi(count);

          assertm(size == 100, "The test with ballot file 100 invalid ballots passed");

          std::cout << "The test with ballot file 100 invalid ballots passed.\n";

          votingapp.files_.clear();
          assertm(votingapp.files_.empty(), "clear files_");

          return;
      }
      void test2(){
          VotingApp votingapp(false);
          std::string file1 = "../testing/test_data/test2_invalid_1.csv";
          votingapp.files_.push_back(file1);
          assertm(votingapp.files_.size() == 1, "file push_back failed");
          std::cout << "File push_back passed" << std::endl;

          votingapp.processFiles("STV");


          assertm(votingapp.ballots_.size() == 12, "Test 2 with 12 ballots");

          assertm(votingapp.candidates_.size() == 10, "Test 2 with 10 candidates");

          std::cout << "Test 2 passed, file contained 12 valid ballots of 10 candidates" << std::endl;

          std::string tempStr = votingapp.invalidBallotsText_.str();
          std::string count;
          int idx = tempStr.find(':');
          for (int i = idx+2; i < tempStr.size(); i++) {
            count += tempStr.at(i);
          }
          int size = stoi(count);

          assertm(size == 8, "The test with ballot file 8 invalid ballots passed");

          std::cout << "The test with ballot file 8 invalid ballots passed.\n";

          votingapp.files_.clear();
          assertm(votingapp.files_.empty(), "clear files_");

          return;
      }

      void test3(){
          VotingApp votingapp(false);
          std::string file1 = "../testing/test_data/test3_invalid_1.csv";
          votingapp.files_.push_back(file1);
          assertm(votingapp.files_.size() == 1, "file push_back failed");
          std::cout << "File push_back passed" << std::endl;

          votingapp.processFiles("STV");

          assertm(votingapp.ballots_.size() == 434, "Test 3 with 434 ballots");

          assertm(votingapp.candidates_.size() == 9, "Test 3 with 10 candidates");

          std::cout << "Test 3 passed, file contained 434 valid ballots of 10 candidates" << std::endl;

          std::string tempStr = votingapp.invalidBallotsText_.str();
          std::string count;
          int idx = tempStr.find(':');
          for (int i = idx+2; i < tempStr.size(); i++) {
            count += tempStr.at(i);
          }
          int size = stoi(count);

          assertm(size == 565, "The test with ballot file 100 invalid ballots passed");

          std::cout << "The test with ballot file 565 invalid ballots passed.\n";

          votingapp.files_.clear();
          assertm(votingapp.files_.empty(), "clear files_");

          return;
      }

      void test4(){
          VotingApp votingapp(false);
          std::string file1 = "../testing/test_data/test4_invalid_1.csv";
          votingapp.files_.push_back(file1);
          file1 = "../testing/test_data/test4_invalid_2.csv";
          votingapp.files_.push_back(file1);
          assertm(votingapp.files_.size() == 2, "file push_back failed");
          std::cout << "File push_back passed" << std::endl;

          votingapp.processFiles("STV");

          assertm(votingapp.ballots_.size() == 1150, "Test 4 with 1150 ballots");

          assertm(votingapp.candidates_.size() == 8, "Test 4 with 8 candidates");

          std::cout << "Test 4 passed, file contained 1150 valid ballots of 8 candidates" << std::endl;

          std::string tempStr = votingapp.invalidBallotsText_.str();
          std::string count;
          int idx = tempStr.find(':');
          for (int i = idx+2; i < tempStr.size(); i++) {
            count += tempStr.at(i);
          }
          int size = stoi(count);

          assertm(size == 850, "The test with ballot file 850 invalid ballots passed");

          std::cout << "The test with ballot file 850 invalid ballots passed.\n";

          votingapp.files_.clear();
          assertm(votingapp.files_.empty(), "clear files_");

          return;
      }

};


int main(){
    test_refactor_processFiles test;
    // std::cout << "point1" << std::endl;
    test.test1();
    test.test2();
    test.test3();
    test.test4();
}