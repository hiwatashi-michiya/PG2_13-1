#include <Novice.h>
#include "Key.h"
#include "Enemy.h"
#include "Player.h"

const char kWindowTitle[] = "LC1A_21_ヒワタシミチヤ";

bool Enemy::mIsAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();

	Enemy* enemy1 = new Enemy(30, 300);
	Enemy* enemy2 = new Enemy(130, 500);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Key::Update();

		if (Key::IsTrigger(DIK_R)) {
			enemy1->Reset();
			enemy2->Reset();
		}

		enemy1->Update(player->GetBullet());
		enemy2->Update(player->GetBullet());
		player->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enemy1->Draw();
		enemy2->Draw();
		player->Draw();

		Novice::ScreenPrintf(0, 0, "enemy1 isAlive = %d", enemy1->GetIsAlive());
		Novice::ScreenPrintf(0, 20, "enemy1 isAlive = %d", enemy2->GetIsAlive());
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "SPACE : shot");
		Novice::ScreenPrintf(0, 80, "R : enemy respawn");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
