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
	//‰æ‘œ“Ç‚İ‚İ
	DrawGraph(position_X, position_Y, ptexture, FALSE);

	//ˆÚ“®ˆ—
	if (CheckHitKey(KEY_INPUT_A))
	{
		position_X = position_X - speed;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		position_X = position_X + speed;
	}



}

void Player::Draw()
{
}

void Player::LoadTexture()
{
	ptexture = LoadGraph("Resources/Player/green.png");
}
