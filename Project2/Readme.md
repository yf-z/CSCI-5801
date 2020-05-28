# Team 4
Sara Nelson (nels8907)
Brendan Ritchie (ritch167)
Yiwen Xu (xu000515)
Yifan Zhang (zhan4372)


## Project 2 Instructions
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

Then follow on screen prompts. When prompted to select files, please manauever to the location of your .csv files using the graphical interface. You may select more than one file by holding down the CTRL key when clicking on files in a directory.

##### Running Program in Test Mode

Type in these commands:
```
make 
./voting_app -t
```

Then follow on screen prompts. Only difference is now if STV election is selected for the type, will be prompted to turn off the shuffle.


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

#### Overall Changes

- The Zentiy file selection GUI was used for ballot file selection for the election. The following is the bash command that was used for the GUI: `zenity --file-selection --multiple --filename=. --file-filter=*.csv --separator=\",\" --title \"Select .csv Files Containing Ballots\" 2>/dev/null`

- Invalid ballot files are saved in same location as the executable for the program (/src) and are named with the following convention: `invalid_ballots<timestamp_in_seconds>.txt`

- Audit files are saved in the same location as the executable for the program (/src) and are named with the following convention: `<ElectionType>_<timestamp_in_seconds>.txt`

#### VotingApp

Methods:
```
std::vector<std::string> splitString(std::string str, char delim) was created as a helper funtion for askForFiles()

bool checkBallotValidity(std::string ballot) was created to determine if a ballot had enough candidates ranked.

void displayInvalidBallotFileName() was created to display the location of the invalid ballot file name to the screen.

removed the bool doesFileExist(const std::string filename) function as it became unnecessary with the addition of the GUI.
```

Member Variables:
```
std::string invalidBallotFileName_; added member variable

std::stringstream invalidBallotsText_; added member variable
```

Input Changes:
```
void VotingApp::processFiles(std::string type) takes in the type of election
```


#### STVElection

Methods:
```
void addHeader() was created to set up header for input files

void addInfo() was created to add info for aufit file after each round of distribution

void addLoserInfo() was created to add losers for audit file after each round of distribution

int initialDistribution(time_t timer) was created to run the initial distribution of all valid ballots
```


### References

 https://help.gnome.org/users/zenity/3.32/index.html.en#dialogs (Zenity GUI documentation)

 https://forum.juce.com/t/filechooser-multi-selection-and-zenity-platform-dialog/3747 (Implementing a Zenity GUI)

 https://stackoverflow.com/questions/45202379/how-does-popen-work-and-how-to-implement-it-into-c-code-on-linux (Implementing a Zenity GUI)

 https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/ (Splitting a comma-separated string into a vector)

 https://askubuntu.com/questions/896935/how-to-make-zenity-transient-parent-warning-disappear-permanently/896940#896940 (Hiding annoying Zenity warnings that are meaningless)
