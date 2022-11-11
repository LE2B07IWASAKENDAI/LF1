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
	position_X = 1000.0f;
	position_Y = 700.0f;
	count = 0;
	speed = 5.f;
}

void Enemy::Update()
{
	DrawGraph(position_X, position_Y, Etexture, FALSE);
	count++;
	position_X += speed;

	if (count == 64)
	{
		speed *= -1;
		count = 0;
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

void Enemy::LoadTexture()
{
	Etexture = LoadGraph("Resources/Enemy/Enemy.png");
}