#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}


void Player::Initialize()
{
	LoadTexture();
}

void Player::Update()
{
	DrawGraph(position_X, position_Y, Ptexture, FALSE);
}

void Player::Draw()
{
}

void Player::LoadTexture()
{
	Ptexture = LoadGraph("Resources/Player/green.png");
}
