#ifndef TTPASS_HPP
#define TTPASS_HPP

#include <list>
#include "comdef.h"
#include "tactic.h"
#include "skillSet.h"
#include "beliefState.h"
#include "logger.h"
#include "config.h"
#define D_TPASS 1
namespace Strategy
{
  class TPass : public Tactic
  {
  public:
    TPass(const BeliefState* state, int botID) :
      Tactic(Tactic::Stop, state, botID)
    {} // TPass

    ~TPass()
    { } // ~TPass

    inline bool isActiveTactic(void) const
    {
      return true;
    }

    int chooseBestBot(std::list<int>& freeBots, const Tactic::Param* tParam) const
    {
			/*Arpit: tactic explicitly for Kickoff. chooses the farthest bot on the other side of the field. */
      int maxv = *(freeBots.begin());
      int maxdis = 0;
      for (std::list<int>::iterator it = freeBots.begin(); it != freeBots.end(); ++it)
      {        
        float dist = ForwardX(state->homePos[*it].x);
        if(dist > maxdis)
        {
          maxdis= dist;
          maxv = *it;
        }
      }
      debug(1, maxv, "assigned Pass");
      return maxv;
    } // chooseBestBot
    void execute(const Param& tParam)
    {
      printf("Pass BotID: %d\n",botID);
      //tState = RUNNING;
			if(ForwardX(state->ballPos.x) < -250)
				tState = Tactic::COMPLETED;
      gotoPointExact(state->ballPos.x, state->ballPos.y, false, 0, MAX_BOT_SPEED);
    }
  };// class TPass
} // namespace Strategy

#endif // TTPass_HPP
