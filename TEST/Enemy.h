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

	void Set_position(float position_x, float position_y);

	float GetPosition_X();
	float Getposition_Y();

	int GetDeath();
	int SetDeath(int d);
	int GetFlont();

	//画像読み込み
	void LoadTexture();


public:
	int Etexture;
	float position_X = 0.0f;
	float position_Y = 0.0f;
	int death = 0; //生死　0:生きてる 1:死んでる
	int flont = 0;//0:前　1:後ろ
private:
	float speed = 5.0f;
	float speed_ = -5.0f;
	float vector = 0.0f;
	float beforSpeed = 0;
	int eye = 0;
	int count = 0;
	float before_position_X;
	float movement_position_X;
	int trigger;
};