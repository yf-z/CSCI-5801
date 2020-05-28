/* candidate.h
* Header file for the Candidate class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#ifndef CANDIDATE_H_
#define CANDIDATE_H_

#include <string>
#include <list>

class Ballot;

/** @brief The Candidate class provides the necessary functionality to represent a candidate in an election.
 It is able to represent candidates in both plurality and single-tranferrable vote elections. A Candidate had an Id, a
 name, a forward-linked list of Ballot objects assigned to them, a int representing the count of how many Ballots are 
 assigned to them, double representing the time of when they received their first Ballot in an election (needed for STV 
 elections), and boolean indicating whether the Candidate has been declared a winner or a loser yet. */
class Candidate {
  public:
  
    /** The constructor for the Candidate class sets the initial id of the ballot and the Candidate object's name. 
     It defaults the count of its Ballot objects for to 0, when they got their first ballot to -1.0, and their winner/loser assigned 
     status to false.
     @param id an int that the Id of the Candidate object will be set to
     @param name a string that the name of the Candidate will be set to 
     @author Brendan Ritchie (ritch167)*/
    Candidate(int id, std::string name);
    virtual ~Candidate();
  
    /** This method returns the Id of the Candidate object. 
     @author Brendan Ritchie (ritch167)*/
    int getId();

    /** This method returns the name of the Candidate object. 
     @author Brendan Ritchie (ritch167)*/
    std::string getName();
  
    /** This method returns the list of pointers to Ballot objects assigned to the Candidate object.
     @author Brendan Ritchie (ritch167)*/
    std::list<Ballot *> getBallotsFor();

    /** This method is responsible for adding new Ballot to the end of the list ballotsFor of the Candidate.
     @param new_ballot a pointer to the new Ballot which will be added to the list
     @author Yiwen Xu (xu000515)*/
    void addBallot(Ballot* new_ballot);

    /** This method removes a Ballot from the front of the list ballotsFor for the Candidate and returns that Ballot.
     @author Yiwen Xu (xu000515)*/
    Ballot* removeBallot();

    /** This method returns the the count of how many Ballots objects are assigned to the Candidate objects. 
     @author Brendan Ritchie (ritch167)*/
    int getBallotsForSize();

    /** This method returns the double representing the time of when the Candidate object received their first Ballot in an election (needed for STV elections). 
     @author Brendan Ritchie (ritch167)*/
    double getWhenGotFirstBallot();

    /** This method sets the time when the Candidate object received their first Ballot in an election (needed for STV elections). 
     @param time an double representing the number of seconds since the election algorithm started processing 
     @author Brendan Ritchie (ritch167) */
    void setWhenGotFirstBallot(double time);

    /** This method returns the boolean indicating whether the Candidate object has been declared a winner or a loser yet. 
     @author Brendan Ritchie (ritch167)*/
    bool getAssignedStatus();

    /** This method sets the status indicating whether the Candidate object has been declared a winner or a loser yet. 
     @param status a boolean indicating whether the Candidate has been assigned or not
     @author Brendan Ritchie (ritch167) */
    void setAssignedStatus(bool status);

  private:

    int id_;
    std::string name_;
    std::list<Ballot *> ballotsFor_;
    int ballotsForSize_;
    double whenGotFirstBallot_;
    bool assigned_;

};

#endif  // CANDIDATE_H_
