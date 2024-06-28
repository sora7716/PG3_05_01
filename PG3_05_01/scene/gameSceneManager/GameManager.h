#pragma once
#include <memory>
#include "scene/IScene.h"
#include "scene/gameSceneManager/title/TitleScene.h"
#include "scene/gameSceneManager/game/StageScene.h"
#include "scene/gameSceneManager/end/EndScene.h"
class GameManager{

public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameManager();

	/// <summary>
	/// ゲームループ
	/// </summary>
	void Run();

private://メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void InputKeys();

public://静的メンバ変数
	static inline const char kWindowTitle[] = "GC2B_01_イイヅカ_ソラ";
	static inline const int kSceneNum = 3;
private://メンバ変数
	//キーを受け取る箱
	char keys_[IScene::kKeysNums];//現在のキー
	char preKeys_[IScene::kKeysNums];//前のキー

	std::unique_ptr<IScene>sceneArr_[kSceneNum];//シーンを保持するメンバ変数
	int currentSceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン

};

