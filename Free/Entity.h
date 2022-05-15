#pragma once
#include "Yam.h"
#include <vector>

class Entity
{
public:
	Entity(const std::vector<std::string>& files);

	int GetX() const;
	int GetY() const;
	int GetZ() const;
	bool GetSolid() const;
	int GetActiveImg() const;
	int GetWidth() const;
	int GetHeight() const;

	void SetX(int x);
	void SetY(int y);
	void SetZ(int z);
	void SetSolid(bool solid);
	void SetActiveImg(int image);

	void Draw();

private:
	int mX{ 0 };
	int mY{ 0 };
	int mZ{ 0 };
	bool mSolid{ true };

	int mActiveImg{ 0 };

	std::vector<Yam::Sprite> mImgs;
};

