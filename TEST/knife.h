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
	void Ready_Throw(float Ppos_X, float Ppos_y,int flont);
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

	void Cariculate();

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
	
	void SetDirection() { if (front == 0)direction = 1; else if (front == 1)direction = -1; }

	//グラフィックハンドル
	int knifetex[2];

	//前向いてるか？
	int front = 0;  //0:前、1:後ろ

private:
	float position_X = 0;//プレイヤーの現在位置から取得する
	float position_Y = 0;

	//変化量
	float vector_x = 0.0f;
	float vector_y = 0.0f;

	//投げているかどうかのフラグ
	int is_throw = 0;

	//ナイフの生存時間
	int life = 100;

	int stock = 10;

	//向いてる方向
	int direction = 0;
};
