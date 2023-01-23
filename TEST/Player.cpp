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
		if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_D)) {
			if (CheckHitKey(KEY_INPUT_A))
			{
				position_X = position_X - speed;
				rl = 1;
				stop_position = position_X;
				walk_index++;
			}
			else if (CheckHitKey(KEY_INPUT_D))
			{
				position_X = position_X + speed;
				rl = 0;
				stop_position = position_X;
				walk_index++;
			}
		}
		else
		{
			walk_index = -1;
		}
	}

	if (walk_index > 5)
	{
		walk_index = 0;
	}

	//���[�ړ�����
	if (position_X < 0)
	{
		position_X = 0;
	}


	//�B��Ă���Ԃ͍s������
	if (hide == 1 || hide == 2 || hide == 3) {
		SetkeyPermission(true); }

	//���݂̍��W�𕶎���`��
	DrawPlayerPos();

	//�i�C�t�̃N�[���^�C��
	heidCool = knife->GetHiedCool();

////////////////�i�C�t��������////////////////////////////////

	//�G���^�[�������@�i�C�t�ʒu�A�g���K�[�X�V
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && hide == 0)
	{
		keyCounter_knife++;
	}
	else
	{
		if (keyCounter_knife > 0)
		{
			keyCounter_knife = -1;
		}
		else
		{
			keyCounter_knife = 0;
		}
	}

	if (keyCounter_knife == 1)
	{
		//�i�C�t�̔��ˈʒu���Z�b�g
		knife->SetHiedCool(1);
		knife->SetPosition(GetPosition_x() + 100);
		knife->Ready_Throw(GetPosition_x() + 100, GetPosition_Y() + 100 ,rl);
		SetDisapperKnifeTrigger(0);
	}

	if (GetDisapperKnifeTrigger() == 1) {
		knife->Dead();
	}


	SetKnifePos(knife->GetPosition());
	hitFlag = knife->Getis_throw();
}

void Player::Draw()
{
	//�i�C�t�X�V����
	knife->Update();

	//�B��Ă��鎞�ȊO�͕`�悷��
	if (hide == 0 || !GetHide()) {
		//�摜�ǂݍ���

		if (rl == 0) {
			if (position_X >= end)
			{
				return_Positin = position_X - end + center;
				if (walk_index == -1)
				{
					DrawGraph(position_X - end + center, position_Y, ptexture_R, TRUE);
				}
				else
				{
					DrawGraph(position_X - end + center, position_Y, walk_R[walk_index], TRUE);
				}
			}

			else if (position_X >= center)
			{
				return_Positin = center;
				if (walk_index == -1)
				{
					DrawGraph(center, position_Y, ptexture_R, TRUE);
				}
				else
				{
					DrawGraph(center, position_Y, walk_R[walk_index], TRUE);
				}
			}
			else
			{
				return_Positin = position_X;
				if (walk_index == -1)
				{
					DrawGraph(position_X, position_Y, ptexture_R, TRUE);
				}
				else
				{
					DrawGraph(position_X, position_Y, walk_R[walk_index], TRUE);
				}
			}
		}
		else if (rl == 1)
		{
			if (position_X >= end)
			{
				return_Positin = position_X - end + center;
				if (walk_index == -1)
				{
					DrawGraph(position_X - end + center, position_Y, ptexture_L, TRUE);
				}
				else
				{
					DrawGraph(position_X - end + center, position_Y, walk_L[walk_index], TRUE);
				}
			}
			else if (position_X >= center)
			{
				return_Positin = center;
				if (walk_index == -1)
				{
					DrawGraph(center, position_Y, ptexture_L, TRUE);
				}
				else
				{
					DrawGraph(center, position_Y, walk_L[walk_index], TRUE);
				}
			}
			else
			{
				return_Positin = position_X;
				if(walk_index == -1)
				{
					DrawGraph(position_X, position_Y, ptexture_L, TRUE);
				}
				else
				{
					DrawGraph(position_X, position_Y, walk_L[walk_index], TRUE);
				}
			}
		}

		SetkeyPermission(false);
	}
	else if(hide == 1)
	{
		DrawGraph(return_Positin, position_Y - 90, hide_ghandleL, TRUE);
	}
	else if(hide == 2)
	{
		DrawGraph(return_Positin, position_Y - 90, hide_ghandleR, TRUE);
	}
}

