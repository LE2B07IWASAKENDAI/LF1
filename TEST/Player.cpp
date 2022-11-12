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
	position_Y = 600.0f;
	death = 0;
	hide = 0;
	notDrawPlayer = false;//�B��Ă���Ƃ��͕`�悵�Ȃ�
	keyPermission = false;
	keyCounter = 0;
	SetkeyPermission(false);
}

void Player::Update()
{

	//�ړ�����(�B��Ă��Ȃ��Ƃ�)
	if (!GetkeyPermission()) {
		if (CheckHitKey(KEY_INPUT_A))
		{
			position_X = position_X - speed;
		}
		if (CheckHitKey(KEY_INPUT_D))
		{
			position_X = position_X + speed;
		}
	}

	//True�Ȃ�B���Ƃ����֐����Ăт����B
	if (GetHide()) { Hidding(); }

	//�B��Ă��鎞�ȊO�͕`�悷��
	if (!notDrawPlayer || !GetHide()) {
		//�摜�ǂݍ���
		DrawGraph(position_X, position_Y, ptexture, FALSE);
		SetkeyPermission(false);
	}

	//�B��Ă�I�̕`��
	if(notDrawPlayer){ DrawGraph(1602, 0, hidetext, FALSE); SetkeyPermission(true);}
	//���݂̍��W�𕶎���`��
	DrawPlayerPos();
}

void Player::Draw()
{
}

bool Player::GetHide()
{
	return hide;
}

void Player::SetHide(bool sethide)
{
	hide = sethide;
}

void Player::Hidding()
{
	//�B���
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		keyCounter++;
	}
	else
	{
		//�L�[������Ă��Ȃ�
		if (keyCounter > 0)keyCounter = -1;//LSHIFT�L�[�����ꂽ�u��
		else { keyCounter = 0; }           //LSHIFT�L�[������Ă�����
	}

		//�����ꂽ�u�Ԃ̏���
		if (keyCounter == 1 && notDrawPlayer) {
			//���ɉB�ꂽ�Ƃ������o�ŁA�`������Ȃ��悤�ɂ��Ă���(11/11)
			notDrawPlayer = false;
		}
		else if (keyCounter == 1 && !notDrawPlayer) {
			//�`�悳��Ă��Ȃ�����LSHIFT�����ƁH
			notDrawPlayer = true;//�v���C���[��`�悷��
			SetkeyPermission(false);
		}
}

float Player::GetPosition_X()
{
	return position_X;
}

float Player::GetPosition_Y()
{
	return position_Y;
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
	hidetext = LoadGraph("Resources/Player/hidding2.png");
}

void Player::DrawPlayerPos()
{
	DrawFormatString(1607, 100, GetColor(255, 255, 255), "x���W : %f",GetPosition_X());
	DrawFormatString(1607, 128, GetColor(255, 255, 255), "y���W : %f",GetPosition_Y());
}