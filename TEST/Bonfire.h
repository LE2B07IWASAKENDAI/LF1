#pragma once
#include "DxLib.h"
class Bonfire
{
public:
	Bonfire();
	~Bonfire();

	//初期化
	void Initialize();
	//毎フレーム更新
	void Update();
	//画像の読み込み
	void LoadTexture();
	//描画
	void Draw();

	/*Setter,Getter*/

	//座標置
	float GetPosition() { return position_X; }
	void SetPosition(float x, float y) { position_X = x, position_Y = y; }

private:
	float position_X = 0;
	float position_Y = 0;

	//グラフィックハンドル
	int gHandle = 0;

};

