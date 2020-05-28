/* ballot.h
* Header file for the Ballot class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#ifndef BALLOT_H_
#define BALLOT_H_

#include <vector>

class Candidate;

/** @brief The Ballot class provides the necessary functionality to represent a voter's ballot in an election.
 It is able to represent ballots in both plurality and single-tranferrable vote elections. A ballot had an Id, a
 list of the Candidates in the order they were ranked on the ballot, and a variable indicating the current highest 
 ranked Candidate choice remaining on the ballot. */
class Ballot {
  public:

    /** The constructor for the Ballot class which sets the initial id of the ballot and the Candidates that were ranked on the Ballot. 
     It defaults the current choice index to 0.
     @param id an int that the Id of the Ballot object will be set to
     @param choices a vector of pointers to Candidates ranked on the Ballot object (in order) 
     @author Brendan Ritchie (ritch167)*/
    Ballot(int id, std::vector<Candidate*> choices);
    virtual ~Ballot();

    /** This method returns the Id of the Ballot object 
     @author Brendan Ritchie (ritch167)*/
    int getId();

    /** This method sets the Id of the Ballot object 
     @param id an int that the Id of the Ballot object will be set to 
     @author Brendan Ritchie (ritch167) */
    void setId(int id);

    /** This method returns the vector of pointers to Candidates ranked on the Ballot object (in order) 
     @author Brendan Ritchie (ritch167) */
    std::vector<Candidate*> getCandidates();

    /** This method returns the index of the current highest ranked Candidate choice in the vector of Candidates 
     ranked on the Ballot object 
     @author Brendan Ritchie (ritch167) */
    int getCurrentChoice();

    /** This method sets the currentChoice to the next Candidate in order
     @author Yiwen Xu (xu000515) */
    void nextChoice();

  private:

    int id_;
    std::vector<Candidate*> candidates_;
    int currentChoice_;

};

#endif  // BALLOT_H_