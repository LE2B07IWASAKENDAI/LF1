#pragma once
#pragma once
#include "DxLib.h";
#include <vector>;

using namespace std;

class Vase
{
public:
	Vase();
	~Vase();

	//初期化
	void Initialize();
	//ナイフ死亡時
	void Break();
	//毎フレーム更新
	void Update();
	//画像の読み込み
	void LoadTexture();
	//描画
	void Draw();

/*Setter,Getter*/
	//生死
	int GetDead() { return dead; }
	void SetDead(int dead) { this->dead = dead; }

	//座標置
	float GetPosition() { return position_X; }
	void SetPosition(float x, float y) { position_X = x, position_Y = y; }

private:
	float position_X = 0;
	float position_Y = 0;

	//グラフィックハンドル
	int gHandle = 0;

	//生存フラグ
	int dead = 0;//0:生きてる,1:死んでる
};
