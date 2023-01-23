#include "Player.h"
#include <Novice.h>
#include "Key.h"

Player::Player()
{
	mPosX = 640;
	mPosY = 600;
	mRadius = 50;
	mSpeed = 5;
	bullet = new Bullet();

}

Player::~Player()
{
	delete bullet;
}

void Player::Update() {

	bullet->Update();

	if (Key::IsTrigger(DIK_SPACE)) {

		bullet->SetBullet(mPosX, mPosY);

	}

	if (Key::IsPress(DIK_W)) {
		mPosY -= mSpeed;
	}

	if (Key::IsPress(DIK_A)) {
		mPosX -= mSpeed;
	}

	if (Key::IsPress(DIK_S)) {
		mPosY += mSpeed;
	}

	if (Key::IsPress(DIK_D)) {
		mPosX += mSpeed;
	}

}

void Player::Draw() {
	bullet->Draw();
	Novice::DrawEllipse(mPosX, mPosY, mRadius, mRadius, 0, 0x00FF00FF, kFillModeSolid);
}
