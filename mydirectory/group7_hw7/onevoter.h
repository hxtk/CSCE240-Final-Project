/****************************************************************
 * Header for the 'OneVoter' class
 *
 * Author/copyright:  Duncan Buell
 * Date: 6 October 2016
 *
**/

#ifndef ONEVOTER_H
#define ONEVOTER_H

#include "../../Utilities/utils.h"

using namespace std;

static int kDummyVoterInt = -333;

class OneVoter {
 public:
  /****************************************************************
   * Constructors and destructors for the class.
  **/

  // OneVoter emulates the basics functions of a voter at the voting booth. 
  // It takes in sequence, arrival_seconds, and duration_seconds    
  // and initializes sequence_, time_arrival_seconds,time_start_voting_seconds_,
  // time_vote_duration_seconds_ and which_station.
  OneVoter();
  OneVoter(int sequence, int arrival_seconds, int duration_seconds);
  virtual ~OneVoter();

  /****************************************************************
   * Accessors and Mutators.
  **/
  int GetStationNumber() const;
  int GetTimeArrival() const;
  int GetTimeDoneVoting() const;
  int GetTimeWaiting() const;

  /****************************************************************
   * General functions.
  **/

  // AssignStation is responsible for taking in station_number and    
  // start_time_seconds and calculating which_station, 	 
  // time_vote_duration_seconds, and time_waiting_seconds_.
  void AssignStation(int station_number, int start_time_seconds);
  
  // dead code no DoneVoting function in .cc file
  void DoneVoting();
  
  // GetTimeInQ uses time_start_voting_seconds_ and time_arrival_seconds_ to
  // calculate the wait time of a voter in the line.
  int GetTimeInQ() const;

  string ToString();
  static string ToStringHeader();

 private:
  int sequence_ = kDummyVoterInt;
  int time_arrival_seconds_ = kDummyVoterInt;
  int time_done_voting_seconds_ = kDummyVoterInt;
  int time_start_voting_seconds_ = kDummyVoterInt;
  int time_vote_duration_seconds_ = kDummyVoterInt;
  int time_waiting_seconds_ = kDummyVoterInt;
  int which_station_ = kDummyVoterInt;

  /****************************************************************
   * General private functions.
  **/
  // ConvertTime(takes in time_in_seconds and returns the time of day in the hour:minute:second format
  string ConvertTime(int time_in_seconds) const;
  
  // GetTOD takes time_in_seconds and returns the time of day.
  string GetTOD(int time) const;
};

#endif  // ONEVOTER_H
