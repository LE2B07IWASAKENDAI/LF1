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



}

void Player::Draw()
{
}

void Player::LoadTexture()
{
	ptexture = LoadGraph("Resources/Player/green.png");
}
