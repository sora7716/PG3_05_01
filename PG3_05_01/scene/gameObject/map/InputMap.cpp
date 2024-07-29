#include "InputMap.h"
#include <iostream>
#include <fstream>
#include <sstream>


//CSVの読み込み
void InputMap::ReadCSV(const string& filename) {
	vector<vector<string>> data;
	ifstream file(filename);

	if (!file.is_open()) {
		cerr << "Could not open the file!" << endl;
		map_ = data;
	}

	string line;
	while (getline(file, line)) {
		vector<string> row;
		stringstream ss(line);
		string cell;

		while (getline(ss, cell, ',')) {
			row.push_back(cell);
		}
		data.push_back(row);
	}
	file.close();
	map_ = data;
}

void InputMap::BackgroundUpdate(){
	while (true) {
		{
			std::unique_lock<mutex> uniqueLock(exclusive_);
			condition_.wait(uniqueLock, [&]() { return !q_.empty() || exit_; });

			if (exit_ && q_.empty()) {
				break; // exitがtrueであり、キューが空の場合、ループを終了
			}

			if (!q_.empty()) {
				q_.pop();
				cout << "Processed a task" << endl;
			}
		}
		std::this_thread::sleep_for(milliseconds(2000));
	}
}

void InputMap::Draw() {
	for (int i = 0; i < kVertical; i++) {
		for (int j = 0; j < kHorizontal; j++) {
			if (map_[i][j] == "1") {
				Novice::DrawBox(kBlockSize * j, kBlockSize * i, kBlockSize, kBlockSize, 0.0f, BLACK, kFillModeWireFrame);//外枠
				Novice::DrawBox(kBlockSize * j, kBlockSize * i, kBlockSize, kBlockSize, 0.0f, WHITE, kFillModeSolid);//中身
			}
		}
	}
}


