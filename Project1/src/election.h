/* election.h
* Header file for the Election class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#ifndef ELECTION_H_
#define ELECTION_H_

#include "ballot.h"
#include "candidate.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

// for unit tests only
// #define protected public
// #define private public


/** @brief The Election class is an abstract class that provides the necessary functionality to represent 
 an election. While non-abstract child classes are required to implement their own Ballot tallying algorithms and results, the Election class provides 
 a template of necessary methods and properties that all types of elections will utilize. */
class Election {
  public:

    /** The constructor for the Election class sets the type of the election, the number of seats in the election, the vector that stores the Candidates who are running 
     in the election, and the vector that stores the Ballots cast in the election.  
     It also defaults the name of the audit file path to the empty string.
     @param type a string that indicates the election type
     @param seats an int that indicates the number of seats in the election
     @param cands a vector of Candidates who are up for election
     @param bals a vector of Ballots that were cast in the election
     @author Brendan Ritchie (ritch167)*/
    Election(std::string type, int seats, std::vector<Candidate*> cands, std::vector<Ballot*> bals);
    virtual ~Election();

    /** This method returns the type of the Election object. 
     @author Brendan Ritchie (ritch167)*/
    std::string getType();

    /** This method returns the number of the seats of the Election object. 
     @author Brendan Ritchie (ritch167)*/
    int getNumSeats();

    /** This method returns the vector of Candidate pointers in the Election object.
     @author Brendan Ritchie (ritch167)*/
    std::vector<Candidate*> getCandidates();

    /** This method returns the vector of Ballot pointers in the Election object.
     @author Brendan Ritchie (ritch167)*/
    std::vector<Ballot*> getBallots();

    /** This method returns the winners which is a vector of Candidate pointers in the Election object.
     @author Brendan Ritchie (ritch167)*/
    std::vector<Candidate*> getWinners();

    /** This method returns the losers which is a vector of Candidate pointers in the Election object.
     @author Brendan Ritchie (ritch167)*/
    std::vector<Candidate*> getLosers();

    /** This method returns the path for the audit file in the Election object.
     @author Brendan Ritchie (ritch167)*/
    std::string getAuditFilePath();

    /** This pure virtual method will be implemented in the child classes of Election and will be responsible for running 
     the speicific election type's vote tallying algorithm. */
    virtual void runAlgorithm() = 0;

    /** This pure virtual method will be implemented in the child classes of Election and will be responsible for compiling 
     the results for the specific election type */
    virtual std::string getResults() = 0;

  protected:

    std::string type_;
    int numSeats_;
    std::vector<Candidate*> candidates_;
    std::vector<Ballot*> ballots_;
    std::vector<Candidate*> winners_;
    std::vector<Candidate*> losers_;
    std::string auditFilePath_;
    std::stringstream auditText_;

    /** This method sets the auditFilePath of the Election object 
     @param name a string that the auditFilePath of the Election object will be set to 
     @author Brendan Ritchie (ritch167) */
    void setAuditFilePath(std::string name);

    /** This methods writes the content of stingstream auditText_ to audit files
     with file path as auditFilePath_.
     @author Yifan Zhang(zhan4372)*/
    void writeToAuditFile();

    /** This methods adds a candidate to winners_ vector which is a vector of Candidates.
     @author Yifan Zhang(zhan4372)*/
    void addWinner(Candidate *win);

    /** This methods adds a candidate to losers_ vector which is a vector of Candidates.
     @author Yifan Zhang(zhan4372)*/
    void addLoser(Candidate *lose);

};

#endif  // ELECTION_H_
