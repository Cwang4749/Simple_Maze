#pragma once
#include "PrecompH.h"
#include "Events.h"

namespace Yam
{
	class Window
	{
	public:
		virtual bool CreateWindow(int width, int height, const std::string& name) = 0;
		virtual void SwapBuffers() = 0;
		virtual void GetEvents() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> keyPressCallback) = 0;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> keyReleaseCallback) = 0;
		virtual bool CloseWindow() = 0;
	};
}