#pragma once
#include "Bullet.h"

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

	Bullet GetBullet() { return *bullet; }

private:

	Bullet* bullet;

	int mPosX;
	int mPosY;
	int mRadius;
	int mSpeed;

};

