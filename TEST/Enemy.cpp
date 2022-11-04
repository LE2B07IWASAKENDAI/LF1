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
}

void Enemy::Update()
{
	DrawGraph(position_X, position_Y, Etexture, FALSE);
}

void Enemy::Draw()
{
}

void Enemy::LoadTexture()
{
	Etexture = LoadGraph("Resources/Enemy/Enemy.png");
}