/* <test_election_setAuditFilePath.cc>
* Unit test for <setAuditFilePath()> in the <Election> class
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

class Test_setAuditFilePath {
  public:
   
    Election* setup() {
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup();
      temp->setAuditFilePath(std::string());
      assertm(temp->auditFilePath_.empty(), "Test with empty audit file path");
      std::cout << "Test with empty audit file path passed." << std::endl;
    }

    void test_2() {
      Election *temp = this->setup();
      temp->setAuditFilePath("testPath");
      assertm(temp->auditFilePath_.compare("testPath") == 0, "Test with audit file path as \"testPath\"");
      std::cout << "Test with audit file path as \"testPath\" passed." << std::endl;
    }
};

int main()
{
  Test_setAuditFilePath test;
  test.test_1();
  test.test_2();
  return 0;
}