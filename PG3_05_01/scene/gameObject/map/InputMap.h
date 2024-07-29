#pragma once
#include <Novice.h>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

/// <summary>
/// マップの読み込み
/// </summary>
class InputMap {
public://メンバ関数

	/// <summary>
	/// CSVの読み込み
	/// </summary>
	/// <param name="filename"></param>
	void ReadCSV(const std::string& filename);

	/// <summary>
	/// 背景の処理
	/// </summary>
	void BackgroundUpdate();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private://メンバ変数

	vector<vector<string>>map_;//マップ

public://メンバ変数

	//状況変数
	mutex exclusive_;
	condition_variable condition_;
	queue<int>q_;
	bool exit_ = false;

public://静的メンバ変数
	static inline const int kBlockSize = 32;//ブロックのサイズ
	static inline const int kHorizontal = 100;//マップの横幅
	static inline const int kVertical = 20;//マップの縦幅
};

