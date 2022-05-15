#include "PrecompH.h"
#include "Events.h"

namespace Yam
{
	KeyPressed::KeyPressed(int code) : mKeyCode(code)
	{
	}
	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}


	KeyReleased::KeyReleased(int code) : mKeyCode(code)
	{
	}
	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}
