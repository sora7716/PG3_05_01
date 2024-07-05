#include "InputHandler.h"

//入力処理の集約
ICommand* InputHandler::HandleCommand(){
    if (Novice::CheckHitKey(DIK_D)) {
        return pressKeyD_;
    }
    else if (Novice::CheckHitKey(DIK_A)) {
        return pressKeyA_;
    }
    return nullptr;
}

//左に行くときのキー入力
void InputHandler::AssignMoveLeftCommand2PressKeyA(){
    ICommand* command = new MoveLeftCommand();
    this->pressKeyA_ = command;
}

//右に行くときのキー入力
void InputHandler::AssignMoveRightCommand2PressKeyA(){
    ICommand* command = new MoveRightCommand();
    this->pressKeyD_ = command;
}
