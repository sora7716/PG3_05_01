#pragma once
#include <cmath>
#define _USE_MATH_DEFINES
#include <Novice.h>
#include "scene/math/Math.h"
//シーン
enum SCENE {
	Title,
	Game_Stage,
	End,
	SceneNum
};

class IScene {

public://構造体等
	//ベクトル2D
	typedef struct Vector2 {
		float x;
		float y;
	}Vector2;

	//横幅、縦幅
	typedef struct Size {
		float width;
		float height;
	}Size;

	typedef struct GameObject {
		Vector2 position;
		Vector2 velocity;
		Size size;
		uint32_t color;
	}GameObject;
public://メンバ関数

	//純粋仮想関数
	virtual void Initialize() = 0;
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;

	//仮想デストラクタ
	virtual ~IScene();

	//シーンナンバーのゲッター
	int GetSceneNo();
public://静的メンバ変数
	static inline const float kWindowWidth = 1280;//画面の横幅
	static inline const float kWindowHeight = 720;//画面の縦幅
	static inline const int kKeysNums = 256;
protected:
	static int sceneNo_;//シーンナンバーの管理をする
	GameObject gameObject_ = {};//各シーンに出すオブジェクトに使う素材を管理
};
