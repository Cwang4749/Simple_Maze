#pragma once

#include "YamUtility.h"
#include "PrecompH.h"

#define YAM_FRAMERATE 60

namespace Yam
{
	class YAM_API YamApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		
	private:
		std::chrono::milliseconds mFrameDuration{ 1000/ YAM_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

