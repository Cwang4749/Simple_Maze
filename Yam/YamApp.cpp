
#include "PrecompH.h"
#include "YamApp.h"
#include "GmWin.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "KeyCodes.h"

namespace Yam
{
	void YamApp::Run()
	{
		YAM_LOG("Yam is running...");

		Yam::GmWin::Init();

		Yam::GmWin::GetWindow()->CreateWindow(800, 600, "Free Game");
		

		Renderer::Init();

		Yam::Sprite bot("../Yam/Assets/Images/Bot.png");
		Yam::Sprite BG("../Yam/Assets/Images/Background.png");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;


		int x{ 50 }, y{ 50 };
		//auto keyCall = [](const KeyPressed& event) {YAM_LOG(event.GetKeyCode()); };
		//auto keyRelease = [](const KeyReleased& event) {YAM_LOG(event.GetKeyCode()); };
		auto keyCall = [&x, &y](const KeyPressed& event) {
			if (event.GetKeyCode() == YAM_KEY_LEFT) x -= 5;
			if (event.GetKeyCode() == YAM_KEY_RIGHT) x += 5;
			if (event.GetKeyCode() == YAM_KEY_DOWN) y -= 5;
			if (event.GetKeyCode() == YAM_KEY_UP) y += 5;
		};
		SetKeyPressedCallBack(keyCall);
		//SetKeyReleasedCallBack(keyRelease);


		while (true)
		{
			OnUpdate();

			Renderer::ClearScreen();
			Renderer::Draw(BG, 0, 0, 0);

			Renderer::Draw(bot, x, y, 1);

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