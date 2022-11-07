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

	float GetPosition_X();
	float SetPosition(float x, float y);

	int GetDeath();
	int SetDeath(int d);

	//‰æ‘œ“Ç‚İ‚İ
	void LoadTexture();


public:
	int ptexture = 0;
	float position_X = 0.0f;   //XÀ•W
	float position_Y = 700.0f; //YÀ•W
	float speed = 7.5f;        //ˆÚ“®‘¬“x
	int hide = 0;//‰B‚ê‚é 0:‰B‚ê‚È‚¢ 1:‰B‚ê‚é
	int death = 0; //¶€@0:¶‚«‚Ä‚é 1:€‚ñ‚Å‚é
};

