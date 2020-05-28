/* plurality_election.h
* Header file for the PluralityElection class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#ifndef PLURALITY_ELECTION_H_
#define PLURALITY_ELECTION_H_

#include "election.h"
#include "ballot.h"
#include "candidate.h"

// for unit test only
// #define private public

/** @brief The PluralityElection class is a child class of the abstract Election class that provides the necessary functionality to represent 
 a Plurality election. */
class PluralityElection : public Election {
  public:

    /** The constructor for the PluralityElection class utilizes the constructor of the Election class to set the type, number of seats, the Candidates 
     in the election, and the Ballots in the election.
     @param type a string that indicates the election type
     @param seats an int that indicates the number of seats in the election
     @param cands a vector of Candidates who are up for election
     @param bals a vector of Ballots that were cast in the election
     @author Brendan Ritchie (ritch167)*/
    PluralityElection(std::string type, int seats, std::vector<Candidate*> cands, std::vector<Ballot*> bals);
    virtual ~PluralityElection();

    /** This method is responsible for running the election based on the plurality algorithm.
     @author Yiwen Xu (xu000515)*/
    void runAlgorithm() override;

    /** This method gets the result of running the plurality algorithm. It returns a string variable that contains the results of the plurality election, 
     as well as the Candidates and their vote percentage. Also, the string contains who won and who lost.
     @author Yiwen Xu (xu000515)*/
    std::string getResults() override;

  private:

    /** This method returns the vector of float values wihch are the percentages of the ballots that each candidate got to the total number of ballots.
     @author Yiwen Xu (xu000515)*/
    std::vector<float> calculatePercentages();
    
    /** This method sorts the vector of Candidate candidate_ based on the ballotForSize_ which is the number of ballots they got.
     @author Yiwen Xu (xu000515)*/
    void sortCandidates();

};

#endif  // PLURALITY_ELECTION_H_
