#include "PrecompH.h"
#include "GlfwWin.h"
#include "YamUtility.h"
#include "Events.h"

namespace Yam
{
	GlfwWin::GlfwWin() 
	{
		if (!glfwInit())
			YAM_LOG("ERROR: GLFW Initialization Failed");

		/*if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			YAM_LOG("ERROR: GLAD Initialization Failed");*/
	}

	bool GlfwWin::CreateWindow(int width, int height, const std::string& name)
	{
		mGlfwWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		
		if (mGlfwWindow == nullptr)
		{
			YAM_LOG("ERROR: Creation Failed");
			return false;
		}

		glfwMakeContextCurrent(mGlfwWindow);
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			YAM_LOG("ERROR: Glad failed to initialize");

		glfwSetWindowUserPointer(mGlfwWindow, &mCallbacks);

		glfwSetKeyCallback(mGlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPressed event{ key };
					userPointer->keyPressCallback(event);
				}
				else if (action == GLFW_RELEASE)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyReleased event{ key };
					userPointer->keyReleaseCallback(event);
				}
			}
		);

		return true;
	}

	void GlfwWin::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}

	void GlfwWin::GetEvents()
	{
		glfwPollEvents();
	}

	int GlfwWin::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return width;
	}

	int GlfwWin::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return height;
	}

	GlfwWin::~GlfwWin()
	{
		if (mGlfwWindow != nullptr)
			glfwDestroyWindow(mGlfwWindow);

		glfwTerminate();
	}

	void GlfwWin::SetKeyPressedCallBack(std::function<void(const KeyPressed&)> keyPressCallback)
	{
		mCallbacks.keyPressCallback = keyPressCallback;
	}
	void GlfwWin::SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> keyReleaseCallback)
	{
		mCallbacks.keyReleaseCallback = keyReleaseCallback;
	}
	bool GlfwWin::CloseWindow()
	{
		return glfwWindowShouldClose(mGlfwWindow);
	}
}