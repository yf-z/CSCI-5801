/* voting_app.h
* Header file for the VotingApp class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#ifndef VOTING_APP_H_
#define VOTING_APP_H_

#include "election.h"
#include "ballot.h"
#include "candidate.h"
#include "stv_election.h"
#include "plurality_election.h"


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <exception>
#include <unistd.h>



// for unit test only
//  #define private public
//  #define protected public


/** @brief The VotingApp class provides the necessary functionality to run the user interface for the application.
 It handles all interactions with the user in the interface and initiates the process of running an election after 
 being given all the necessary information by the user. It also provides the necessary functionality to run in a test 
 mode for debugging purposes. */
class VotingApp {
  public:

    /** The constructor for the VotingApp class sets test mode status of the object. 
     It defaults the Election member variable to NULL.
     @param test_mode a boolean that indicates whether the application is running in test mode or not
     @author Brendan Ritchie (ritch167)*/
    VotingApp(bool test_mode);
    virtual ~VotingApp();

    /** This is the run method for the voting system. No inputs and returns nothing.
     @author Sara Nelson (nels8907) */ 
    void run();

  private:    

    Election *election_;
    bool test_;
    std::vector<std::string> files_;
    std::vector<Candidate*> candidates_;
    std::vector<Ballot*> ballots_;
    std::stringstream helpMessage_;
    std::stringstream invalidBallotsText_;
    std::string invalidBallotFileName_;

    /** This is the method that will ask the user for the file names. It will return a vector of file names
     that private attribute files will be set to.
    @author Sara Nelson */ 
    std::vector<std::string> askForFiles();

    /** This method asks for the number of seats available for this election and returns an int.
     @author Sara Nelson (nels8907) */
    int askForSeats();

    /** This method asks the user for the type of algorithm they want to run and returns a string 
     that describes the algorithm
     @author Sara Nelson (nels8907) */ 
    std::string askForType();

    /** This method asks the user if the shuffle should be on or off. This will only be asked if in test_mode.
     A bool will be returned.
     @author Sara Nelson (nelso8907) */ 
    bool askForShuffleTurnOff();

    /** This method will print out the election parameters for the user to see.
     @param seats an int that describes the number of seats in the election
     @param type a string that describes the type of elction that will be run
     @param shuffle a bool that describes whether on not the shuffle will be on.
     @author Sara Nelson (nels8907) */ 
    void displayElectionParams(int seats, std::string type, bool shuffle);

    /** This method will ask the user to confirm their input parameters and return a bool
     @author Sara Nelson (nels8907) */ 
    bool askForConfirmation();

    /** This method will display the invalid ballot file location for election officials. There will be no return.
    @author Yiwen Xu (xu000515)*/
    void displayInvalidBallotFileName();

    /** This method will write the invalid ballot information to a txt file.
     @param invalid_text a std::stringsteam that contains the text for the invalid ballot file.
     @author Brendan Ritchie (ritch167) */
    void writeToInvalidBallotFile(std::stringstream &invalid_text);
    
    /** This method will read all the files and create the ballots and candidates for the election.
     Refactored to invalidate ballots with less than at least of half candidates.
     @param type a std::string that contains the type of the current election
     @author Sara Nelson (nels8907) 
     @author Yifan Zhang (zhan4372) */ 
    void processFiles(std::string type);

    /** This method will create the object Candidate and return a vector of Candidate objects.
     @param id an int that describes a unique candidate
     @param candidate a string that describes the candidate name
     @author Sara Nelson (nels8907) */ 
    std::vector<Candidate*> createCandidate(int id, std::string candidate);

    /** This method will display the help window for the user
    @author Sara Nelson (nes8907) */ 
    void displayHelp();

    /** This method will display the any error message and return nothing.
    @param message a string that describes the error
    @author Sara Nelson (nels8907) */ 
    void displayErrorMessage(std::string message);

    /** This method will display the results that have been created from the election_. This method will not 
     return anything.
    @author Sara Nelson (nels8907) */ 
    void displayResults();

    /** This method will display the audit file location for election officials. There will be no return.
     @author Sara Nelson (nels8907)*/ 
    void displayAuditLocation();

    /** This method will return a 'true' if the ballot has more than half the candidates ranked and a 'false'
     if not.
     @param ballot is a string of ballot votes 
     @author Sara Nelson (nels8907)*/
    bool checkBallotValidity(std::string ballot);

    /** This method will split the file name string into a vector of strings with each name, it will
    return a vector of strings.
    @param str is a string of file names that are comma delimited.
    @param delim is the char delimitator of the file names.
    @author Brendan Ritchie (ritch167)*/
    std::vector<std::string> splitString(std::string str, char delim);



};

#endif  // VOTING_APP_H_