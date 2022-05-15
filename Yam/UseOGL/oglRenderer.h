#pragma once

#include "RendererType.h"

namespace Yam
{
	class oglRenderer : public RendererType
	{
	public:
		virtual void Draw(Yam::Sprite& pic, int x, int y, int z, Yam::Shader shader) override;
		virtual void ClearScreen() override;
	};
}