#pragma once

#include"DxLib.h"
#include"E_Light.h"

class StopEnemy
{
public:
	StopEnemy();
	~StopEnemy();

	//初期化
	void Initialize();
	//視野
	void Horizon();
	//死亡判定処理
	void Dead();
	//毎フレーム更新
	void Update();
	//監視
	void Monitoring();
	void DeadAnime();
	void DeadAnimeSet(float x, float y);

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
		Back,
	};

public:
	//グラフィックハンドル
	int StopEtexture;
	//座標
	float position_X = 0.0f;
	float position_Y = 0.0f;

	int death = 0; //生死　0:生きている 1:死んでいる
	int flont = 0;//0:前　1:後ろ
	//生成時の位置
	float before_position_X;
	float BreakPoint = 0;
	int EqualFlag = 0; //0:未到達　1:到達

private:
	//右、左に進む速度
	float speed = 5.0f;
	float speed_ = -5.0f;
	//移動量
	float vector = 0.0f;
	//振り向きのカウント
	float count = 0;
	//チェック用カウント
	float checkCount = 0;

	//死亡アニメーション
	int death_anime = 0;
	int death_indec = 0;
	float death_x = 0.0f;
	float death_y = 0.0f;
	float death_X = 0.0f;
	float death_Y = 0.0f;
	float death_speedX = 0.1f;
	float death_Xvector = 0;
	float death_speedY = 0.5f;
	float death_Yvector = 0;
	int deathX_LR = 0;
	float a = 100;

private:
	E_Light* light;
};