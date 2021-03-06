#include "PrecompH.h"
#include "GmWin.h"
#include "UseGlfw/GlfwWin.h"

namespace Yam
{
	void GmWin::Init()
	{
		if(mInst == nullptr)
			mInst = new GmWin;
	}

	GmWin* GmWin::GetWindow()
	{
		assert(mInst);
		return mInst;
	}

	bool GmWin::CreateWindow(int width, int height, const std::string& name)
	{
		return mWindow->CreateWindow(width, height, name);
	}

	void GmWin::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GmWin::GetEvents()
	{
		mWindow->GetEvents();
	}

	int GmWin::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int GmWin::GetHeight() const
	{
		return mWindow->GetHeight();
	}

	void GmWin::SetKeyReleasedCallBack(const std::function<void(const KeyReleased&)>& keyReleaseCallback)
	{
		mWindow->SetKeyReleasedCallBack(keyReleaseCallback);
	}

	bool GmWin::CloseWindow()
	{
		return mWindow->CloseWindow();
	}

	void GmWin::SetKeyPressedCallBack(const std::function<void(const KeyPressed&)>& keyPressCallback)
	{
		mWindow->SetKeyPressedCallBack(keyPressCallback);
	}

	GmWin::GmWin()
	{
#ifdef YAM_WINDOWS
		mWindow = new GlfwWin;
#elif defined YAM_MACOS
		mWindow = new GlfwWin;
#elif defined YAM_LINUX
		mWindow = new GlfwWin;
#else
	#Unsupported_platform
#endif
	}
}
