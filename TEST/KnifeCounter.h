#pragma once
#include"DxLib.h"
#include <vector>

class KnifeCounter
{
public:
	KnifeCounter();
	~KnifeCounter();

	//初期化
	void Initialize();
	//計算
	void Cariculate();
	//毎フレーム更新
	void Update();
	//画像の読み込み
	void LoadTexture();

	void Delete();
	//描画
	void Draw();

	int GetCounter() { return count; }
	void SetCounter(int knifecount) { count = knifecount; }

private:
	int count = 10;
	int ghandle;
	std::vector<int> positionX,positionY;
};