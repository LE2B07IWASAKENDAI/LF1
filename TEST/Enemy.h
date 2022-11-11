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
	
	float GetPosition_X();
	float Getposition_Y();

	int GetDeath();
	int SetDeath(int d);

	//�摜�ǂݍ���
	void LoadTexture();


public:
	int Etexture;
	float position_X = 1000.0f;
	float position_Y = 700.0f;
	int death = 0; //�����@0:�����Ă� 1:����ł�
private:
	float speed = 5;
	int count = 0;
};