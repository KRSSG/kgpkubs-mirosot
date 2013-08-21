#ifndef PPOSITIONOPPFREEKICK_HPP
#define PPOSITIONOPPFREEKICK_HPP

#include <utility>
#include "play.hpp"
#include "beliefState.h"
#include "tactic.h"
#define KICK_RADIUS 200
/* This play positions the bots in the position in case we Defend a Free Kick*/
namespace Strategy
{
  class PPositionOppFreeKick : public Play
  {
  public:
    inline PPositionOppFreeKick(const BeliefState& state) 
      : Play(state)
    {
      name = "OppFreeKick";

      assert(HomeTeam::SIZE == 5); 
      
      PositionPlay = PLAYTYPE_YES;
      AttackPlay   = PLAYTYPE_NO;
      
      Tactic::Param param;
			
      /*param.PositionP.align = false;
      param.PositionP.x = ForwardX(-HALF_FIELD_MAXX + GOAL_DEPTH + BOT_RADIUS*1.5);
      param.PositionP.y = 0;
      param.PositionP.finalSlope  = PI/2;
      roleList[0].push_back(std::make_pair(Tactic::Position, param));
      
			param.PositionP.align = false;
      param.PositionP.x = ForwardX(-HALF_FIELD_MAXX + GOAL_DEPTH + 4.5*BOT_RADIUS);
      param.PositionP.y = 0;
      param.PositionP.finalSlope  = PI/2;
      roleList[1].push_back(std::make_pair(Tactic::Position, param));*/
			
			/* Role 0 - Goalie */
      roleList[0].push_back(std::make_pair(Tactic::GoalieOur,param));
      
      /* Role 1 - Defender 1*/
      roleList[1].push_back(std::make_pair(Tactic::CoverGoal,param));
	  
      param.PositionP.x = state.ballPos.x;
      param.PositionP.y = SGN(-state.ballPos.y)*HALF_FIELD_MAXY/2;;
      param.PositionP.finalSlope  = 0;
      roleList[2].push_back(std::make_pair(Tactic::Position, param));
      
      param.PositionP.x = state.ballPos.x-ForwardX(FREEKICK_RADIUS);
      param.PositionP.y = state.ballPos.y;
      param.PositionP.finalSlope  = 0;
      roleList[3].push_back(std::make_pair(Tactic::Position, param));
      
      param.PositionP.x = (state.ballPos.x+ForwardX(HALF_FIELD_MAXX))/2;
      param.PositionP.y = (state.ballPos.y)/2;
      param.PositionP.finalSlope  = 0;
      roleList[4].push_back(std::make_pair(Tactic::Position, param));
      
      computeMaxTacticTransits();
    }
	
	virtual void reevaluateRoleParams()
    {
        {
            Tactic::Param &param = roleList[4][0].second;
            param.PositionP.x = (state.ballPos.x+ForwardX(HALF_FIELD_MAXX))/2;
						param.PositionP.y = (state.ballPos.y)/2;
						param.PositionP.finalSlope  = 0;
        }
        {
            Tactic::Param &param = roleList[3][0].second;
            param.PositionP.x = state.ballPos.x-ForwardX(FREEKICK_RADIUS);
						param.PositionP.y = state.ballPos.y;
						param.PositionP.finalSlope  = 0;
        }
        {
            Tactic::Param &param = roleList[2][0].second;
            param.PositionP.x = state.ballPos.x;
						param.PositionP.y = SGN(-state.ballPos.y)*HALF_FIELD_MAXY/2;;
						param.PositionP.finalSlope  = 0;
        }
        printf("reevaling params in OurFreeKick. ballPos = %d, %d\n", state.ballPos.x, state.ballPos.y);
    }

    inline ~PPositionOppFreeKick()
    { }

    inline bool applicable(void) const
    {
      if(state.pr_oppFreeKick)
        return true;
      return false;
    }

    inline Result done(void) const
    {
      // TODO make it more sophisticated and also use the timeout info to determine if the play has terminated
      // printf("Done condition not finalised\n");
      return NOT_TERMINATED;
    }
  }; // class PTestPlay
} // namespace Strategy

#endif // PPOSITIONOPPFREEKICK
