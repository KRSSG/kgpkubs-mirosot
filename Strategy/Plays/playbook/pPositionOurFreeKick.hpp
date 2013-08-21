#ifndef PPOSITIONOURFREEKICK_HPP
#define PPOSITIONOURFREEKICK_HPP

#include <utility>
#include "play.hpp"
#include "beliefState.h"
#include "tactic.h"
#define KICK_RADIUS 200
/* This play positions the bots in the position in case its our Free Kick*/
namespace Strategy
{
  class PPositionOurFreeKick : public Play
  {
  public:
    inline PPositionOurFreeKick(const BeliefState& state) 
      : Play(state)
    {
      name = "OurFreeKick";

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
      
      param.PositionP.align = false;
      param.PositionP.x = state.ballPos.x-ForwardX(FREEKICK_RADIUS);
      param.PositionP.y = state.ballPos.y;
			Vector2D<int>Goal(ForwardX(HALF_FIELD_MAXX),0);
      param.PositionP.finalSlope  = Vector2D<int>::angle(Goal,state.ballPos);
      roleList[2].push_back(std::make_pair(Tactic::Position, param));
      
      param.PositionP.x = state.ballPos.x;
      param.PositionP.y = -state.ballPos.y;
      param.PositionP.finalSlope  = 0;
      roleList[3].push_back(std::make_pair(Tactic::Position, param));
      
      param.PositionP.x = ForwardX(HALF_FIELD_MAXX/2);
      param.PositionP.y = SGN(-state.ballPos.y)*HALF_FIELD_MAXY/2;
      param.PositionP.finalSlope  = 0;
      roleList[4].push_back(std::make_pair(Tactic::Position, param));
      
      computeMaxTacticTransits();
    }
    virtual void reevaluateRoleParams()
    {
        {
            Tactic::Param &param = roleList[4][0].second;
            param.PositionP.x = ForwardX(HALF_FIELD_MAXX/2);
						param.PositionP.y = SGN(-state.ballPos.y)*HALF_FIELD_MAXY/2;
						param.PositionP.finalSlope  = 0;
        }
        {
            Tactic::Param &param = roleList[3][0].second;
            param.PositionP.x = state.ballPos.x;
						param.PositionP.y = -state.ballPos.y;
						param.PositionP.finalSlope  = 0;
        }
        {
            Tactic::Param &param = roleList[2][0].second;
            param.PositionP.align = false;
						param.PositionP.x = state.ballPos.x-ForwardX(FREEKICK_RADIUS);
						param.PositionP.y = state.ballPos.y;
						Vector2D<int>Goal(ForwardX(HALF_FIELD_MAXX),0);
						param.PositionP.finalSlope  = Vector2D<int>::angle(Goal,state.ballPos);
        }
        //printf("reevaling params in OurFreeKick. ballPos = %d, %d\n", state.ballPos.x, state.ballPos.y);
    }
    inline ~PPositionOurFreeKick()
    { }

    inline bool applicable(void) const
    {
      if(state.pr_ourFreeKick)
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

#endif // PPOSITIONOURFREEKICK