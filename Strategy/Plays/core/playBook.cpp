// DO NOT EDIT: This file is auto-generated

#include <cstdlib>
#include "playBook.h"
#include "play.hpp"
#include "pNone.hpp"
#include "pTestPlay.hpp"
//#include "pOffensePlay.hpp"
#include "pSetPosition.hpp"
//#include "pDefenceSetPos1.hpp"
#include "pPositionOppKickoff.hpp"
//#include "pOffenceSetPos1.hpp"
//#include "pDefensiveGoToGoal.hpp"
//#include "pDefensiveSteal.hpp"
#include "pOurGoalKick.hpp"
#include "pOppGoalKick.hpp"
#include "pStop.hpp"
#include "pPositionOurFreeKick.hpp"
#include "pPositionOppFreeKick.hpp"
//#include "pTieBreakerOurPenalty.hpp"
//#include "pTieBreakerOppPenalty.hpp"
#include "pPenaltyOur.hpp"
#include "pPenaltyOpp.hpp"

#include "pSuperOffense.hpp"
#include "pOffense1.hpp"
#include "pOffense2.hpp"
#include "pSuperDefense.hpp"
#include "pDefense1.hpp"
#include "pDefense2.hpp"
#include "pPositionOurKickoff.hpp"
#include "pKickoff.hpp"
#include "pPositionOurPenalty.hpp"
//#include "pOnePassGoal.hpp"
//#include "pPassAndWait.hpp"
namespace Strategy
{
  PlayBook::PlayBook(const BeliefState* state) : 
    state(state)
  {
    reload();
  } // PlayBook

  PlayBook::~PlayBook()
  { } // ~PlayBook

  void PlayBook::reload(void)
  {
    // Initializing all play objects with NULL
    for (int pID=0; pID<PlayBook::MAX_PLAYS; ++pID)
    {
      playList[pID] = NULL;
    }

    // Inserting all the name-object pairs into the  Play List
    playList[PlayBook::None]                  = new PNone(*state);
    playList[PlayBook::TestPlay]              = new PTestPlay(*state);
    playList[PlayBook::SetPosition]           = new PSetPosition(*state);
    //playList[PlayBook::OffenceSetPosition1]   = new POffenceSetPosition1(*state);
    //playList[PlayBook::OffensePlay]           = new POffensePlay(*state); 
    //playList[PlayBook::DefenceSetPosition1]   = new PDefenceSetPosition1(*state);    
    playList[PlayBook::Stop]                  = new PStop(*state);
    //playList[PlayBook::DefensiveGoToGoal]     = new PDefensiveGoToGoal(*state);
    //playList[PlayBook::DefensiveSteal]        = new PDefensiveSteal(*state);
    playList[PlayBook::OurGoalKick]           = new POurGoalKick(*state);
    playList[PlayBook::OppGoalKick]           = new POppGoalKick(*state);
    playList[PlayBook::OurFreeKick]           = new PPositionOurFreeKick(*state);
    playList[PlayBook::OppFreeKick]           = new PPositionOppFreeKick(*state);
    //playList[PlayBook::TieBreakerOurPenalty]  = new PTieBreakerOurPenalty(*state);
    //playList[PlayBook::TieBreakerOppPenalty]  = new PTieBreakerOppPenalty(*state);
    playList[PlayBook::PenaltyOur]						=	new PPenaltyOur(*state);
		playList[PlayBook::PenaltyOpp]						=	new PPenaltyOpp(*state);
    playList[PlayBook::SuperOffense]          = new PSuperOffensePlay(*state);
    playList[PlayBook::Offense1]              = new POffense1Play(*state);
    playList[PlayBook::Offense2]              = new POffense2Play(*state);
    playList[PlayBook::SuperDefense]          = new PSuperDefensePlay(*state);
    playList[PlayBook::Defense1]              = new PDefense1Play(*state);
    playList[PlayBook::Defense2]              = new PDefense2Play(*state);
		playList[PlayBook::PositionOurKickoff]    = new PPositionOurKickoff(*state);
		playList[PlayBook::PositionOppKickoff]    = new PPositionOppKickoff(*state);
		playList[PlayBook::Kickoff]               = new PKickoff(*state);
		playList[PlayBook::PositionOurPenalty]    = new PPositionOurPenalty(*state);
    //playList[PlayBook::OnePassGoal]           = new POnePassGoal(*state);
    //playList[PlayBook::PassAndWait]           = new PPassAndWait(*state);
    
    // Checking if all the play ids have been associated with their corresponding Play objects
    for (int pID=0; pID<PlayBook::MAX_PLAYS; ++pID)
    {
      assert(playList[pID] != NULL); // Play has not been assigned a Play object
    }
  }
}
