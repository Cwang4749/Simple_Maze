#include "FreeApp.h"

FreeApp::FreeApp()
{
	SetKeyPressedCallBack([this](const Yam::KeyPressed& e) {
		switch (e.GetKeyCode())
		{
		case YAM_KEY_LEFT:
			mXSpeed = -3;
			break;
		case YAM_KEY_RIGHT:
			mXSpeed = 3;
			break;
		case YAM_KEY_UP:
			mYSpeed = 3;
			break;
		case YAM_KEY_DOWN:
			mYSpeed = -3;
			break;
		case YAM_KEY_A:
			if(BotStateChange(mBotState, BotState::SideL))
				mBotState = BotState::SideL;
			break;
		case YAM_KEY_D:
			if(BotStateChange(mBotState, BotState::SideR))
				mBotState = BotState::SideR;
			break;
		case YAM_KEY_S:
			if(BotStateChange(mBotState, BotState::Standing))
				mBotState = BotState::Standing;
			break;
		}
		});

	SetKeyReleasedCallBack([this](const Yam::KeyReleased& e) {
		mXSpeed = 0;
		mYSpeed = 0;
		});

	InitializeCoords();
}

void FreeApp::OnUpdate()
{
	// Draw Background
	Sweep();
	DrawMaze();
	mGoal.Draw();

	// Calculate new movement
	mBot.SetX(mBot.GetX() + mXSpeed);
	mBot.SetY(mBot.GetY() + mYSpeed);
	CheckCollide();

	// Switch to correct active image
	ChangeState();

	Borders();

	mBot.Draw();
}

void FreeApp::InitializeCoords()
{
	// Buffer var
	int x{ 0 }, y{ 0 };

	// Initialize bot coords
	x = Yam::GmWin::GetWindow()->GetWidth() - 20;
	x -= mBot.GetWidth();
	mBot.SetX(x);
	mBot.SetY(20);

	// Initialize sweeper coords
	x = mStationary[12].GetWidth() + 30;
	y = Yam::GmWin::GetWindow()->GetHeight() - mSweeperV.GetHeight();
	mSweeperV.SetX(x);
	mSweeperV.SetY(y);

	// Initialize Goal coords
	mGoal.SetActiveImg(0);
	y = Yam::GmWin::GetWindow()->GetHeight() - mStationary[12].GetHeight() - mGoal.GetHeight();
	mGoal.SetX(0);
	mGoal.SetY(y);

	// Rightmost Wall (i = 0)
	x = Yam::GmWin::GetWindow()->GetWidth();
	x -= mStationary[0].GetWidth();
	y = mBot.GetHeight() + 40 + mStationary[2].GetHeight();
	mStationary[0].SetX(x);
	mStationary[0].SetY(y);

	// Leftmost Wall (i = 14, Stage 2)
	mStationary[14].SetX(0);
	mStationary[14].SetY(y);

	//--------Base----------
	// Left Wall of base (i = 1)
	x = Yam::GmWin::GetWindow()->GetWidth() - 40;
	x -= mBot.GetWidth();
	x -= mStationary[1].GetWidth();
	mStationary[1].SetX(x);
	mStationary[1].SetY(0);
	//Top Wall of base (i = 2)
	x = Yam::GmWin::GetWindow()->GetWidth();
	x -= mStationary[2].GetWidth();
	y = mBot.GetHeight() + 40;
	mStationary[2].SetX(x);
	mStationary[2].SetY(y);

	//--------Maze Horizontal Walls----------
	// H1 (i = 3)
	y = mBot.GetHeight() + 40;
	mStationary[3].SetX(0);
	mStationary[3].SetY(y);
	// H2 (i = 4)
	x = mStationary[0].GetX() - 115 - mStationary[7].GetWidth() - mStationary[4].GetWidth();
	y = mStationary[3].GetY() + 10 + mStationary[6].GetHeight();
	mStationary[4].SetX(x);
	mStationary[4].SetY(y);
	// H3 (i = 5)
	x = mStationary[4].GetX() - 115 - mStationary[5].GetWidth();
	y = mStationary[3].GetY() + 10 + mStationary[6].GetHeight();
	mStationary[5].SetX(x);
	mStationary[5].SetY(y);

	//--------Maze Vertical Walls----------
	// V1 (i = 6)
	x = mStationary[3].GetWidth() - mStationary[6].GetWidth();
	y = mBot.GetHeight() + 40 + mStationary[3].GetHeight();
	mStationary[6].SetX(x);
	mStationary[6].SetY(y);
	// V2 (i = 7)
	x = mStationary[0].GetX() - 115 - mStationary[7].GetWidth();
	y = mStationary[3].GetY() + 10 + mStationary[6].GetHeight();
	mStationary[7].SetX(x);
	mStationary[7].SetY(y);
	// V3 (i = 8)
	x = mStationary[7].GetX() - 115 - mStationary[8].GetWidth();
	y = Yam::GmWin::GetWindow()->GetHeight() - mStationary[8].GetHeight();
	mStationary[8].SetX(x);
	mStationary[8].SetY(y);
	// V4 (i = 9)
	x = mStationary[8].GetX() - 160 - mStationary[9].GetWidth();
	y = Yam::GmWin::GetWindow()->GetHeight() - mStationary[9].GetHeight();
	mStationary[9].SetX(x);
	mStationary[9].SetY(y);
	// V5 (i = 10)
	x = mStationary[9].GetX();
	y = mStationary[9].GetY() - 105 - mStationary[10].GetHeight();
	mStationary[10].SetX(x);
	mStationary[10].SetY(y);
	// V6 (i = 11)
	x = mStationary[9].GetX() - 160;
	y = Yam::GmWin::GetWindow()->GetHeight() - mStationary[11].GetHeight();
	mStationary[11].SetX(x);
	mStationary[11].SetY(y);
	// V7 (i = 12)
	y = Yam::GmWin::GetWindow()->GetHeight() - mStationary[12].GetHeight();
	mStationary[12].SetX(0);
	mStationary[12].SetY(y);
	// V8 (i = 13)
	y = mStationary[12].GetY() - 105 - mStationary[13].GetHeight();
	mStationary[13].SetX(0);
	mStationary[13].SetY(y);
}

