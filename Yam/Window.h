#pragma once
#include "PrecompH.h"

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
	};
}