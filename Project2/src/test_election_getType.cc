/* <test_election_getType.cc>
* Unit test for <getType()> in the <Election> class
* Author: <Yifan Zhang (zhan4372)> **/

#include "election.h"
#include "plurality_election.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_getType {
  public:
   
    Election* setup(int testNumber) {
      if (testNumber == 1) {
        Election *temp =  new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        return temp;
      }
      else if (testNumber == 2) {
        Election *temp = new PluralityElection("test", 1, std::vector<Candidate*>(), std::vector<Ballot*>());
        return temp;
      }
      return new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
    }

    void test_1() {
      Election *temp = this->setup(1);
      assertm(temp->getType().empty(), "Test with empty string of type");
      std::cout << "Test with empty string of type passed." << std::endl;
    }

    void test_2() {
      Election *temp = this->setup(2);
      assertm(temp->getType().compare("test") == 0, "Test with type of \"test\"");
      std::cout << "Test with type of \"test\" passed." << std::endl;
    }
};

int main()
{
  Test_getType test;
  test.test_1();
  test.test_2();
  return 0;
}