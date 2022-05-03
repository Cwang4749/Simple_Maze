#include "PrecompH.h"
#include "Sprite.h"
#include "UseOGL/oglSprite.h"

namespace Yam {
	Sprite::Sprite(const std::string& file)
	{
#ifdef YAM_OPENGL
		mType = new oglSprite(file);
#else
		#ONLY_OPENGL_CURRENTLY 
#endif
	}
	int Sprite::GetWidth() const
	{
		return mType->GetWidth();
	}
	int Sprite::GetHeight() const
	{
		return mType->GetHeight();
	}
	void Sprite::Bind()
	{
		mType->Bind();
	}
}