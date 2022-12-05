#pragma once
#include "DxLib.h";
#include <vector>;

using namespace std;

class Knife
{
public:
	Knife();
	~Knife();

	//初期化
	void Initialize();
	//投げるボタンを押したら位置とフラグを更新
	void Ready_Throw(float Ppos_X, float Ppos_y);
	//投げた後の挙動
	void Throw();
	//ナイフ死亡時
	void Dead();
	//毎フレーム更新
	void Update();
	//画像の読み込み
	void LoadTexture();
	//描画
	void Draw();

/*Setter,Getter*/

	//is_throwフラグ
	void Setis_throw(int flag) { is_throw = flag; }
	int Getis_throw() { return is_throw; }

	//frontフラグ
	void Setfront(int flag) { front = flag; }
	int Getfront() { return front; }

	//lifeの数値
	void Setlife(int life) { this->life = life; }
	int Getlife() { return life; }

	//座標置
	float GetPosition() { return position_X; }

	//グラフィックハンドル
	int knifetexR = 0;
	int knifetexL = 0;

	//前向いてるか？
	int front = 0;  //0:前、1:後ろ

	int Counter = 0;

private:
	float position_X = 0;//プレイヤーの現在位置から取得する
	float position_Y = 0;

	//速度
	float speed = 10.0f;

	//投げているかどうかのフラグ
	int is_throw = 0;

	//ナイフの生存時間
	int life = 100;
};
