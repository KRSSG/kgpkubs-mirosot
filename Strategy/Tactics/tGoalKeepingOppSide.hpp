#ifndef TGOALKEEPINGOPP_HPP
#define TGOALKEEPINGOPP_HPP

#include <list>
#include "comdef.h"
#include "tactic.h"
#include "skillSet.h"
#include "beliefState.h"
#include "logger.h"
#include "config.h"
#include "geometry.hpp"
#define GOAL_Y 0
#define AWAYGOAL_X HALF_FIELD_MAXX
namespace Strategy
{
  class TGoalKeepingOppSide : public Tactic
  {
  public:
    int state1;
    TGoalKeepingOppSide(const BeliefState* state, int botID) :
      Tactic(Tactic::Stop, state, botID)
    {
      state1 = 0;
    } // TGoalKeeping

    ~TGoalKeepingOppSide()
    { } // ~TGoalKeeping
    inline bool isActiveTactic(void) const
    {
      return false;
    }

    int chooseBestBot(std::list<int>& freeBots, const Tactic::Param* tParam, int prevID) const
    {
      int minv = *(freeBots.begin());
      int mindis = 10000;
      Point2D<int> goalPos(-(HALF_FIELD_MAXX), OUR_GOAL_MAXY);
      for (std::list<int>::iterator it = freeBots.begin(); it != freeBots.end(); ++it)
      {
        float dis_from_ball = (state->homePos[*it] - goalPos).absSq();//state->home_goalpoints[2] is center of our goal
        if(dis_from_ball < mindis)
        {
          mindis = dis_from_ball;
          minv = *it;
        }
      }
      return minv;
    } // chooseBestBot

    void execute(const Param& tParam)
    {
      printf("GoalKeepOpp BotID: %d\n",botID);
      //printf("Ball Pos: %d %d\n", state->ballPos.x, state->ballPos.y);
      if (!isGoalKeeperInPosition() && state1 == 0)
      {
        //Bot elsewhere in field. Bring the bot to the Goalkeeper position.
        //Util::Logger::toStdOut("Bot going to goalkeeper positon.");
        gotoPointExact((HALF_FIELD_MAXX) - DBOX_WIDTH / 6, (OUR_GOAL_MAXY + OUR_GOAL_MINY) / 2, true, PI/2, MIN_BOT_SPEED);
      }
      else
      {
        //Bot in Goalkeeper position. Show goalkeeping skills.
        state1 = 1 ;
        gotoPointExact((HALF_FIELD_MAXX) - DBOX_WIDTH / 6, getBotDestPointY(), true, PI/2, 0);
        Util::Logger::toStdOut("Bot showing goalkeeping skills (%f,%f).\n", sParam.GoToPointP.x, sParam.GoToPointP.y);
      }
      tState = COMPLETED;

    }

    bool isGoalKeeperInPosition()
    {
      //Util::Logger::toStdOut("Half_field_max : %d, Dbox_width : %d\n",HALF_FIELD_MAXX,DBOX_WIDTH);
      if ((state->homePos[botID].x < HALF_FIELD_MAXX) &&
          (state->homePos[botID].x > HALF_FIELD_MAXX - DBOX_WIDTH) &&
          (state->homePos[botID].y >= OUR_GOAL_MINY) &&
          (state->homePos[botID].y <= OUR_GOAL_MAXY))
        return true;
      else
        return false;

    }

    int getBotDestPointY()
    {
      Vector2D<int> ballFinalpos, botDestination, point;
      ballFinalpos.x = state->ballPos.x + state->ballVel.x;
      ballFinalpos.y = state->ballPos.y + state->ballVel.y;
      botDestination.x = HALF_FIELD_MAXX - DBOX_WIDTH / 2;

      /* Workaround for ball velocity 0*/
      if(fabs(ballFinalpos.y - state->ballPos.y) < 5 || fabs(ballFinalpos.x - state->ballPos.x) < 5)
      {
        Util::Logger::toStdOut("******************Ball velocity is zero.\n");
        point.x = (HALF_FIELD_MAXX) - DBOX_WIDTH / 2;
        point.y = state->ballPos.y;
      }
      else
      {
        botDestination.y = (ballFinalpos.y - state->ballPos.y) / (ballFinalpos.x - state->ballPos.x) * (botDestination.x - ballFinalpos.x) + ballFinalpos.y;
        point.x = (HALF_FIELD_MAXX) - DBOX_WIDTH / 2;;
        point.y = botDestination.y;
        point.y = state->ballPos.y;
      }
      /* Set Limits on y to not exceed DBOX Y Limits*/
      if(point.y < OUR_GOAL_MINY)
        point.y = OUR_GOAL_MINY + BOT_RADIUS;
      else if(point.y > OUR_GOAL_MAXY)
        point.y = OUR_GOAL_MAXY - BOT_RADIUS;

      return point.y;
    }
  } ;// class TGoalKeeping
} // namespace Strategy

#endif // TGOALKEEPING_HPP
