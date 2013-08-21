#ifndef TSHOOT_HPP
#define TSHOOT_HPP
#include <list>
#include "comdef.h"
#include "tactic.h"
#include "skillSet.h"
#include "beliefState.h"
#include "logger.h"
#include "config.h"
namespace Strategy
{
  class TShoot : public Tactic
  {
  public:
    TShoot(const BeliefState* state, int botID) :
      Tactic(Tactic::Stop, state, botID)
    { } // TShoot
    ~TShoot()
    { } // ~TShoot
    inline bool isActiveTactic(void) const
    {
      return true;
    }
    int chooseBestBot(std::list<int>& freeBots, const Tactic::Param* tParam) const
    {
      int minv = *(freeBots.begin());
      int mindis = 10000;
      for (std::list<int>::iterator it = freeBots.begin(); it != freeBots.end(); ++it)
      {
        // TODO make the bot choosing process more sophisticated, the logic below returns the 1st available bot
        float dis_from_ball = (state->homePos[*it] - state->ballPos).absSq();
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
      printf("Shoot BotID: %d\n",botID);
      
      float tmp_angle1, tmp_angle2, tmp_angle3;
      float angle1, angle2, finalSlope;
      tmp_angle1 = Vector2D<int>::angle(Vector2D<int>(HALF_FIELD_MAXX, OPP_GOAL_MAXY), state->ballPos);
      tmp_angle2 = Vector2D<int>::angle(getOppGoalie(), state->ballPos);
      tmp_angle3 = Vector2D<int>::angle(Vector2D<int>(HALF_FIELD_MAXX, OPP_GOAL_MINY), state->ballPos);
      angle1 = fabs(tmp_angle2 - tmp_angle1);
      angle2 = fabs(tmp_angle3 - tmp_angle2);
      if(angle1 > angle2)
        finalSlope = (tmp_angle2 + tmp_angle1) / 2;
      else
        finalSlope = (tmp_angle2 + tmp_angle3) / 2;
      Util::Logger::toStdOut("Final Angle : %f\n", finalSlope);
      float dist_from_ball = Vector2D<int>::dist(state->homePos[botID], state->ballPos);
      int finalx, finaly;
      if(dist_from_ball < BOT_BALL_THRESH)
      {
        finalx = HALF_FIELD_MAXX;
        /* The point of intersection with the goal Vertical line y = mx1 + (y2 - mx2)*/
        finaly = finalSlope * HALF_FIELD_MAXX + (state->homePos[botID].y - finalSlope * state->homePos[botID].x);
      }
      else
      {
        finalx = state->ballPos.x;
        finaly = state->ballPos.y;
      }
      gotoPointExact(finalx, finaly, true, finalSlope, 0);
    }
    Vector2D<int> getOppGoalie()
    {
      return state->awayPos[0];
    }
  }; // class TShoot
} // namespace Strategy
#endif // TSHOOT_HPP