#pragma once
#include "scene/IScene.h"
#include "scene/gameObject/player/Player.h"
#include "scene/gameObject/command/inputHandle/InputHandler.h"
class StageScene :public IScene {

public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	StageScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~StageScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update(char* keys, char* preKeys)override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw()override;

private://メンバ変数
	InputHandler* inputHandler_;
	ICommand* iCommand_;
	Player* player_;
};

