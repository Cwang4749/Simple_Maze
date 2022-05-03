#include "PrecompH.h"
#include "GlfwWin.h"
#include "YamUtility.h"

namespace Yam
{
	GlfwWin::GlfwWin()
	{
		if (!glfwInit())
			YAM_LOG("ERROR: GLFW Initialization Failed");

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			YAM_LOG("ERROR: GLAD Initialization Failed");
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
}