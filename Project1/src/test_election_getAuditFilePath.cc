/* <test_election_getAuditFilePath.cc>
* Unit test for <getAuditFilePath()> in the <Election> class
* Author: <Yifan Zhang (zhan4372)> **/

#include "election.h"
#include "plurality_election.h"
#include "candidate.h"
#include "ballot.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_getAuditFilePath {
  public:
   
    Election* setup(int testNumber) {
      if (testNumber == 1) {
        Election *temp =  new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        return temp;
      }
      else if (testNumber == 2) {
        Election *temp = new PluralityElection("test", 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        temp->setAuditFilePath("testPath");
        return temp;
      }
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup(1);
      assertm(temp->getAuditFilePath().empty(), "Test with empty audit file path");
      std::cout << "Test with empty audit file path passed." << std::endl;
    }

    void test_2() {
      Election *temp = this->setup(2);
      assertm(temp->getAuditFilePath().compare("testPath") == 0, "Test with audit file path as \"testPath\"");
      std::cout << "Test with audit file path as \"testPath\" passed." << std::endl;
    }
};

int main()
{
  Test_getAuditFilePath test;
  test.test_1();
  test.test_2();
  return 0;
}