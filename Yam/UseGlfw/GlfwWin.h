#pragma once

#include "Window.h"
#include "glad/glad.h"
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

		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> keyPressCallback) override;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> keyReleaseCallback) override;

	private:
		struct Callbacks
		{
			std::function<void(const KeyPressed&)> keyPressCallback{ [](const KeyPressed&) {} };
			std::function<void(const KeyReleased&)> keyReleaseCallback{ [](const KeyReleased&) {} };
		}mCallbacks;

		GLFWwindow* mGlfwWindow;
	};
}