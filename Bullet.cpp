#include "Bullet.h"
#include <Novice.h>
#include <math.h>

Bullet::Bullet()
{

	for (int i = 0; i < 10; i++) {

		mPosX[i] = -100;
		mPosY[i] = -100;
		mRadius[i] = 10;
		mIsShot[i] = false;

	}

	mSpeed = 10;

}

Bullet::~Bullet()
{
}

void Bullet::Update() {

	for (int i = 0; i < 10; i++) {

		if (mIsShot[i] == true) {

			mPosY[i] -= mSpeed;

			if (mPosY[i] + mRadius[i] < 0) {
				mIsShot[i] = false;
			}

		}

	}

	

}

void Bullet::SetBullet(int posX, int posY) {

	for (int i = 0; i < 10; i++) {

		if (mIsShot[i] == false) {

			mPosX[i] = posX;
			mPosY[i] = posY;
			mIsShot[i] = true;
			break;

		}

	}

}

bool Bullet::isHitBullet(int posX, int posY, int radius) {

	for (int i = 0; i < 10; i++) {

		if (mIsShot[i] == true) {

			float xtx = mPosX[i] - posX;
			float yty = mPosY[i] - posY;

			if (sqrtf(xtx * xtx + yty * yty) < mRadius[i] + radius) {
				return true;
			}

		}

	}

	return false;

}

void Bullet::Draw() {

	for (int i = 0; i < 10; i++) {

		if (mIsShot[i] == true) {
			Novice::DrawEllipse(mPosX[i], mPosY[i], mRadius[i], mRadius[i], 0, 0xFFFFFFFF, kFillModeSolid);
		}

	}

}