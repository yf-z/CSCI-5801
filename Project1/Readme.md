# Team 4
Sara Nelson (nels8907)
Brendan Ritchie (ritch167)
Yiwen Xu (xu000515)
Yifan Zhang (zhan4372)


## Project 1 Instructions
This project is the creation of a voting system that is capable of running both plurality voting and STV voting system using Droop quota methods. Below, you will find instructions on running the voting sytem, as well as testing the voting system. Design changes from the UML diagrams will be noted at the end.

### Running the Voting System
This voting system is written in C++ and thus has a Makefile to make and execute the program. Below are a list of files that will need to be in the same directory on your machine in order to compile. After you kick-off the build and run the program, follow the prompts on the screen for further instructions. Typing 'help' at any time before confirming you inputs will display a help window for you reference.

##### Files
- ballot.cc
- ballot.h
- candidate.cc
- candidate.h
- election.cc
- election.h
- main.cc
- Makefile
- plurality_election.cc
- plurality_election.h
- stv_election.cc
- stv_election.h
- voting_app.cc
- voting_app.h

##### Running Program

Type in these commands:
```
make
./voting_app
```

Then follow on screen prompts. Make sure .csv files that contain Ballot/Candidate information are located in same directory as the voting_app executable.

##### Running Program in Test Mode

Type in these commands:
```
make 
./voting_app -t
```

Then follow on screen prompts. Only difference is now if STV election is selected for the type, will be prompted to turn off the shuffle. Make sure .csv files that contain Ballot/Candidate information are located in same directory as the voting_app executable.


### Testing the Voting System

For automated unit testing purposes, uncomment the following lines in the .h files (if they are present):
```
#define private public
#define protected public
```


Running automated unit tests:

If the test requires a data file, be sure to pull it out of the testing/test-data/ directory and put it in the src/ directory.

Then run the following commands to run a specific function's automated unit tests:
```
make test ARGS="<name_of_unit_test_file_here_without_.cc_on_the_end>"
./unit_test
```
cleaning up after running an automated unit test:
```
make clean_test
```


### Design Changes

#### Voting_App

Methods:
```
std::vector<Candidate*> createCandidate(int id, std::string candidate); created as a helper function for processFiles()

bool doesFileExist(std::string filename); created as a helper function for processFiles()

bool is_number(const std::string& s) was created as a helper function for askForSeats()
```

Member Variables:
```
std::vector<Candidate*> candidates_; added member variable 

std::vector<Ballot*> ballots_; added member variable

std::stringstream helpMessage_; added member variable
```

Input Changes:
```
void VotingApp::processFiles() no longer takes in arguments
```

#### Ballot
Method Changes:
```
The constructor now takes in std::vector<Candidate*> 

Ballot::getCandidate() returns std::vector<Candidate*> 
```
Member Variables:
```
member variable candidates_ is now a std::vector<Candidates*>

```


#### Candidate
Method Changes:
```
Candidate::removeBallot() now returns Ballot*

Candidate::getballotsFor() is now returns std::list <Ballots*>

Candidate::addBallot() takes in Ballot*

```
Member Variables:
```
bool assigned_; was added (added getter and setter methods to accompany)

double winGotFirstballot_; was added (added getter and setter methods to accompany)

```
#### Election
Member Variable:

```
std::vector<Candidates*> candidates_

std::vector<Ballots*> ballots_

std::vector<Candidate*> winners_;
    
std::vector<Candidate*> losers_;

std::stringstream auditText_; was added

```
Other Changes:
```
constructor now takes in std::vector<Candidate*> and std::vector<Ballot*>

getCandidates() returns std::vector<Candidate*>

getLosers() returns std::vector<Candidate*>

getWinners() returns std::vector<Candidate*>

addWinner() takes in Candidate*

addLoser() takes in Candidate*

```


#### Plurality Election
Changes
```
constructor now takes in std::vector<Candidate*> and std::vector<Ballot*>
```


#### STV Election
Changes
```
constructor now takes in std::vector<Candidate*> and std::vector<Ballot*>

writeToAuditFile() was removed

removeLastLoser() now returns Candidates*

```


### References

 https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c (Checking User Input in VotingApp)

 https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c (Checking User Input in VotingApp)

 https://gist.github.com/kantoniak/d58103623d0d7a7748fbc2040810428f (Timestamping Audit Files)
