#include "Entity.h"
#include "Yam.h"

Entity::Entity(const std::vector<std::string>& files) : 
	mImgs(files.begin(), files.end())
{
}

int Entity::GetX() const
{
	return mX;
}

int Entity::GetY() const
{
	return mY;
}

int Entity::GetZ() const
{
	return mZ;
}

bool Entity::GetSolid() const
{
	return mSolid;
}

int Entity::GetActiveImg() const
{
	return mActiveImg;
}

int Entity::GetWidth() const
{
	return mImgs[mActiveImg].GetWidth();
}

int Entity::GetHeight() const
{
	return mImgs[mActiveImg].GetHeight();
}

void Entity::SetX(int x)
{
	mX = x;
}

void Entity::SetY(int y)
{
	mY = y;
}

void Entity::SetZ(int z)
{
	mZ = z;
}

void Entity::SetSolid(bool solid)
{
	mSolid = solid;
}

void Entity::SetActiveImg(int image)
{
	mActiveImg = image;
}

void Entity::Draw()
{
	Yam::Renderer::Draw(mImgs[mActiveImg], mX, mY, mZ);
}
