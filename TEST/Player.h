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

	//�摜�ǂݍ���
	void LoadTexture();


public:
	int ptexture = 0;
	float position_X = 0.0f;   //X���W
	float position_Y = 700.0f; //Y���W
	float speed = 7.5f;        //�ړ����x
	int hide = 0;//�B��� 0:�B��Ȃ� 1:�B���@
};

