#include "IScene.h"

//タイトルシーンで初期化
int IScene::sceneNo_ = SCENE::Game_Stage;

//仮想のデストラクタ
IScene::~IScene(){
}

//シーンナンバーのゲッター
int IScene::GetSceneNo(){
    return sceneNo_;
}

