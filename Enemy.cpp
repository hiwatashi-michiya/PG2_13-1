#include "Enemy.h"
#include <Novice.h>
#include "Bullet.h"

Enemy::Enemy(int posX, int posY)
{
	mIsAlive = true;
	mPosX = posX;
	mPosY = posY;
	mRadius = 20;
	mSpeed = -5;
}

Enemy::~Enemy()
{
}

void Enemy::Reset() {
	mIsAlive = true;
}

void Enemy::Update(Bullet bullet) {

	if (mIsAlive == true) {

		mPosX += mSpeed;

		if (mPosX - mRadius < 0 || mPosX + mRadius > 1280) {
			mSpeed *= -1;
		}

		if (bullet.isHitBullet(mPosX, mPosY, mRadius) == true) {
			mIsAlive = false;
		}

	}

}

void Enemy::Draw() {

	if (mIsAlive == true) {
		Novice::DrawEllipse(mPosX, mPosY, mRadius, mRadius, 0, 0xFF0000FF, kFillModeSolid);
	}

}

