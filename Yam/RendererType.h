#pragma once

#include "Sprite.h"
#include "Shader.h"

namespace Yam
{
	class RendererType
	{
	public:
		virtual void Draw(Yam::Sprite& pic, int x, int y, int z, Yam::Shader shader) = 0;
		virtual void ClearScreen() = 0;
	};
}