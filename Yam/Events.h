#pragma once

#include "YamUtility.h"

namespace Yam
{
	class YAM_API KeyPressed
	{
	public:
		KeyPressed(int code);
		KeyPressed() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class YAM_API KeyReleased
	{
	public:
		KeyReleased(int code);
		KeyReleased() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};
}
