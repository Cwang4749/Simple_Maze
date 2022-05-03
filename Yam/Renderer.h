#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererType.h"
#include "YamUtility.h"

namespace Yam
{
	class YAM_API Renderer
	{
	public:
		static void Init();
		static void Draw(Yam::Sprite &pic, int x, int y, int z);
		static void ClearScreen();

	private:
		inline static Renderer* mInst{ nullptr };
		
		RendererType* mType{ nullptr };

		Renderer();

		Yam::Shader mShader;
	};
}