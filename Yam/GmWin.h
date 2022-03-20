#pragma once
#include "Window.h"

namespace Yam
{
	class GmWin
	{
	public:
		static void Init();
		static GmWin* GetWindow();

		bool CreateWindow(int width, int height, const std::string& name);
		void SwapBuffers();
		void GetEvents();

		int GetWidth() const;
		int GetHeight() const;

	private:
		inline static GmWin* mInst{nullptr};

		GmWin();

		Window* mWindow{nullptr};
	};
}