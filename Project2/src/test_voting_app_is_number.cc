/* <test_election_is_number.cc>
* Unit test for <is_number()> in the <votingapp> class
* Author: <Yifan Zhang (zhan4372)> **/

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_is_number {
  public:

    bool is_number(const std::string& s) {
      // helper function to check if a string is a positive integer
      return !s.empty() && std::find_if(s.begin(), 
          s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
    }

    void test_1() {
      assertm(is_number("1234567891093874392847392"), "Test with standard number");
      std::cout << "Test with standard number passed." << std::endl;
    }

    void test_2() {
      assertm(!is_number("1.1"), "Test with standard number");
      std::cout << "Test with standard number passed." << std::endl;
    }

    void test_3() {
      assertm(is_number("0"), "Test with standard number");
      std::cout << "Test with standard number passed." << std::endl;
    }

    void test_4() {
      assertm(!is_number("-1"), "Test with standard number");
      std::cout << "Test with standard number passed." << std::endl;
    }

    void test_5() {
      assertm(!is_number("98098asdjlakdnwljadb"), "Test with standard number");
      std::cout << "Test with standard number passed." << std::endl;
    }
};

int main()
{
  Test_is_number test;
  test.test_1();
  test.test_2();
  test.test_3();
  test.test_4();
  test.test_5();
  return 0;
}