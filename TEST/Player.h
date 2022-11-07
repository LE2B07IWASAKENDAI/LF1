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

	float getPosition_X();
	float setPosition(float x, float y);

	//画像読み込み
	void LoadTexture();


public:
	int ptexture = 0;
	float position_X = 0.0f;   //X座標
	float position_Y = 700.0f; //Y座標
	float speed = 7.5f;        //移動速度
	int hide = 0;//隠れる 0:隠れない 1:隠れる　
};

