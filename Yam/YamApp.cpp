
#include "PrecompH.h"
#include "YamApp.h"
#include "GmWin.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "KeyCodes.h"

namespace Yam
{
	YamApp::YamApp()
	{
		YAM_LOG("Yam is running...");

		Yam::GmWin::Init();

		Yam::GmWin::GetWindow()->CreateWindow(800, 600, "Free Game");

		Renderer::Init();
	}
	void YamApp::Run()
	{

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (!GmWin::GetWindow()->CloseWindow())
		{
			Renderer::ClearScreen();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Yam::GmWin::GetWindow()->SwapBuffers();
			Yam::GmWin::GetWindow()->GetEvents();
		
			mNextFrameTime += mFrameDuration;
		}
	}

	void YamApp::OnUpdate()
	{
	}

	void YamApp::SetKeyPressedCallBack(std::function<void(const KeyPressed&)> keyPressCallback)
	{
		GmWin::GetWindow()->SetKeyPressedCallBack(keyPressCallback);
	}

	void YamApp::SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> keyReleaseCallback)
	{
		GmWin::GetWindow()->SetKeyReleasedCallBack(keyReleaseCallback);
	}
}