#ifndef TTCHARGE_HPP
#define TTCHARGE_HPP

#include <list>
#include "comdef.h"
#include "tactic.h"
#include "skillSet.h"
#include "beliefState.h"
#include "logger.h"
#include "config.h"

//TODO: Make a tactic such as tStealAndShoot which steals the ball, then shoots it, and
//      continues the stealing a few times if a goal isn't scored.

namespace Strategy
{
  class TCharge : public Tactic
  {
  public:
    TCharge(const BeliefState* state, int botID) :
      Tactic(Tactic::Stop, state, botID)
    { 
      iState =  REACH;
    } // TCharge

    ~TCharge()
    { } // ~TCharge
    enum InternalState
		{
			REACH,
			CHARGE
		}iState;
    inline bool isActiveTactic(void) const
    {
      return true;
    }

    int chooseBestBot(std::list<int>& freeBots, const Tactic::Param* tParam) const
    {
      int minv = *(freeBots.begin());
      int mindis = Vector2D<int>::dist(state->homePos[minv], state->ballPos);
      for (std::list<int>::iterator it = freeBots.begin(); it != freeBots.end(); ++it)
      {
        // TODO make the bot choosing process more sophisticated, the logic below returns the 1st available bot
        if(ForwardX(state->homePos[*it].x) < ForwardX(state->ballPos.x) && Vector2D<int>::dist(state->homePos[*it], state->ballPos) < mindis)
        {
          mindis = Vector2D<int>::dist(state->homePos[*it], state->ballPos);;
          minv = *it;
        }
      }
      return minv;
    } // chooseBestBot


    void execute(const Param& tParam)
    {
      printf("Charge BotID: %d\n",botID);

        sID = SkillSet::GoToBall;
        sParam.GoToBallP.align = true;
		skillSet->executeSkill(sID, sParam);
    
    float dist = Vector2D<int>::dist(state->ballPos, state->homePos[botID]);
    	switch(iState)
			{
        case REACH:
				{
          if(dist>BOT_BALL_THRESH+BOT_RADIUS) 
            {    
              //printf("\n BOTOBALL \n");
              sID = SkillSet::GoToPointStraight;
              sParam.GoToPointP.x = state->ballPos.x;
              sParam.GoToPointP.y = state->ballPos.y;
              sParam.GoToPointP.increaseSpeed = true;
              skillSet->executeSkill(sID, sParam);
            
            }
            else 
              iState = CHARGE;
          break;
        }
				case CHARGE : 
        {
           //printf("\n ATTACK \n");
            sID = SkillSet::GoToPoint;
            sParam.GoToPointP.align = true;
            sParam.GoToPointP.x = OPP_GOAL_X;
            sParam.GoToPointP.y = 0;
            sParam.GoToPointP.finalslope = Vector2D<int>::angle(Vector2D<int>(OPP_GOAL_X, 0), state->ballPos);
            sParam.GoToPointP.increaseSpeed = 1;
            skillSet->executeSkill(sID, sParam);
          break;
        }
      }
      if (state->pr_ourGoalScored)
        tState = COMPLETED;
      else
        tState = RUNNING;
    }
  };
// class TCharge
} // namespace Strategy

#endif // TTCharge_HPP
