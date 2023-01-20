#include "knife.h"

#define PI 3.1415926535897932384626433832795f

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
	position_X = 0;
	position_Y = 0;
	vector_x = 15.0f;
	vector_y = 1.05f;
	front = 0;
	stock = 5;
	knifeCounter->Initialize();
}

void Knife::Ready_Throw(float Ppos_x, float Ppos_y,int flont)
{
	//�i�C�t����ʓ��ɖ������
	if (Getis_throw() == 0) {

		//�v���C���[�̌��݈ʒu�i�[
		position_X = Ppos_x;
		position_Y = Ppos_y;

		//�X�V�F�i�C�t����ʓ��ɂ���

		is_throw = 1;
	}
	front = flont;
	SetDirection();

}

void Knife::Throw()
{
	if (front == 0) {
		//�E�ɂƂ�ł�
		position_X = position_X + vector_x;
		position_Y += vector_y;
		
	}
	else if (front == 1) {
		position_X = position_X - vector_x;
		position_Y += vector_y;
		
	}

	//�������Ԃ����炷
	distance = position_X - position;
	
}

void Knife::Dead()
{
	//���Z�b�g
	//���C�t
	position = 0.0f;
	distance = 0.0f;
	//������t���O
	timer->startTimer();
	is_throw = 2;
	//�ʒu
	position_X = 0;
	//�c�@
	stock--;
	if (stock <= 0)
	{
		is_throw = -1;
		stock = 0;
	}
	knifeCounter->Delete();

}

void Knife::Update()
{
	timer->Update();
	counter++;
	if (is_throw == 1) {
		Throw();
		if (front == 0)
		{
			distance >= point ? Dead() : Draw();
		}
		else if(front ==1 )
		{
			distance <= _point ? Dead() : Draw();
		}
	}
	if (timer->elapsedTimer() >= 4000 && is_throw ==2)
	{
		timer->reset();
		is_throw = 0;
	}

	if (timer->elapsedTimer() >= 3000 && is_throw == 2)
	{
		heidCool = 0;
	}

	if (is_throw != 0) {
		if (counter % 10 != 0) {
			knifeCounter->Draw();
		}
	}
	else {
		knifeCounter->Draw();
		counter = 0;
	}

	//DrawFormatString(0, 225, GetColor(255, 255, 255), "stock : %d", stock);
	//DrawFormatString(0, 250, GetColor(255, 255, 255), "position_X : %f", GetPosition());
}

void Knife::Draw()
{	
	//�E����
	DrawRotaGraph(position_X, position_Y, 1.0f, PI * (1 / 4 * (float)direction), knifetex[front], TRUE);
}

void Knife::Cariculate()
{
}

float Knife::SetPosition(float x)
{
	position = x;
	return 0.0f;
}

void Knife::LoadTexture()
{
	knifetex[0] = LoadGraph("Resources/Player/ThrowingKnife.png");
	knifetex[1] = LoadGraph("Resources/Player/ThrowingKnife_copy.png");
}
