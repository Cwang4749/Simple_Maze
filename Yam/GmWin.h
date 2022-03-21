#pragma once
#include "Window.h"
#include "YamUtility.h"

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

	private:
		inline static GmWin* mInst{nullptr};

		GmWin();

		Window* mWindow{ nullptr };
	};
}