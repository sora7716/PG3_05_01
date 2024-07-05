#include "Command.h"
#include "scene/gameObject/player/Player.h"
//仮想デストラクタ
ICommand::~ICommand(){
}

//右に動くコマンド
void MoveRightCommand::Exec(Player& player){
	player.MoveRight();
}

//左に動かすコマンド
void MoveLeftCommand::Exec(Player& player){
	player.MoveLeft();
}
