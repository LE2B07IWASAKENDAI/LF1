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
	position_Y = 600.0f;
	count = 0;
	speed = 5.f;
}

void Enemy::Update()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(position_X - 250 + vector, position_Y, position_X + 450 + vector, position_Y + 192, GetColor(255, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(position_X + vector, position_Y, Etexture, TRUE);
	count++;
	position_X += speed;


	if (count < 64)
	{
		vector = vector + speed_;
	}
	else  if (count > 65 )
	{
		vector = vector + speed;
		
	}

	if (count == 129)
	{
		count = 0;
	}

	if (count >64)
	{
		flont = 0;
		Etexture = LoadGraph("Resources/Enemy/01_Enemy_R.png");
	}
	else if (count <65)
	{
		flont = 1;
		Etexture = LoadGraph("Resources/Enemy/01_Enemy_L.png");
	}
}

void Enemy::Draw()
{
}

float Enemy::Set_position(float position_x, float position_y)
{
	position_X = position_x;
	position_Y = position_y;

	return 0.0f;
}

float Enemy::GetPosition_X()
{
	
	return position_X + vector;
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