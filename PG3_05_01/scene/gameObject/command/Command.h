#pragma once
#include <Novice.h>
//前方宣言
class Player;

class ICommand{
public://メンバ関数
	
	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~ICommand();
	virtual void Exec(Player& player) = 0;
};

class MoveRightCommand :public ICommand {
public://メンバ関数

	//右の動くコマンド
	void Exec(Player& player)override;
};

class MoveLeftCommand :public ICommand {
public://メンバ関数
	/// <summary>
	/// 左に動かすコマンド
	/// </summary>
	/// <param name="player"></param>
	void Exec(Player&player)override;
};
