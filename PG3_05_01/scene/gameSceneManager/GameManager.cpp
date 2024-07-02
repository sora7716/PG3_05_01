#include "GameManager.h"

//コンストラクタ
GameManager::GameManager(){
	for (int i = 0; i < IScene::kKeysNums; i++) {
		keys_[i] = 0;
		preKeys_[i] = 0;
	}
	for (int i = 0; i < kSceneNum; i++) {
		sceneArr_[i] = 0;
	}
	currentSceneNo_ = 0;
	prevSceneNo_ = 0;
}

//デストラクタ
GameManager::~GameManager(){
}

//ゲームループ
void GameManager::Run(){
	Initialize();//初期化
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		InputKeys();//キーを受け取る
		//シーンチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();
		//シーンの変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}
		//更新処理
		sceneArr_[currentSceneNo_]->Update(keys_, preKeys_);//シーンごとの更新処理
		//描画処理
		sceneArr_[currentSceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys_[DIK_ESCAPE] == 0 && keys_[DIK_ESCAPE] != 0) {
			break;
		}
	}
}

//初期化
void GameManager::Initialize(){
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, (int)IScene::kWindowWidth, (int)IScene::kWindowHeight);

	sceneArr_[Title] = std::make_unique<TitleScene>();//タイトル
	sceneArr_[Game_Stage] = std::make_unique<StageScene>();//ステージ
	sceneArr_[End] = std::make_unique<EndScene>();//エンド
	currentSceneNo_ = static_cast<int>(Title);
}

//更新
void GameManager::InputKeys(){
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}
