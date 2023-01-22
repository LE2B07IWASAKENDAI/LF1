#pragma once
#include"DxLib.h"
#include <vector>

#include"knife.h"
#include"Collision.h"
#include"Vase.h"
//#include"MapChip.h"

using namespace std;

class Enemy
{

public:
	Enemy();
	~Enemy();

	//初期化
	void Initialize();
	//移動
	void Movement();
	//視野
	void Horizon();
	//死亡判定処理
	void Dead();
	//毎フレーム更新
	void Update();

	//画像読み込み
	void LoadTexture();
	//描画
	void Draw();
	//デバッグ表示
	void DebugLog();

/*Getter,Setter*/
	//座標値
	void Set_position(float position_x, float position_y);

	float GetPosition_X() { return position_X; }
	float Getposition_Y() { return position_Y; }

	//生死判定
	int GetDeath() { return death; }
	void SetDeath(int d) { death = d; }

	//向いている方向
	int GetFlont() { return flont; }

	void CheckSound();
	void Breaking(float x);
	int Mode;
	enum Mode
	{
		Normal,
		Check,
	};

public:
	//グラフィックハンドル
	int Etexture;
	//座標
	float position_X = 0.0f;
	float position_Y = 0.0f;

	int death = 0; //生死　0:生きている 1:死んでいる
	int flont = 0;//0:後ろ(左)　1:前(右)
private:
	//右、左に進む速度
	float speed = 5.0f;
	float speed_ = -5.0f;
	//移動量
	float vector = 0.0f;
	//停止時間のカウント
	int count = 0;

	//アニメーション
	int walk_L[6];
	int walk_R[6];
	int walk_indec = -1;

	//生成された時の座標
	float before_position_X;
	//初期位置と、現在位置との座標差
	float movement_position_X;
	float BreakPoint = 0;
	int EqualFlag = 0; //0:未到達　1:到達

private:
	Knife* knife;
	Collision* collision;
	Vase* vase;
};