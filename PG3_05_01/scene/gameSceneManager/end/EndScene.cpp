#include "EndScene.h"

//初期化
void EndScene::Initialize() {
	sceneNo_ = static_cast<int>(SCENE::End);
	gameObject_.size = { kWindowWidth,kWindowHeight };
	gameObject_.color = BLACK;
}

//更新
void EndScene::Update(char* keys, char* preKeys) {
	gameObject_.position += gameObject_.velocity;
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo_ = static_cast<int>(Title);
	}
}

//描画
void EndScene::Draw() {
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y, "EndScene");
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y + 20, "PushSpace");
}