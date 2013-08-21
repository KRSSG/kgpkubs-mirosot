#ifndef PLAY_HPP
#define PLAY_HPP

#include <utility>
#include <vector>
#include <string>
#include "beliefState.h"
#include "robot.h"
#include "timer.h"
#include "logger.h"

namespace Strategy
{
  class Play
  {
    friend class PS;

  public:
    enum Result
    {
      SUCCESS_LOW,
      SUCCESS_MED,
      SUCCESS_HIGH,
      FAILURE_LOW,
      FAILURE_MED,
      FAILURE_HIGH,
      COMPLETED,
      TIMED_OUT,
      NOT_TERMINATED
    }; // enum Result
    inline bool timedOut()
    {
      //printf("Time left: %d\n", timer.split() - timeoutPeriod);
      int tm = timer.split();
      if((tm - lastRoleReassignTime) > roleReassignPeriod) {
        lastRoleReassignTime = tm;
        shouldRolesReassign  = true;
      }
      return (tm >= timeoutPeriod);
    }
    enum PlayType
    {
      PLAYTYPE_YES,
      PLAYTYPE_NO,
      PLAYTYPE_DONTCARE
    };
  private:
    // Default timeout period of any play
    static const int DEFAULT_TIMEOUT_PERIOD = 60;

    Util::Timer timer;
    int         timeoutPeriod; // in milliseconds
    int         roleReassignPeriod;
    int         lastRoleReassignTime;

    // Sets the timeout period for the play in seconds
    inline void startTimer(void)
    {
      timer.start();
      lastRoleReassignTime = 0;
    }

  protected:
    Result             result;  // Assigned when the play terminates
    const BeliefState& state;

    // Sets the timeout period of the play in seconds
    void setTimeout(int timeoutPeriod, int roleReassignPeriod = 1)
    {
      this->timeoutPeriod = (timeoutPeriod * 1000);
      this->roleReassignPeriod = roleReassignPeriod * 1000;
    }

    inline void computeMaxTacticTransits()
    {
      maxTacticsPerRole = roleList[0].size();
      for (int roleIdx = 1; roleIdx < HomeTeam::SIZE; ++roleIdx)
      {
        int sz = roleList[roleIdx].size();
        if (roleList[roleIdx].size() > maxTacticsPerRole)
        {
          maxTacticsPerRole = sz;
        }
      }
    }

  public:
    bool        shouldRolesReassign;
	virtual void reevaluateRoleParams() {} //Function to reevaluate the params for each role in every call of executePlay() in pExec
    inline Play(const BeliefState& state) :
      timeoutPeriod(Play::DEFAULT_TIMEOUT_PERIOD),
      result(NOT_TERMINATED),
      state(state),
      weight(1.0f),
      maxTacticsPerRole(0)
    {
      name = "";
      setTimeout(60);
    }

    // Name of the play
    std::string name;
    PlayType PositionPlay;
    PlayType AttackPlay;
    
    // Weight of the play - Measure of its applicability in the current scenario
    float weight;

    // roleList is a vector of pairs of Tactic ID and Tactic Parameter
    std::vector<std::pair<Tactic::ID, Tactic::Param> > roleList[HomeTeam::SIZE];
    int assignedBot[HomeTeam::SIZE];
    unsigned int maxTacticsPerRole;

    // Returns true if the play is applicable otherwise false
    virtual bool applicable(void) const {
      if((state.pr_gameRunning && this->PositionPlay == PLAYTYPE_YES)|| (!state.pr_gameRunning && this->PositionPlay == PLAYTYPE_NO)) {
        //printf("%d %d", state.gameRunning, this->PositionPlay);
        return false;
      }
      return true;
    }

    /* Returns one of SUCCESS/FAILURE/ABORTED/COMPLETED as applicable if the play terminates
     * otherwise NO_TERMINATION
     */
    virtual Result done(void) const = 0;
  }; // class Play
} // namespace Strategy

#endif // PLAY_HPP