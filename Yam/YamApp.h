#pragma once

#include "YamUtility.h"

namespace Yam
{
	class YAM_API YamApp
	{
	public:
		void Run();
		virtual void OnUpdate();
	};
}

