/* stv_election.h
* Header file for the STVElection class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#ifndef STV_ELECTION_H_
#define STV_ELECTION_H_

#include "election.h"
#include "ballot.h"
#include "candidate.h"

#include <time.h>
#include <math.h>
#include <algorithm>
#include <random>
#include <chrono>

// for unit tests only
// #define protected public
// #define private public

/** @brief The STVElection class is a child class of the abstract Election class that provides the necessary functionality to represent 
 a Single-Transferrable Vote (ranked choice) election using the Droop algorithm. On top of all of the properties of the Election class, 
 the STVElection class also has a value for the Droop quota, a value indicating whether to turn the Ballot shuffle on/off, and a vector 
 that stores the order of the shuffled Ballot objects for the election. */
class STVElection : public Election {
  public:

    /** The constructor for the STVElection class utilizes the constructor of the Election class to set the type, number of seats, the Candidates 
     in the election, and the Ballots in the election. It the sets the shuffle status of the STVElection to the value in shuffle.  
     It also calculates the Droop quota here and defaults the vector that stores the order of the shuffled Ballot objects for the election 
     to hold the ints 0 to the number of Ballotsin the election.
     @param type a string that indicates the election type
     @param seats an int that indicates the number of seats in the election
     @param cands a vector of Candidates who are up for election
     @param bals a vector of Ballots that were cast in the election
     @param shuffle a boolean that indicates whether to turn the Ballot shuffle on/off
     @author Brendan Ritchie (ritch167)*/
    STVElection(std::string type, int seats, std::vector<Candidate*> cands, std::vector<Ballot*> bals, bool shuffle);
    virtual ~STVElection();

    /** This is the primary function which is used to run the algorithm to determine winners and losers for an STV Election.
     It shuffles the ballots if necessary, initially distributes them to candidates, and then relies on the redistribute() 
     function to handle ballot redistribution from there on out. It also makes use of the writeToAuditFile() to write the 
     necessary information for election auditing to the designated text file. 
     @author Brendan Ritchie (ritch167) */
    void runAlgorithm() override;

    /** This method returns the droop quota of the STVElection object 
     @author Brendan Ritchie (ritch167) */
    int getDroop();

    /** This method returns the status of the shullfle option of the STVElection object 
     @author Brendan Ritchie (ritch167) */
    bool getShuffleStatus();

    /** This method returns the vector of shullfed index of ballots of the STVElection object 
     @author Brendan Ritchie (ritch167) */
    std::vector<int> getShuffledBallots();

    /** This method returns the result of an election with STV algorithm 
     @author Yifan Zhang (zhan4372) */
    std::string getResults() override;

  private:

    int droopQuota_;
    bool shuffle_;
    std::vector<int> shuffledBallots_;

    /** This method claculates the droop quota of an election with STV Algorithm.
     droop quota = floor((# of ballots)/(# of seats+1))+1
     @author Yifan Zhang (zhan4372)*/
    void calculateDroop();

    /** This method shuffles the index of the vector of ballots of an election.
     @author Yifan Zhang (zhan4372)*/
    void shuffleBallots();

    /** This funtion responsible for the redistribution of ballots when a Candidate is declared a loser in an STV Election. 
     It also makes use of the writeToAuditFile() to write the necessary information for election auditing to the designated text file.
     @param loser a pointer to the losing Candidate whose Ballots will be redistributed
     @param timer a time_t used in the updating of Candidate's whenGotFirstBallot_ member variable
     @author Brendan Ritchie (ritch167) */
    void redistribute(Candidate* loser, time_t timer);

    /** This method returns and removes the last loser from the losers_ vector.
     @author Yifan Zhang (zhan4372)*/
    Candidate* removeLastLoser();

    /** This method set up header for audit file
     refactored from original runAlgorithm function
     @author Brendan Ritchie (ritch167)
     @author Yifan Zhang (zhan4372)*/
    void addHeader();

    /** This method adds info for audit file after each round of distribution
     refactored from original runAlgorithm function
     @author Brendan Ritchie (ritch167)
     @author Yifan Zhang (zhan4372)*/
    void addInfo();

    /** This method adds losers for audit file after each round of distribution
     refactored from original runAlgorithm function
     @author Brendan Ritchie (ritch167)
     @author Yifan Zhang (zhan4372)*/
    void addLoserInfo();

    /** This method runs the initial distribution of all ballots
     refactored from original runAlgorithm function
     @author Brendan Ritchie (ritch167)
     @author Yifan Zhang (zhan4372)*/
    int initialDistribution(time_t timer);

};

#endif  // STV_ELECTION_H_