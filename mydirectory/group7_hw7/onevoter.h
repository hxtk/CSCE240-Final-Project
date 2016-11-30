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
   * OneVoter emulates the basics functions of a voter at the voting booth. It takes in sequence, arrival_seconds, and duration_seconds    
   * and initializes sequence_, time_arrival_seconds, 
   * time_start_voting_seconds_, time_vote_duration_seconds_ and which_station.
   * 
   * AssignStation is responsible for taking in station_number and    
   * start_time_seconds and calculating which_station, 	 
   * time_vote_duration_seconds, and time_waiting_seconds_.
   *
   * GetTOD takes time_in_seconds and returns the time of day.
   *
   * ConvertTime(takes in time_in_seconds and returns the time of day in the Hour:minute:second format. 
  **/
  void AssignStation(int station_number, int start_time_seconds);
  void DoneVoting();
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
  string ConvertTime(int time_in_seconds) const;
  string GetTOD(int time) const;
};

#endif  // ONEVOTER_H
