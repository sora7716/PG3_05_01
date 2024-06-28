#pragma once
#include "scene/IScene.h"
class StageScene :public IScene {

public://メンバ関数
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
};