void FreeApp::StageTwo()
{
	// Buffer var
	int x{ 0 }, y{ 0 };

	// Reset Bot
	x = Yam::GmWin::GetWindow()->GetWidth() - 20;
	x -= mBot.GetWidth();
	mBot.SetX(x);
	mBot.SetY(20);

	// Change Goal state and coords
	mGoal.SetActiveImg(1);
	x = Yam::GmWin::GetWindow()->GetWidth() / 2;
	x -= (mGoal.GetWidth() / 2);
	y = Yam::GmWin::GetWindow()->GetHeight() - mGoal.GetHeight();
	mGoal.SetX(x);
	mGoal.SetY(y);
}

void FreeApp::DrawMaze()
{
	switch (mStage)
	{
	case 1:
		for (int i = 0; i < mStationary.size() - 1; i++)
		{
			mStationary[i].Draw();
		}
		break;
	case 2:

		for (int i = 0; i < 4; i++)
		{
			mStationary[i].Draw();
		}
		mStationary[14].Draw();
		break;
	}
}

void FreeApp::ChangeState()
{
	switch (mBotState)
	{
	case BotState::Standing:
		mBot.SetActiveImg(0);
		break;
	case BotState::SideL:
		mBot.SetActiveImg(1);
		break;
	case BotState::SideR:
		mBot.SetActiveImg(2);
		break;
	}
}

void FreeApp::CheckCollide()
{
	if(Collide(mBot, mGoal))
		StageClear();

	// Collision with sweeper
	if (Collide(mBot, mSweeperV) || ((mStage == 2) && Collide(mBot, mSweeperH)))
		Reset();

	// Collision with walls
	for (int i = 0; i < mStationary.size() - 1; i++)
	{
		if (mStage == 1 || i < 4)
		{
			if (Collide(mBot, mStationary[i]))
			{
				if (mXSpeed != 0)
					mBot.SetX(mBot.GetX() - mXSpeed);
				if (mYSpeed != 0)
					mBot.SetY(mBot.GetY() - mYSpeed);
			}
		}
	}
	if (mStage == 2)
	{
		if (Collide(mBot, mStationary[14]))
		{
			if (mXSpeed != 0)
				mBot.SetX(mBot.GetX() - mXSpeed);
			if (mYSpeed != 0)
				mBot.SetY(mBot.GetY() - mYSpeed);
		}
	}
}

void FreeApp::Reset()
{
	mBotState = BotState::Standing;
	mBot.SetActiveImg(0);
	int xBuffer{ 0 };
	xBuffer = Yam::GmWin::GetWindow()->GetWidth() - 20;
	xBuffer -= mBot.GetWidth();
	mBot.SetX(xBuffer);
	mBot.SetY(20);
}

void FreeApp::StageClear()
{
	switch (mStage)
	{
	case 1:
		StageTwo();
		mStage = 2;
		break;
	case 2:
		exit(0);
		break;
	}
}

