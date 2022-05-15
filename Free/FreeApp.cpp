#include "FreeApp.h"

//void FreeApp::OnUpdate()
//{
//	switch (mBotState)
//	{
//	case BotState::Standing:
//		break;
//	case BotState::Rolling:
//		break;
//	}
//}
//
//bool FreeApp::CollideX(const Entity& one, const Entity& two)
//{
//	int oneL{ one.GetX() };
//	int oneR{ one.GetX() + one.GetWidth() };
//	int twoL{ two.GetX() };
//	int twoR{ two.GetX() + two.GetWidth() };
//	if ((twoL <= oneL && oneL <= twoR) ||
//		(twoL <= oneR && oneR <= twoR) ||
//		(oneL <= twoL && twoL <= oneR))
//		return true;
//	else 
//		return false;
//}
//
//bool FreeApp::CollideY(const Entity& one, const Entity& two)
//{
//	int oneB{ one.GetY() };
//	int oneT{ one.GetY() + one.GetHeight() };
//	int twoB{ two.GetY() };
//	int twoT{ two.GetY() + two.GetHeight() };
//	if ((twoB <= oneB && oneB <= twoT) ||
//		(twoB <= oneT && oneT <= twoT) ||
//		(oneB <= twoB && twoB <= oneT))
//		return true;
//	else
//		return false;
//}
