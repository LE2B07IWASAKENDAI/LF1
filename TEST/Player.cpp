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
	//画像読み込み
	DrawGraph(position_X, position_Y, ptexture, FALSE);

	//移動処理
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
