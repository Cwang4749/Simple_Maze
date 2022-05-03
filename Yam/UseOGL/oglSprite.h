#pragma once

#include "SpriteType.h"

namespace Yam {
	class oglSprite : public SpriteType
	{
	public:
		oglSprite(const std::string& file);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool IsBound() const override;

	private:
		unsigned int mVBO;
		unsigned int mVAO;
		unsigned int mEBO;
		unsigned int mTexture;
		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}
