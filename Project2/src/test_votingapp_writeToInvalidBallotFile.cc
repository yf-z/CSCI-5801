/* test_votingapp_writeToInvalidBallotFile.cc
* Unit test for writeToInvalidBallotFile() in the VotingApp class
* Author: Brendan Ritchie (ritch167) **/

#include "election.h"
#include "plurality_election.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <vector>
#include <string>
#include <stdio.h>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_writeToInvalidBallotFile {
  public:
    std::string invalidBallotFileName_;

    void writeToInvalidBallotFile(std::stringstream &invalid_text) {
      // timestamped invalid ballots file name
      invalidBallotFileName_ = "invalid_ballots" + std::to_string(std::chrono::seconds(std::time(NULL)).count()) + ".txt";
      std::ofstream invalidFile;

      // write the info to the file
      invalidFile.open(invalidBallotFileName_);
      if(!invalid_text.str().empty()) {
        invalidFile << invalid_text.str();
      }

      invalidFile.close();
    }

    bool fileNameCheck() {
      return regex_match(invalidBallotFileName_, std::regex("invalid_ballots[0-9]+\\.txt"));
    }
   
    std::stringstream setup(int testNumber) {
      std::stringstream temp;
      if (testNumber == 1) {
        return temp;
      }
      else if (testNumber == 2) {
        temp << "this is text";
        return temp;
      }
      else {
        return temp;
      }
    }

    void test_1() {
      std::stringstream temp = this->setup(1);
      this->writeToInvalidBallotFile(temp);
      assertm(fileNameCheck(), "Test 1 of writeToInvalidBallotFile() function: file name does not match expected pattern");
      std::ifstream invalids(invalidBallotFileName_);
      assertm(invalids.good(), "Test 1 of writeToInvalidBallotFile() function: file indicated does not exist");
      char fileText[2];
      invalids.read(fileText, 1);
      assertm(invalids.eof(), "Test 1 of writeToInvalidBallotFile() function: file does not contain nothing");
      std::cout << "Test 1 of writeToInvalidBallotFile() function passed." << std::endl;
    }

    void test_2() {
      std::stringstream temp = this->setup(2);
      this->writeToInvalidBallotFile(temp);
      assertm(fileNameCheck(), "Test 2 of writeToInvalidBallotFile() function: file name does not match expected pattern");
      std::ifstream invalids(invalidBallotFileName_);
      assertm(invalids.good(), "Test 2 of writeToInvalidBallotFile() function: file indicated does not exist");
      char fileText[13];
      invalids.read(fileText, 13);
      assertm(invalids.eof(), "Test 2 of writeToInvalidBallotFile() function: end of file not reached after 12 characters read");
      fileText[12] = '\0';
      std::string fileTxt(fileText);
      std::string checkStr = "this is text";
      assertm(checkStr.compare(fileTxt) == 0, "Test 2 of writeToInvalidBallotFile() function: file does not contain proper text");
      std::cout << "Test 2 of writeToInvalidBallotFile() function passed." << std::endl;
    }
};

int main()
{
  Test_writeToInvalidBallotFile test;
  test.test_1();
  test.test_2();
  return 0;
}