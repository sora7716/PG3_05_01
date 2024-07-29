#include "StageScene.h"

StageScene::StageScene() {
	inputHandler_ = nullptr;
	iCommand_ = nullptr;
	player_ = nullptr;
	inputMap_ = nullptr;
}

StageScene::~StageScene() {
	delete inputHandler_;
	delete iCommand_;
	delete player_;
	delete inputMap_;
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

	inputMap_ = new InputMap();
	inputMap_->ReadCSV("resources/map/map.csv");
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

	// バックグラウンドの処理
	thread backgroundUpdate(&InputMap::BackgroundUpdate, inputMap_);

	// メインスレッドの処理

	lock_guard<mutex> lock(inputMap_->exclusive_);
	inputMap_->q_.push(2);
	inputMap_->condition_.notify_one();

	sleep_for(milliseconds(500));

	// 終了処理

	inputMap_->exit_ = true;
	inputMap_->condition_.notify_all();

	backgroundUpdate.join();

	delete inputMap_;
}


//描画
void StageScene::Draw() {
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y, "StageScene");
	Novice::ScreenPrintf((int)gameObject_.position.x, (int)gameObject_.position.y + 20, "PushSpace");
	inputMap_->Draw();
	player_->Draw();
}