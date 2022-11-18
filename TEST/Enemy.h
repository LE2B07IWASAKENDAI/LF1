#pragma once
#include"DxLib.h"
#include <vector>

using namespace std;

class Enemy
{

public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();

	float Set_position(float position_x, float position_y);

	float GetPosition_X();
	float Getposition_Y();

	int GetDeath();
	int SetDeath(int d);
	int GetFlont();

	//�摜�ǂݍ���
	void LoadTexture();


public:
	int Etexture;
	float position_X = 0.0f;
	float position_Y = 0.0f;
	int death = 0; //�����@0:�����Ă� 1:����ł�
	int flont = 0;//0:�O�@1:���
private:
	float speed = 5.0f;
	float speed_ = -5.0f;
	float vector = 0.0f;
	float beforSpeed = 0;
	int count = 0;
};