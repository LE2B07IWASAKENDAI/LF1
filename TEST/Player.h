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

	//画像読み込み
	void LoadTexture();


public:
	int ptexture = 0;
	float position_X = 0.0f;   //X座標
	float position_Y = 700.0f; //Y座標
	float speed = 1.0f;        //移動速度
};

