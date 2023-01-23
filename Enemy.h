#pragma once

class Bullet;

class Enemy
{
public:
	Enemy(int posX,int posY);
	~Enemy();

	void Update(Bullet bullet);
	void Draw();
	void Reset();
	int GetIsAlive() {
		if (mIsAlive == true) {
			return 1;
		}
		else {
			return 0;
		}
	}

	static bool mIsAlive;

private:

	int mPosX;
	int mPosY;
	int mRadius;
	int mSpeed;

};

