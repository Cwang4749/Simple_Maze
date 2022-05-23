#pragma once

#include "Yam.h"
#include "Entity.h"

class FreeApp : public Yam::YamApp
{
public:

	FreeApp();
	virtual void OnUpdate() override;

	void InitializeCoords();
	void StageTwo();
	void StartAnimation();
	void EndAnimation();
	
	void DrawMaze();
	void ChangeState();
	void CheckCollide();
	void Reset();
	void StageClear();
	void Borders();
	void Sweep();

	bool Collide(const Entity& one, const Entity& two);

private:
	Entity mBot{ {"Assets/Images/BotStand.png", "Assets/Images/BotSideL.png", "Assets/Images/BotSideR.png"} };
	Entity mSweeperV{ {"Assets/Images/SweeperV.png"} };
	Entity mSweeperH{ {"Assets/Images/SweeperH.png"} };
	Entity mGoal{ {"Assets/Images/GoalV.png", "Assets/Images/GoalH.png"} };
	std::vector<Entity> mStationary{ { {"Assets/Images/WallR.png"} }, { {"Assets/Images/BaseL.png"} },  { {"Assets/Images/BaseT.png"} },  
									 { {"Assets/Images/H1.png"} },     { {"Assets/Images/H2.png"} },     { {"Assets/Images/H3.png"} },
									 { {"Assets/Images/V1.png"} },     { {"Assets/Images/V2.png"} },     { {"Assets/Images/V3.png"} },     
								 	 { {"Assets/Images/V4.png"} },     { {"Assets/Images/V5.png"} },     { {"Assets/Images/V6.png"} },
									 { {"Assets/Images/V7.png"} },     { {"Assets/Images/V8.png"} },     { {"Assets/Images/WallR.png"} }
									};

	Entity mBG{ {"Assets/Images/BG/BG2.png",  "Assets/Images/BG/BG4.png",  "Assets/Images/BG/BG6.png",  "Assets/Images/BG/BG8.png",
				 "Assets/Images/BG/BG10.png", "Assets/Images/BG/BG14.png", "Assets/Images/BG/BG18.png", "Assets/Images/BG/BG22.png",
				 "Assets/Images/BG/BG26.png", "Assets/Images/BG/BG30.png", "Assets/Images/BG/BG34.png", "Assets/Images/BG/BG38.png",
				 "Assets/Images/BG/BG42.png", "Assets/Images/BG/BG46.png", "Assets/Images/BG/BG50.png", "Assets/Images/BG/BG54.png",
				 "Assets/Images/BG/BG58.png", "Assets/Images/BG/BG62.png", "Assets/Images/BG/BG66.png", "Assets/Images/BG/BG70.png",
				 "Assets/Images/BG/BG74.png", "Assets/Images/BG/BG78.png", "Assets/Images/BG/BG82.png", "Assets/Images/BG/BG86.png",
				 "Assets/Images/BG/BG90.png", "Assets/Images/BG/BG92.png", "Assets/Images/BG/BG94.png", "Assets/Images/BG/BG96.png",
				 "Assets/Images/BG/BG98.png", "Assets/Images/BG/BG100.png"
				} };

	Entity mStart{ {"Assets/Images/Start/Start1.png", "Assets/Images/Start/Start2.png", "Assets/Images/Start/Start3.png", "Assets/Images/Start/Start4.png"} };
	Entity mEC{ {"Assets/Images/BG/EndCredit.png"} };

	enum class BotState { Standing, SideR, SideL } mBotState{BotState::Standing};
	bool BotStateChange(BotState old_state, BotState new_state);

	int mXSpeed{ 0 };
	int mYSpeed{ 0 };
	int mSweepSpeedV{ -3 };
	int mSweepSpeedH{ 3 };
	int mStage{ 0 };
	int mTimer{ 0 };
};