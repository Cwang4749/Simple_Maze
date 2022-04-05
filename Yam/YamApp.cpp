
#include "PrecompH.h"
#include "YamApp.h"
#include "GmWin.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"  //maybe can be removed

namespace Yam
{
	void YamApp::Run()
	{
		YAM_LOG("Yam is running...");

		Yam::GmWin::Init();

		Yam::GmWin::GetWindow()->CreateWindow(800, 600, "Free Game");
		
		while (true)
		{
			OnUpdate();

			Yam::GmWin::GetWindow()->SwapBuffers();
			Yam::GmWin::GetWindow()->GetEvents();
		}
	}

	void YamApp::OnUpdate()
	{
	}
}