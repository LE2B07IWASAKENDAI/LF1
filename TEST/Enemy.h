#pragma once
#include"DxLib.h"
#include <vector>

using namespace std;

class Enemy
{

public:
	void Initialize();
	void Update();
	void Draw();

	//�摜�ǂݍ���
	void LoadTexture();


public:
	int Etexture;
	float position_X = 1000.0f;
	float position_Y = 700.0f;
};