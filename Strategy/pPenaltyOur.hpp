#pragma once
#include <utility>
#include "play.hpp"
#include "kalman.h"
#include "beliefState.h"
#include "tactic.h"
#include "config.h"
using namespace std;

namespace Strategy
{
  class PPenaltyOur : public Play
  {
    public: 
    inline PPenaltyOur(const BeliefState& state) : Play(state)
    {
      name = "OurPenaltyKick";
      PositionPlay = PLAYTYPE_NO;
      AttackPlay   = PLAYTYPE_YES;
      assert(HomeTeam::SIZE ==5);
      Tactic::Param param;
      
      /* Role 0 - Shooter */
	  roleList[0].push_back(std::make_pair(Tactic::Attack,param));
	  
  /* Role 1 - Position 1*/
	 roleList[1].push_back(std::make_pair(Tactic::Stop,param));
      
 /* Role 1 - Position 2*/
      roleList[2].push_back(std::make_pair(Tactic::Stop,param));
      
 /* Role 1 - Position 3*/
      roleList[3].push_back(std::make_pair(Tactic::Stop,param));
	  
 /* Role 1 - Position 4*/
      roleList[4].push_back(std::make_pair(Tactic::Stop,param));
      
      computeMaxTacticTransits();
    }
          
    inline ~PPenaltyOur()
    {
      
    }
    inline bool applicable(void) const
    {
      
      if(state.pr_ourPenaltyKickStart)
        return true;
      return false;
    }
    inline Result done(void) const
    {

        return NOT_TERMINATED;
    }
  };
}
