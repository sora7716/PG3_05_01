#include "TitleScene.h"

//初期化
void TitleScene::Initialize(){
	sceneNo_ = static_cast<int>(SCENE::Title);
	gameObject_.size = { 100,100 };
	gameObject_.color = WHITE;
	

}

//更新
void TitleScene::Update(char* keys, char* preKeys){
	gameObject_.position += gameObject_.velocity;
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo_ = static_cast<int>(Game_Stage);
	}
}

//描画
void TitleScene::Draw(){
	
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y, "TitleScene");
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y+20, "PushSpace");
}
