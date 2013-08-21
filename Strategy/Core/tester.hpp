#include "mainheaders.hpp"
#include "thread.h"
#include "trainers.hpp"
#include "strategygui_thread.hpp"
#include "command-packet.pb.h"
using namespace std;
using namespace Strategy;

class Tester : public Util::Thread
{
public:
  bool &running;
  BeliefState &state;
  Tester(bool &running_, BeliefState &state_):
  running(running_),state(state_) {}
  void run()
  {
    Util::CS loggerCS;
    Util::Logger logger("timelog.log", Util::Logger::Write, loggerCS);
    Kalman      kFilter;
    VisionThread vThread(&kFilter);
    vThread.start();

    #ifdef STR_GUI
    Util::CS strCS;
    StrategyPacket strPktSh;
    StrategyGUIThread strGUIThread = StrategyGUIThread::getInstance(&strPktSh, &strCS);
    strGUIThread.start();
    #endif
    //tGoalKeeping
    TGoalKeepingOurSide tGoalOur0(&state, 0);
    TGoalKeepingOurSide tGoalOur1(&state, 1);
	TGoalKeepingOurSide tGoalOur2(&state, 2);
	TGoalKeepingOurSide tGoalOur4(&state, 4);
    Tactic::Param paramGoal;
    TGoalKeepingOppSide tGoalOpp(&state, 1);
    
    //tCharge
    TCharge tCharge2(&state, 2);
    TCharge tCharge0(&state, 0);
    Tactic::Param pCharge;
    
    //tReceiveBall
    TReceiveBall tReceive2(&state, 2);
    TReceiveBall tReceive0(&state, 0);
		TReceiveBall tReceive1(&state, 1);
    Tactic::Param pReceive;
    
    
    //tCover Bot
    TCoverGoal tcover0(&state, 0);
    TCoverGoal tcover2(&state,2);
		TCoverGoal tcover3(&state,3);
    Tactic::Param paramcover;
    paramcover.CoverGoalP.distFromGoal = -2*DBOX_WIDTH;
    
    //tStop Bot
    TStop tS0(&state, 0);
    TStop tS1(&state, 1);
    TStop tS2(&state, 2);
    Tactic::Param paramStop;
    
    //tposition
    TPosition tPos1(&state, 1);
    TPosition tPos2(&state,2);
    Tactic::Param pPos;
    pPos.PositionP.align = false;
    pPos.PositionP.x= 0;
    pPos.PositionP.y= 0;
    pPos.PositionP.finalSlope=PI/2;
    
    //tDefendLine
    TDefendLine tDefendLine1(&state,1);
    TDefendLine tDefendLine2(&state,2);

    Tactic::Param pDefendL1;
    pDefendL1.DefendLineP.x1 = BOT_RADIUS/2;
    pDefendL1.DefendLineP.y1 = -BOT_RADIUS/2;;
    pDefendL1.DefendLineP.x2 = HALF_FIELD_MAXX/2;
    pDefendL1.DefendLineP.y2 = -HALF_FIELD_MAXY;
    Tactic::Param pDefendL2;
    pDefendL2.DefendLineP.x1 = BOT_RADIUS/2;
    pDefendL2.DefendLineP.x2 = HALF_FIELD_MAXX/2;
    pDefendL2.DefendLineP.y1 = BOT_RADIUS/2;
    pDefendL2.DefendLineP.y2 = HALF_FIELD_MAXY;
	
	 
    
    //tVelocity
    TVelocity tVelocity(&state,3);
    Tactic::Param pVelocity;
    pVelocity.VelocityP.vl = 40;
    pVelocity.VelocityP.vr = 40;
  
    //tDefend Point
    TDefendPoint tDefendPoint2(&state,0);
    Tactic::Param pDefendPoint;
    pDefendPoint.DefendPointP.x = -HALF_FIELD_MAXX/2;
    pDefendPoint.DefendPointP.y = 0;
    pDefendPoint.DefendPointP.radius = HALF_FIELD_MAXX/4;       

    //tBackup
    Strategy::TBackup tBackup0(&state,0);
    TBackup tBackup1(&state,1);
    TBackup tBackup2(&state,2);
    Tactic::Param pBackup;
    pBackup.BackupP.BotID = 0;
    
    //tAttack
    TAttack tAttack1(&state, 1);
    TAttack tAttack0(&state, 0);
    TAttack tAttack2(&state, 2);
    TAttack tAttack3(&state, 3);
    TAttack tAttack4(&state, 4);
    Tactic::Param pAttack;
    pAttack.AttackP.rotateOnError = true;
    
    //tBlock
    TBlock tblock2(&state,2);
    TBlock tblock0(&state,0);
    Tactic::Param pBlock;
    pBlock.BlockP.dist = 1000;
    
    // TestgotoPoint
    Strategy::Testgotopoint ttest1(&state,1);
	
    //TestgotoPoint ttest1(&state,1);
    Tactic::Param ptestpoint;
    TestbotRace ttest2(&state,2);
    Tactic::Param ptestrace;
    ptestrace.TestbotRaceP.vl = 100;
    ptestrace.TestbotRaceP.vr = 100;
    
#ifdef BOTLOG
    FILE *f = fopen("/home/robo/botplot/compare_dataset/botlog.txt", "w");    
    fclose(f);
    f = fopen("/home/robo/botplot/compare_dataset/response.txt", "w");
    fclose(f);
#endif
    bool isRunning = true; 
    //    Util::Timer timer;
	int loopcount = 0;
    while(running)
    {
    //      timer.start();
      kFilter.update(state);
      state.update();
      #ifdef STR_GUI
      
      #endif
      if(1)
      {
        printf("Ball Pos: %d %d\n",state.ballPos.x,state.ballPos.y);
        //printf("our side %d\n",state.pr_ballOurSide);
        //printf("opp side %d\n",state.pr_ballOppSide);
        //printf("mid %d\n",state.pr_ballMidField);
        //printf("dbox %d\n",state.pr_ball_in_opp_dbox);    
        //ttest1.execute(ptestpoint);
        //tVelocity.execute(pVelocity);

   //     tGoalOur2.execute(paramGoal);
        //tGoalOur1.execute(paramGoal);
        //tGoalOur0.execute(paramGoal);
		//tGoalOur4.execute(paramGoal);

        
	//			tcover3.execute(paramcover);
        //tcover2.execute(paramcover);
        //tcover0.execute(paramcover);
        //goTopointStraight.executeSkill(SkillSet::GoToBallStraight,param1);
        //goToBallStraight.executeSkill(SkillSet::GoToBallStraight,param9)
        //tAttack2.execute(pAttack);
				//tReceive0.execute(pReceive);
				tReceive1.execute(pReceive);
		//tAttack3.execute(pAttack);
		//tAttack2.execute(pAttack);
        //tAttack4.execute(pAttack);

        //tcover0.execute(paramcover);
        //tcover2.execute(paramcover);
        //goTopointStraight.executeSkill(SkillSet::GoToBallStraight,param1);
        //goToBallStraight.executeSkill(SkillSet::GoToBallStraight,param9);
        // goTopointStraight.executeSkill(SkillSet::GoToPointStraight,param1);

       // tAttack0.execute(pAttack);
        //tAttack1.execute(pAttack);
        //tAttack3.execute(pAttack);
        //tAttack4.execute(pAttack);
		//tBackup0.execute(pBackup);
        //tDefendArc0.execute(pDefendArc);
        //tDefendLine1.execute(pDefendL1);
		//tDefendLine2.execute(pDefendL2);
        //tAttack2.execute(pAttack);
#ifdef COMBINED_PACKET
        SkillSet::comm->writeCombinedPacket();
#endif
#ifdef BOTLOG
#ifdef COMBINED_PACKET
        int vl, vr;
        //SkillSet::comm->getSentData(4, vl, vr);
        //SkillSet::errorLog(4, vl, vr, &state);
#else
  // no clue what to do in case of single bot (old) comm. Don't have sentVl and sentVr anymore...
#endif
#endif
        
        

        //tCharge2.execute(pCharge);
        //tDefendLine1.execute(pDefendL1);
        //tDefendLine2.execute(pDefendL2);
        //tPos1.execute(pPos);
        //tAttack2.execute(pAttack);
        //turnangle.executeSkill(SkillSet::TurnToAngle, sparam);
        //tReceive2.execute(pReceive);
        //tReceive0.execute(pReceive);
        //tblock0.execute(pBlock);
      }
     else
      {
        printf("OFF!\n");
        tS0.execute(paramStop);
        tS1.execute(paramStop);
        tS2.execute(paramStop);
      }
    //      printf("tIMER US = %d\n", timer.stopus() );
      //moprintf("Ball Pos: %d %d %f\n",state.ballPos.x,state.ballPos.y,state.homeAngle[2]);
         usleep(20000);  // Adding sleep to this thread of execution to prevent CPU hogging
      
    }
    vThread.stop();
    Util::Logger::toStdOut("Exiting process");
    return;

  }
};