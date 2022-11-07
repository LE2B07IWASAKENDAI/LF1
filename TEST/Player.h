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

	//‰æ‘œ“Ç‚İ‚İ
	void LoadTexture();


public:
	int ptexture = 0;
	float position_X = 0.0f;   //XÀ•W
	float position_Y = 700.0f; //YÀ•W
	float speed = 7.5f;        //ˆÚ“®‘¬“x
};

