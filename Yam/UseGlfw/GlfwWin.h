#pragma once

#include "Window.h"
#include "GLFW/glfw3.h"

namespace Yam
{
	class GlfwWin : public Window
	{
	public:
		GlfwWin();
		virtual bool CreateWindow(int width, int height, const std::string& name) override;
		virtual void SwapBuffers() override;
		virtual void GetEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~GlfwWin();

	private:
		GLFWwindow* mGlfwWindow;

	};
}