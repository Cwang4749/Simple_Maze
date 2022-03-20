
#include "PrecompH.h"
#include "YamApp.h"

namespace Yam
{
	void YamApp::Run()
	{
		YAM_LOG("Yam is running...");

		while (true)
		{
			OnUpdate();
		}
	}
}