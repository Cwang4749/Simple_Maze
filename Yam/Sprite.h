#pragma once

#include "SpriteType.h"
#include "YamUtility.h"

namespace Yam {
	class YAM_API Sprite
	{
	public:
		Sprite(const std::string& file);
		int GetWidth() const;
		int GetHeight() const;
		void Bind();

	private:
		SpriteType* mType;
	};
}

