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
	position_X = 0.0f;
	position_Y = 700.0f;
	death = 0;
	hide = 0;
}

void Player::Update()
{
	//âÊëúì«Ç›çûÇ›
	DrawGraph(position_X, position_Y, ptexture, FALSE);

	//à⁄ìÆèàóù
	if (CheckHitKey(KEY_INPUT_A))
	{
		position_X = position_X - speed;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		position_X = position_X + speed;
	}
	//âBÇÍÇÈ
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

	return 0;
}

float Player::GetPosition_X()
{
	return position_X;
}

float Player::SetPosition(float x, float y)
{
	position_X = x;
	position_Y = y;

	return 0;
}

int Player::GetDeath()
{
	return death;
}

int Player::SetDeath(int d)
{
	death = d;

	return 0;
}

void Player::LoadTexture()
{
	ptexture = LoadGraph("Resources/Player/green.png");
}
