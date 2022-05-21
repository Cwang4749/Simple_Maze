#pragma once
#include "Window.h"
#include "YamUtility.h"
#include "Events.h"

namespace Yam
{
	class YAM_API GmWin
	{
	public:
		static void Init();
		static GmWin* GetWindow();

		bool CreateWindow(int width, int height, const std::string& name);
		void SwapBuffers();
		void GetEvents();

		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallBack(const std::function<void(const KeyPressed&)>& keyPressCallback);
		void SetKeyReleasedCallBack(const std::function<void(const KeyReleased&)>& keyReleaseCallback);

		bool CloseWindow();

	private:
		inline static GmWin* mInst{nullptr};

		GmWin();

		Window* mWindow{ nullptr };
	};
}