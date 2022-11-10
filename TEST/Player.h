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
	float GetPosition_Y();
	float SetPosition(float x, float y);

	int GetPlayerSizeX() { return size_x; }
	int GetPlayerSizeY() { return size_y; }

	int GetDeath();
	int SetDeath(int d);

	//�摜�ǂݍ���
	void LoadTexture();


public:
	int ptexture = 0;
	float position_X = 0.0f;   //X���W
	float position_Y = 700.0f; //Y���W
	int size_x = 200, size_y = 200;//�v���C���[�摜�̃T�C�Y(11/10�ɒÑ����ǉ� ����ŏ���)
	float speed = 7.5f;        //�ړ����x
	int hide = 0;//�B��� 0:�B��Ȃ� 1:�B���
	int death = 0; //�����@0:�����Ă� 1:����ł�
};