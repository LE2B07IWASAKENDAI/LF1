#pragma once
#include "DxLib.h"
class Title_obj
{
public:
	Title_obj();
	~Title_obj();
	void Initialize();
	void Update();
	void Draw();
	void LoadTexture();

private:
	float position_X = 750.0f;
	float position_Y = 500.0f;
	int obj = 0;
};

