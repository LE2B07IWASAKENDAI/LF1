#pragma once
#include"DxLib.h"
#include <vector>

using namespace std;

class Player
{

public:
	void Initialize();
	void Update();
	void Draw();

	//�摜�ǂݍ���
	void LoadTexture();


public:
	int Ptexture;
	float position_X = 0.0f;
	float position_Y = 700.0f;
};

