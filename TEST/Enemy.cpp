#include "Enemy.h"

//Enemy::Enemy()
//{
//}
//
//Enemy::~Enemy()
//{
//}

void Enemy::Initialize()
{
	LoadTexture();
	float position_X = 1000.0f;
	float position_Y = 700.0f;
	count = 0;
}

void Enemy::Update()
{
	DrawGraph(position_X, position_Y, Etexture, FALSE);
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
}

void Enemy::Draw()
{
}

void Enemy::LoadTexture()
{
	Etexture = LoadGraph("Resources/Enemy/Enemy.png");
}