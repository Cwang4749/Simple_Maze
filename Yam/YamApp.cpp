
#include "PrecompH.h"
#include "YamApp.h"
#include "GmWin.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

namespace Yam
{
	void YamApp::Run()
	{
		YAM_LOG("Yam is running...");

		Yam::GmWin::Init();

		Yam::GmWin::GetWindow()->CreateWindow(800, 600, "Free Game");
		

		Renderer::Init();

		Yam::Sprite heart("../Yam/Assets/Images/Heart.png");
		
		int xPos{ -heart.GetWidth() };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(heart, xPos, 20, 1);

			xPos = (xPos + 5);

			std::this_thread::sleep_until(mNextFrameTime);

			Yam::GmWin::GetWindow()->SwapBuffers();
			Yam::GmWin::GetWindow()->GetEvents();
		
			mNextFrameTime += mFrameDuration;
		}
	}

	void YamApp::OnUpdate()
	{
	}
}