#include "StageScene.h"

//初期化
void StageScene::Initialize() {
	sceneNo_ = static_cast<int>(SCENE::Game_Stage);
	gameObject_.size = { kWindowWidth,kWindowHeight };
	gameObject_.color = GREEN;
	
}

//更新
void StageScene::Update(char* keys, char* preKeys) {
	gameObject_.position += gameObject_.velocity;
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo_ = static_cast<int>(End);
	}
}

//描画
void StageScene::Draw() {
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y, "StageScene");
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y + 20, "PushSpace");
}