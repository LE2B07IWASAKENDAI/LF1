#pragma once
#include "DxLib.h"
#include "Timer.h"
#include <vector>
class Title_player
{
public:
	Title_player();
	~Title_player();
	void Initialize();
	void Update();
	void Draw();
	void LoadTexture();
	void Animation();
	void Control(int d);

private:
	float position_X = 0.0f;
	float position_Y = 576.0f;
	float vector = 1.0f;
	float speed = 30.0f;
	int direction = 0; //Œü‚« 0:‰E 1:¶ 2:~‚Ü‚Á‚Ä‚¢‚é

	int texture_R = 0;
	int texture_L = 0;
	int hide_R = 0;
	int hide_L = 0;
	int walk_R[10];
	int walk_L[10];
	int walk_index = 0;
	int anime_time = 0;
	int anime_max = 2;

	float witdh = 1800.0f;

	int pattern_Nuber = 0;
	int count = 0;

	Timer* timer = new Timer();

};

