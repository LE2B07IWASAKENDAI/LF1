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

	//‰æ‘œ“Ç‚İ‚İ
	void LoadTexture();


public:
	int Etexture;
	float position_X = 1000.0f;
	float position_Y = 600.0f;
	int death = 0; //¶€@0:¶‚«‚Ä‚é 1:€‚ñ‚Å‚é
	int flont = 0;//0:‘O@1:Œã‚ë
private:
	float speed = 5;
	float beforSpeed = 0;
	int count = 0;
};