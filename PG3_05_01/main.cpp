#include "scene/gameSceneManager/GameManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	//インスタンス
	GameManager* gameManager = new GameManager();
	//ゲームループ
	gameManager->Run();
	//削除
	delete gameManager;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
