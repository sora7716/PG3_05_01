#include "IScene.h"

//タイトルシーンで初期化
int IScene::sceneNo_ = SCENE::Title;

//仮想のデストラクタ
IScene::~IScene(){
}

//シーンナンバーのゲッター
int IScene::GetSceneNo(){
    return sceneNo_;
}

const IScene::Vector2 operator+=(const IScene::Vector2& v1, const IScene::Vector2& v2) {
	IScene::Vector2 result{};
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return result;
}