bool Player::GetHide()
{
	return hide;
}

void Player::SetHide(bool sethide)
{
	hide = sethide;
}

void Player::Hidding_R()
{
	if (heidCool == 0) {
		//�B���
		if (CheckHitKey(KEY_INPUT_LSHIFT))
		{
			keyCounter++;
		}
		else{
			//�L�[������Ă��Ȃ�
			if (keyCounter > 0)keyCounter = -1;//LSHIFT�L�[�����ꂽ�u��
			else { keyCounter = 0; }           //LSHIFT�L�[������Ă�����
		}

		//�����ꂽ�u�Ԃ̏���
		if (keyCounter == 1 && hide == 0) {
			//�C�X�A���ɉB�ꂽ�Ƃ������o�ŁA�`������Ȃ��悤�ɂ��Ă���
			hide = 1;
		}
		else if (keyCounter == 1 && hide == 1) {
			//�`�悳��Ă��Ȃ�����LSHIFT�����ƁH
			hide = 0;//�v���C���[��`�悷��

			SetkeyPermission(false);
		}
	}
}

void Player::Hidding_L()
{
	if (heidCool == 0) {
		//�B���
		if (CheckHitKey(KEY_INPUT_LSHIFT))
		{
			keyCounter++;
		}
		else {
			//�L�[������Ă��Ȃ�
			if (keyCounter > 0)keyCounter = -1;//LSHIFT�L�[�����ꂽ�u��
			else { keyCounter = 0; }           //LSHIFT�L�[������Ă�����
		}

		//�����ꂽ�u�Ԃ̏���
		if (keyCounter == 1 && hide == 0) {
			//�C�X�A���ɉB�ꂽ�Ƃ������o�ŁA�`������Ȃ��悤�ɂ��Ă���
			hide = 2;
		}
		else if (keyCounter == 1 && hide == 2) {
			//�`�悳��Ă��Ȃ�����LSHIFT�����ƁH
			hide = 0;//�v���C���[��`�悷��

			SetkeyPermission(false);
		}
	}
}

void Player::Hidding_Door()
{
	if (heidCool == 0) {
		//�B���
		if (CheckHitKey(KEY_INPUT_LSHIFT))
		{
			keyCounter++;
		}
		else {
			//�L�[������Ă��Ȃ�
			if (keyCounter > 0)keyCounter = -1;//LSHIFT�L�[�����ꂽ�u��
			else { keyCounter = 0; }           //LSHIFT�L�[������Ă�����
		}

		//�����ꂽ�u�Ԃ̏���
		if (keyCounter == 1 && hide == 0) {
			//���ɉB�ꂽ�Ƃ������o�ŁA�`������Ȃ��悤�ɂ��Ă���
			hide = 3;
		}
		else if (keyCounter == 1 &&  hide == 3) {
			//�`�悳��Ă��Ȃ�����LSHIFT�����ƁH
			hide = 0;//�v���C���[��`�悷��

			SetkeyPermission(false);
		}
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
	ptexture_R = LoadGraph("Resources/Player/Player_R.png");
	ptexture_L = LoadGraph("Resources/Player/Player_L.png");
	hide_ghandleR = LoadGraph("Resources/Player/Assassin_Squat_L.png");
	hide_ghandleL = LoadGraph("Resources/Player/Assassin_Squat_R.png");
	LoadDivGraph("Resources/Player/playerAni_R.png", 6, 6, 1, 192, 192, walk_R);
	LoadDivGraph("Resources/Player/playerAni_L.png", 6, 6, 1, 192, 192, walk_L);
}

void Player::DrawPlayerPos()
{
	//DrawFormatString(1607, 100, GetColor(255, 255, 255), "x���W : %f",GetPosition_X());
	//DrawFormatString(1607, 128, GetColor(255, 255, 255), "y���W : %f",GetPosition_Y());
}