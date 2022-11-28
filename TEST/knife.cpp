#include "knife.h"

Knife::Knife()
{
}

Knife::~Knife()
{
}

void Knife::Initialize()
{
	LoadTexture();
	is_throw = 0;
	life = 100;
	position_X = 0;
	position_Y = 0;
	speed = 10.0f;
}

void Knife::Ready_Throw(float Ppos_x, float Ppos_y)
{
	//�i�C�t����ʓ��ɖ������
	if (Getis_throw() == 0) {

		//�v���C���[�̌��݈ʒu�i�[
		position_X = Ppos_x;
		position_Y = Ppos_y;

		//�X�V�F�i�C�t����ʓ��ɂ���
		is_throw = 1;
	}
}

void Knife::Throw()
{
	//�E�����։��Z
	position_X += speed;
	//�������Ԃ����炷
	life--;
}

void Knife::Dead()
{
//���Z�b�g
	//���C�t
	life = 100;
	//������t���O
	is_throw = 0;
	//�ʒu
	position_X = 0;
}

void Knife::Update()
{
	if (is_throw == 1) {
		Throw();
		//life��0�ȏ�Ȃ�`�悻��ȊO�͎��S����
		life >= 0 ? Draw() : Dead();
	}
	DrawFormatString(0, 200, GetColor(255, 255, 255), "life : %d", life);
	DrawFormatString(0, 250, GetColor(255, 255, 255), "position : %f", GetPosition());
}

void Knife::Draw()
{
	DrawGraph(position_X,position_Y, knifetex, TRUE);
}

void Knife::LoadTexture()
{
	knifetex = LoadGraph("Resources/Player/Knife.png");
}
