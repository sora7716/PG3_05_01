#pragma once
#include "scene/gameObject/command/Command.h"
class InputHandler{
public://メンバ関数

	/// <summary>
	/// 入力処理の集約
	/// </summary>
	/// <returns></returns>
	ICommand* HandleCommand();

	/// <summary>
	/// 左に行くときのキー入力
	/// </summary>
	void AssignMoveLeftCommand2PressKeyA();

	/// <summary>
	/// 右に行くときのキー入力
	/// </summary>
	void AssignMoveRightCommand2PressKeyA();

private://メンバ変数
		ICommand* pressKeyD_;
		ICommand* pressKeyA_;
};

