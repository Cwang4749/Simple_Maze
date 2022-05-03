#include "PrecompH.h"
#include "Renderer.h"
#include "GmWin.h"
#include "UseOGL/oglRenderer.h"

namespace Yam
{
	void Renderer::Init()
	{
		if(mInst == nullptr)
			mInst = new Renderer;
	}

	void Renderer::Draw(Yam::Sprite& pic, int x, int y, int z)
	{
		assert(mInst != nullptr);
		
		mInst->mType->Draw(pic, x, y, z, mInst->mShader);
	}

	void Renderer::ClearScreen()
	{
		mInst->mType->ClearScreen();
	}

	Renderer::Renderer() : mShader("../Yam/Assets/Shaders/defaultVertex.glsl", "../Yam/Assets/Shaders/defaultFragment.glsl")
	{	
#ifdef YAM_OPENGL
		mType = new oglRenderer;
#else
		#ONLY_OPENGL_SUPPORTED_FOR_NOW
#endif
	}
}