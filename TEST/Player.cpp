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
	//�摜�ǂݍ���
	DrawGraph(position_X, position_Y, ptexture, FALSE);

	//�ړ�����
	if (CheckHitKey(KEY_INPUT_A))
	{
		position_X = position_X - speed;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		position_X = position_X + speed;
	}
	//�B���
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

float Player::getPosition_X()
{
	return position_X;
}

float Player::setPosition(float x, float y)
{
	position_X = x;
	position_Y = y;

	return 0;
}

void Player::LoadTexture()
{
	ptexture = LoadGraph("Resources/Player/green.png");
}
