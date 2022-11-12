#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	LoadTexture();
	position_X = 900.0f;
	position_Y = 640.0f;
	count = 0;
	speed = 8.f;//���x��ς���11/12�Ñ�
}

void Enemy::Update()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//���G�͈�
	DrawBox(position_X - 250, position_Y, position_X + 450, position_Y + 64, GetColor(255, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawGraph(position_X, position_Y, Etexture, TRUE);
	count++;
	position_X += speed;

	if (count == 64)
	{
		beforSpeed = speed;
		speed = 0;
	}
	else if (count == 128)
	{
		speed = beforSpeed;
		speed *= -1;
		count = 0;
	}

	if (speed > 0)
	{
		flont = 0;
		Etexture = LoadGraph("Resources/Enemy/01_Enemy_R_64.png");
	}
	else if (speed < 0)
	{
		flont = 1;
		Etexture = LoadGraph("Resources/Enemy/01_Enemy_L_64.png");
	}
}

void Enemy::Draw()
{
}

float Enemy::GetPosition_X()
{
	return position_X;
}

float Enemy::Getposition_Y()
{
	return position_Y;
}

int Enemy::GetDeath()
{
	return death;
}

int Enemy::SetDeath(int d)
{
	death = d;

	return 0;
}

int Enemy::GetFlont()
{
	return flont;
}

void Enemy::LoadTexture()
{
	Etexture = LoadGraph("Resources/Enemy/01_Enemy_R.png");
}