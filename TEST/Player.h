#pragma once
#include"DxLib.h"
#include <vector>

using namespace std;

class Player
{

public:
	Player();
	~Player();
	void Initialize();
	void Update();
	void Draw();

	int GetHide();
	int SetHide(int sethide);

	float GetPosition_X();
	float GetPosition_Y();
	float SetPosition(float x, float y);

	int GetPlayerSizeX() { return size_x; }
	int GetPlayerSizeY() { return size_y; }

	int GetDeath();
	int SetDeath(int d);

	//画像読み込み
	void LoadTexture();


public:
	int ptexture = 0;
	float position_X = 0.0f;   //X座標
	float position_Y = 700.0f; //Y座標
	int size_x = 200, size_y = 200;//プレイヤー画像のサイズ(11/10に津村が追加 ※後で消去)
	float speed = 7.5f;        //移動速度
	int hide = 0;//隠れる 0:隠れない 1:隠れる
	int death = 0; //生死　0:生きてる 1:死んでる
};