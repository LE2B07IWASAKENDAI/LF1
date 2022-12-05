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
	position_Y = 576.0f;
	death = 0;
	hide = 0;
	//drawPlayer = false;//�B��Ă���Ƃ��͕`�悵�Ȃ�
	keyPermission = false;
	keyCounter = 0;
	SetkeyPermission(false);

	/*�i�C�t�֘A*/
		knife = new Knife();
		//������
		knife->Initialize();
		hitFlag = 0;
		diaspper_knife_trigger = 0;
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

	//�B��Ă��鎞�ȊO�͕`�悷��
	if (hide == 0 || !GetHide()) {
		//�摜�ǂݍ���
		
		if(position_X >= end )
		{
			return_Positin = position_X - end + center;
			DrawGraph(position_X - end + center, position_Y, ptexture, FALSE);
		}
		else if (position_X >= center)
		{
			return_Positin = center;
			DrawGraph(center, position_Y, ptexture, FALSE);
		}
		else
		{
			return_Positin = position_X;
			DrawGraph(position_X, position_Y, ptexture, FALSE);
		}
		
		SetkeyPermission(false);
	}

	//�B��Ă�I�̕`��
	if (hide == 1) { DrawGraph(1602, 0, hidetext, FALSE); SetkeyPermission(true); }
	//���݂̍��W�𕶎���`��
	DrawPlayerPos();


////////////////�i�C�t��������////////////////////////////////

	//�G���^�[�������@�i�C�t�ʒu�A�g���K�[�X�V
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && hide == 0)
	{
		//�i�C�t�̔��ˈʒu���Z�b�g
		knife->Ready_Throw(GetPosition_x() + 100, GetPosition_Y() + 50);
		SetDisapperKnifeTrigger(0);
	}	

	if (GetDisapperKnifeTrigger() == 1) {
		knife->Dead();
	}

	//�i�C�t�X�V����
	knife->Update();

	SetKnifePos(knife->GetPosition());
	hitFlag = knife->Getis_throw();
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
	if (keyCounter == 1 && hide == 0) {
		//���ɉB�ꂽ�Ƃ������o�ŁA�`������Ȃ��悤�ɂ��Ă���
		hide = 1;
	}
	else if (keyCounter == 1 && hide == 1) {
		//�`�悳��Ă��Ȃ�����LSHIFT�����ƁH
		hide = 0;//�v���C���[��`�悷��
		SetkeyPermission(false);
	}
}

float Player::GetPosition_X()
{
	return position_X;
}

float Player::GetPosition_x()
{
	return return_Positin;
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