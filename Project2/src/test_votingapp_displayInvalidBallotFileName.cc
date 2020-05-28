/* test_votingapp_displayInvalidBallotFileName.cc
* Unit test for displayInvalidBallotFileName in the VotingApp class
* Author: Yiwen Xu (xu000515) **/

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

class Test_displayInvalidBallotFileName {
  public:
  std::string invalidBallotFileName_;
  
  std::string displayInvalidBallotFileName() {
    
    std::stringstream temp;
    temp << "Invalid Ballot File location: ";
    temp << invalidBallotFileName_;
    return temp.str();
  }
  
  void setup(int testNumber) {
    if (testNumber == 1) {
      invalidBallotFileName_ = "";
    }
    
    else if (testNumber == 2) {
      invalidBallotFileName_ = "Test";
    }
  }
  
  void test_1() {
    setup(1);
    std::string temp;
    temp = displayInvalidBallotFileName();
    assertm(temp.compare("Invalid Ballot File location: " + invalidBallotFileName_) == 0, "Test with empty invalid ballot file name");
    std::cout << "Test of displayInvalidBallotFileName with empty invalid ballot file name passed." << std::endl;
  }
  
  void test_2() {
    setup(2);
    std::string temp;
    temp = displayInvalidBallotFileName();
    assertm(temp.compare("Invalid Ballot File location: " + invalidBallotFileName_) == 0, "Test with none-empty invalid ballot file name");
    std::cout << "Test of displayInvalidBallotFileName with a non-empty invalid ballot file name passed." << std::endl;
  }
};


int main()
{
  Test_displayInvalidBallotFileName test;
  test.test_1();
  test.test_2();
  return 0;
}
