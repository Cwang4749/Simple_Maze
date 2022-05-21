#pragma once

#include "Yam.h"
#include "Entity.h"

class FreeApp : public Yam::YamApp
{
public:

	FreeApp();
	virtual void OnUpdate() override;

	void InitializeCoords();
	void CheckCollide();
	void Borders();
	void Sweep();
	bool Collide(const Entity& one, const Entity& two);

private:
	Entity mBot{ {"Assets/Images/BotStand.png", "Assets/Images/BotSideL.png", "Assets/Images/BotSideR.png"} };
	Entity mSweeper{ {"Assets/Images/Sweeper.png"} };
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
									};

	enum class BotState { Standing, SideR, SideL } mBotState{BotState::Standing};

	int mXSpeed{ 0 };
	int mYSpeed{ 0 };
	int mSweepSpeed{ -3 };
};