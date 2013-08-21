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
  class PPositionOurPenalty : public Play
  {
    public: 
    inline PPositionOurPenalty(const BeliefState& state) : Play(state)
    {
      name = "PositionOurPenalty";
      PositionPlay = PLAYTYPE_YES;
      AttackPlay   = PLAYTYPE_NO;
      assert(HomeTeam::SIZE ==5);
      Tactic::Param param;
      param.PositionP.align = -PI;
	  
      /* Role 0 - Shooter*/
	 param.PositionP.x = ForwardX(HALF_FIELD_MAXX - DBOX_WIDTH - BOT_RADIUS);
	 param.PositionP.y = 0;
	 param.PositionP.align = true;
	 param.PositionP.finalSlope = 0;
      
	  roleList[0].push_back(std::make_pair(Tactic::Position,param));
	  
  /* Role 1 - Position 1*/
	  param.PositionP.x =-ForwardX(BOT_RADIUS);
	  param.PositionP.y = HALF_FIELD_MAXY/4;
      roleList[1].push_back(std::make_pair(Tactic::Position,param));
      
 /* Role 1 - Position 2*/
      param.PositionP.x =-ForwardX(BOT_RADIUS);
	  param.PositionP.y = HALF_FIELD_MAXY/2;
      roleList[2].push_back(std::make_pair(Tactic::Position,param));
      
 /* Role 1 - Position 3*/
      param.PositionP.x =-ForwardX(BOT_RADIUS);
	  param.PositionP.y = -HALF_FIELD_MAXY/2;
      roleList[3].push_back(std::make_pair(Tactic::Position,param));
	  
 /* Role 1 - Position 4*/
      param.PositionP.x =-ForwardX(BOT_RADIUS);
	  param.PositionP.y = -HALF_FIELD_MAXY/4;
      roleList[4].push_back(std::make_pair(Tactic::Position,param));
      
      computeMaxTacticTransits();
    }
		
    inline ~PPositionOurPenalty()
    {
      
    }
    inline bool applicable(void) const
    {      
      if(state.pr_ourPenaltyKick)
        return true;
      return false;
    }
    inline Result done(void) const
    {

        return NOT_TERMINATED;
    }
  };
}
