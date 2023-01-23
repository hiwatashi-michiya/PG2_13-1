#pragma once

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Draw();
	void SetBullet(int posX, int posY);

	bool isHitBullet(int posX, int posY, int radius);

private:

	int mPosX[10];
	int mPosY[10];
	int mRadius[10];
	int mSpeed;
	bool mIsShot[10];

};

