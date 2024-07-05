#pragma once
#include <Novice.h>
#include "scene/math/Math.h"
#include <cmath>
#define _USE_MATH_DEFINES
//プレイヤークラス
class Player{

public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 右の動き
	/// </summary>
	void MoveRight();

	/// <summary>
	/// 左の動き
	/// </summary>
	void MoveLeft();

	/// <summary>
	/// スピードのセッター
	/// </summary>
	void SetSpeed(const Vector2& speed);

public://静的メンバ変数
	static inline const float kSpeed = 5.0f;
private://メンバ変数
	Vector2 position_;
	float radius_;
	Vector2 speed_;
	uint32_t color_;
};

