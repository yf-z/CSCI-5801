/* main.cc
* Implementation of the main method for the Voting Application
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "voting_app.h"

#include <string>

int main(int argc, const char *argv[]) {
  bool test_mode = false;
  if(argc > 1) {
    std::string option = argv[1];
    if(option.compare("-t") == 0) {
        test_mode = true;
    }
  }
  VotingApp app(test_mode);
  app.run();
  return 0;
}