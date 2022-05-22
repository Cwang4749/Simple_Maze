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
	std::vector<Entity> mStationary{ { {"Assets/Images/WallR.png"} }, 
									{ {"Assets/Images/BaseL.png"} }, 
									{ {"Assets/Images/BaseT.png"} },
									{ {"Assets/Images/H1.png"} },
									{ {"Assets/Images/H2.png"} },
									{ {"Assets/Images/H3.png"} },
									{ {"Assets/Images/V1.png"} },
									{ {"Assets/Images/V2.png"} },
									{ {"Assets/Images/V3.png"} },
									{ {"Assets/Images/V4.png"} },
									{ {"Assets/Images/V5.png"} },
									{ {"Assets/Images/V6.png"} },
									{ {"Assets/Images/V7.png"} },
									{ {"Assets/Images/V8.png"} },
									{ {"Assets/Images/WallR.png"} }
									};

	enum class BotState { Standing, SideR, SideL } mBotState{BotState::Standing};
	bool BotStateChange(BotState old_state, BotState new_state);

	int mXSpeed{ 0 };
	int mYSpeed{ 0 };
	int mSweepSpeedV{ -3 };
	int mSweepSpeedH{ 3 };
	int mStage{ 1 };
};