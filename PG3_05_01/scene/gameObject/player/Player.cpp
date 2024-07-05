#include "Player.h"

//コンストラクタ
Player::Player(){
	position_ = {};
	speed_ = {};
	radius_ = 0.0f;
	color_ = 0u;
}

//デストラクタ
Player::~Player(){
}

//初期化
void Player::Initialize(){
	position_ = { 100,100 };
	speed_ = {};
	radius_ = 30;
	color_ = RED;
}

//更新
void Player::Update(){
	position_ += speed_;
}

//描画
void Player::Draw(){
	Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_,0.0f, color_, kFillModeSolid);
}

//右の動き
void Player::MoveRight(){
	this->speed_.x = kSpeed;
}

//左の動き
void Player::MoveLeft(){
	this->speed_.x = -kSpeed;
}

void Player::SetSpeed(const Vector2& speed){
	speed_ = speed;
}
