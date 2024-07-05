#include "StageScene.h"

StageScene::StageScene(){
	inputHandler_ = nullptr;
	iCommand_ = nullptr;
	player_ = nullptr;
}

StageScene::~StageScene(){
	delete inputHandler_;
	delete iCommand_;
	delete player_;
}

//初期化
void StageScene::Initialize() {
	sceneNo_ = static_cast<int>(SCENE::Game_Stage);
	gameObject_.size = { kWindowWidth,kWindowHeight };
	gameObject_.color = GREEN;

	inputHandler_ = new InputHandler();

	//Assign Command
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyA();

	//New Player
	player_ = new Player();
	player_->Initialize();
}

//更新
void StageScene::Update(char* keys, char* preKeys) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo_ = End;
	}

	//get input
	iCommand_ = inputHandler_->HandleCommand();

	//set command
	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}
	else {
		player_->SetSpeed({});
	}
	player_->Update();
}

//描画
void StageScene::Draw() {
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y, "StageScene");
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y + 20, "PushSpace");
	player_->Draw();
}