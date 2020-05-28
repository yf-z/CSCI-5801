/* <test_election_writeToAuditFile.cc>
* Unit test for <writeToAuditFile()> in the <Election> class
* Author: <Yifan Zhang (zhan4372)> **/

#include "election.h"
#include "plurality_election.h"
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <vector>
#include <string>
#include <stdio.h>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

class Test_getNumSeats {
  public:

  int compareFiles(FILE *fp1, FILE *fp2) 
  { 
    // fetching character of two file 
    // in two variable ch1 and ch2 
    char ch1 = getc(fp1); 
    char ch2 = getc(fp2); 
  
    // error keeps track of number of errors 
    // pos keeps track of position of errors 
    // line keeps track of error line 
    int error = 0, pos = 0, line = 1; 
  
    // iterate loop till end of file 
    while (ch1 != EOF && ch2 != EOF) 
    { 
        pos++; 
  
        // if both variable encounters new 
        // line then line variable is incremented 
        // and pos variable is set to 0 
        if (ch1 == '\n' && ch2 == '\n') 
        { 
            line++; 
            pos = 0; 
        } 
  
        // if fetched data is not equal then 
        // error is incremented 
        if (ch1 != ch2) 
        { 
            error++; 
            printf("Line Number : %d \tError"
              " Position : %d \n", line, pos); 
            return error;
        } 
  
        // fetching character until end of file 
        ch1 = getc(fp1); 
        ch2 = getc(fp2); 
    }
  
    return error;
  }
   
    Election* setup(int testNumber) {
      Election *temp = new PluralityElection(std::string(), 1, std::vector<Candidate*>(), std::vector<Ballot*>());
      if (testNumber == 1) {
        return temp;
      }
      else {
        temp->auditText_ << "this is text";
        return temp;
      }
      return temp;
    }

    void test_1() {
      Election *temp = this->setup(1);
      temp->writeToAuditFile();
      FILE *f1 = std::fopen("../testing/test_data/test1.txt", "r");
      FILE *f2 = std::fopen(temp->auditFilePath_.c_str(), "rc");
      // std::cout << compareFiles(f1, f2) << std::endl;
      assertm(compareFiles(f1, f2) == 0, "Test with empty auditText_");
      std::cout << "Test with empty auditText_ passed." << std::endl;
    }

    void test_2() {
      Election *temp = this->setup(2);
      temp->writeToAuditFile();
      FILE *f1 = std::fopen("../testing/test_data/test2.txt", "r");
      FILE *f2 = std::fopen(temp->auditFilePath_.c_str(), "rc");
      // std::cout << compareFiles(f1, f2) << std::endl;
      assertm(compareFiles(f1, f2) == 0, "Test with auditText_ as \"this is text\"");
      std::cout << "Test with auditText_ as \"this is text\" passed." << std::endl;
    }
};

int main()
{
  Test_getNumSeats test;
  test.test_1();
  test.test_2();
  return 0;
}