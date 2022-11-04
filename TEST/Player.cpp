#include "Player.h"

void Player::Initialize()
{
	LoadTexture();
}

void Player::Update()
{
	DrawGraph(poisitio_X, position_Y, texture, FALSE);
}

void Player::Draw()
{
}

void Player::LoadTexture()
{
	texture = LoadGraph("Resources/Player/green.png");
}
