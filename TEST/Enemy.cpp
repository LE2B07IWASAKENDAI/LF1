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
	//position_X = 300.0f;
	//position_Y = 600.0f;
	count = 0;
	speed = 5.f;
	eye = 0;
	flont = 0;
}

void Enemy::Update()
{

	eye = position_X;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//DrawBox(position_X - 250 + vector, position_Y, position_X + 450 + vector, position_Y + 192, GetColor(255, 0, 0), true);
	count++;
	position_X += speed + vector;


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
		DrawBox(eye + vector, position_Y, eye + 450 + vector, position_Y + 192, GetColor(255, 0, 0), true);
	}
	else if (count <65)
	{
		flont = 1;
		Etexture = LoadGraph("Resources/Enemy/01_Enemy_L.png");
		DrawBox(eye - 250 + vector, position_Y, eye + 192 + vector, position_Y + 192, GetColor(255, 0, 0), true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(position_X/* + vector*/, position_Y, Etexture, TRUE);

	DrawFormatString(1607, 180, GetColor(255, 255, 255), "vector + eye : %f", vector + eye);
}

void Enemy::Draw()
{
	DrawGraph(position_X, position_Y, Etexture, TRUE);

}

float Enemy::Set_position(float position_x, float position_y)
{
	position_X = position_x;
	position_Y = position_y;

	return 0.0f;
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