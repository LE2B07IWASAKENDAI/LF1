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
	//隠れる
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		hide = 1;
	}
	else
	{
		hide = 0;
	}


}

void Player::Draw()
{
}

int Player::GetHide()
{
	return hide;
}

int Player::SetHide(int sethide)
{
	hide = sethide;
}

float Player::getPosition_X()
{
	return position_X;
}

float Player::setPosition(float x, float y)
{
	position_X = x;
	position_Y = y;
}

void Player::LoadTexture()
{
	ptexture = LoadGraph("Resources/Player/green.png");
}