void FreeApp::Borders()
{
	// Prevent bot from exceeding Y boundaries
	if (mBot.GetY() <= 0)
		mBot.SetY(mBot.GetY() - mYSpeed);
	if (mBot.GetY() + mBot.GetHeight() >= Yam::GmWin::GetWindow()->GetHeight())
		mBot.SetY(mBot.GetY() - mYSpeed);

	// Horizontal Looping
	if (mBot.GetX() + mBot.GetWidth() >= Yam::GmWin::GetWindow()->GetWidth())
	{
		int xBuffer = mBot.GetX();
		mBot.SetX(xBuffer - Yam::GmWin::GetWindow()->GetWidth());

		// Check collision with sweeper before drawing looped bot
		CheckCollide();

		if (mBot.GetX() != Yam::GmWin::GetWindow()->GetWidth() - 20 - mBot.GetWidth())
		{
			mBot.Draw();
			if (xBuffer <= Yam::GmWin::GetWindow()->GetWidth())
				mBot.SetX(xBuffer);
		}
	}
	else if (mBot.GetX() <= 0)
	{
		int xBuffer = mBot.GetX();
		mBot.SetX(xBuffer + Yam::GmWin::GetWindow()->GetWidth());

		// Check collision with sweeper before drawing looped bot
		CheckCollide();

		if (mBot.GetX() != Yam::GmWin::GetWindow()->GetWidth() - 20 - mBot.GetWidth())
		{
			mBot.Draw();
			if (xBuffer + mBot.GetWidth() >= 0)
				mBot.SetX(xBuffer);
		}
	}
		

}

void FreeApp::Sweep()
{
	// Buffer var
	int buffer{ 0 };

	switch (mStage)
	{
	case 1:
		mSweeperV.SetY(mSweeperV.GetY() + mSweepSpeedV);
		if (mSweeperV.GetY() + mSweeperV.GetHeight() >= Yam::GmWin::GetWindow()->GetHeight() || mSweeperV.GetY() <= 0) {
			mSweeperV.SetY(mSweeperV.GetY() - mSweepSpeedV);
			mSweepSpeedV = -mSweepSpeedV;
		}
		mSweeperV.Draw();
		break;
	case 2:
		// Move Vertical Sweeper
		mSweeperV.SetY(mSweeperV.GetY() + mSweepSpeedV);
		if (mSweeperV.GetY() + mSweeperV.GetHeight() >= Yam::GmWin::GetWindow()->GetHeight() || mSweeperV.GetY() <= 0) {
			mSweeperV.SetY(mSweeperV.GetY() - mSweepSpeedV);
			mSweepSpeedV = -mSweepSpeedV;
		}

		// Clone Vertical Sweeper
		for (int i = 1; i < 5; i++)
		{
			buffer = i * 160;
			buffer -= 25;
			mSweeperV.SetX(buffer);
			mSweeperV.Draw();

			// Collision with sweeper
			if (Collide(mBot, mSweeperV))
				Reset();
		}

		// Move Horizontal Sweeper
		mSweeperH.SetX(mSweeperH.GetX() + mSweepSpeedH);
		if (mSweeperH.GetX() + mSweeperH.GetWidth() >= Yam::GmWin::GetWindow()->GetWidth() || mSweeperH.GetX() <= 0) {
			mSweeperH.SetX(mSweeperH.GetX() - mSweepSpeedH);
			mSweepSpeedH = -mSweepSpeedH;
		}

		// Clone Horizontal Sweeper
		for (int i = 0; i < 4; i++)
		{
			buffer = i * 150;
			buffer = Yam::GmWin::GetWindow()->GetHeight() - buffer - 12;
			mSweeperH.SetY(buffer);
			mSweeperH.Draw();

			// Collision with sweeper
			if (Collide(mBot, mSweeperH))
				Reset();
		}
		break;
	}
}

bool FreeApp::BotStateChange(BotState old_state, BotState new_state)
{
	mBotState = new_state;
	ChangeState();

	// Collision with walls
	for (int i = 0; i < mStationary.size() - 1; i++)
	{
		if (Collide(mBot, mStationary[i]))
		{
			mBotState = old_state;
			return false;
		}
	}

	// Collision with sweeper
	if (Collide(mBot, mSweeperV) || ((mStage == 2) && Collide(mBot, mSweeperH)))
	{
		Reset();
		return false;
	}
	return true;
}

bool FreeApp::Collide(const Entity& one, const Entity& two)
{
	int oneL{ one.GetX() };
	int oneR{ one.GetX() + one.GetWidth() };
	int twoL{ two.GetX() };
	int twoR{ two.GetX() + two.GetWidth() };

	int oneB{ one.GetY() };
	int oneT{ one.GetY() + one.GetHeight() };
	int twoB{ two.GetY() };
	int twoT{ two.GetY() + two.GetHeight() };
	
	bool collideX{ false };
	if ((oneL <= twoL && twoL <= oneR) ||
		(twoL <= oneL && oneL <= twoR))
		collideX = true;

	bool collideY{ false };
	if ((oneB <= twoB && twoB <= oneT) ||
		(twoB <= oneB && oneB <= twoT))
		collideY = true;

	return collideX && collideY;
}