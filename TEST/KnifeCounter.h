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
	//毎フレーム更新
	void Update();
	//画像の読み込み
	void LoadTexture();

	//数を減らす
	void DisCount();

	//描画
	void Draw();
	void AlwaysDraw();

	int GetCounter() { return count; }
	void SetCounter(int knifecount) { count = knifecount; }

private:
	int count = 5;
	int ghandle[6];
	int gh_knife;
	int gh_x;

	//ghandle[6]の位置
	int positionX,positionY;
	//gh_knifeの位置
	int positionX_k, positionY_k;
	//gh_x
	int positionX_x, positionY_y;
};