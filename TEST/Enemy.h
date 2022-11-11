#pragma once
#include"DxLib.h"
#include <vector>

using namespace std;

class Enemy
{

public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();
	
	float GetPosition_X();
	float Getposition_Y();

	int GetDeath();
	int SetDeath(int d);
	int GetFlont();

	//画像読み込み
	void LoadTexture();


public:
	int Etexture;
	float position_X = 1000.0f;
	float position_Y = 600.0f;
	int death = 0; //生死　0:生きてる 1:死んでる
	int flont = 0;//0:前　1:後ろ
private:
	float speed = 5;
	float beforSpeed = 0;
	int count = 0;
};