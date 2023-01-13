#pragma once
#include "DxLib.h"
#include <vector>
class Title_plaayer
{
public:
	Title_plaayer();
	~Title_plaayer();
	void Initialize();
	void Update();
	void Draw();
	void LoadTexture();

private:
	float position_X;
	float position_Y;
	float vector = 1.0f;
	float speed = 30.0f;

	int texture_R = 0;
	int texture_L = 0;
	int walk_R[10];
	int walk_L[10];

	float witdh = 1800.0f;

	int pattern_Nuber = 0;

};

