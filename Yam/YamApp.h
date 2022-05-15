#pragma once

#include "YamUtility.h"
#include "PrecompH.h"
#include "Events.h"

#define YAM_FRAMERATE 60

namespace Yam
{
	class YAM_API YamApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		void SetKeyPressedCallBack(std::function<void(const KeyPressed &)> keyPressCallback);
		void SetKeyReleasedCallBack(std::function<void(const KeyReleased &)> keyReleaseCallback);
		
	private:
		std::chrono::milliseconds mFrameDuration{ 1000/ YAM_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

