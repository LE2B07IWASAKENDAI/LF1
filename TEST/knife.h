#pragma once
#include "DxLib.h";
#include <vector>;

using namespace std;

class Knife
{
public:
	Knife();
	~Knife();

	//������
	void Initialize();
	//������{�^������������ʒu�ƃt���O���X�V
	void Ready_Throw(float Ppos_X, float Ppos_y,int flont);
	//��������̋���
	void Throw();
	//�i�C�t���S��
	void Dead();
	//���t���[���X�V
	void Update();
	//�摜�̓ǂݍ���
	void LoadTexture();
	//�`��
	void Draw();

	void Cariculate();

/*Setter,Getter*/

	//is_throw�t���O
	void Setis_throw(int flag) { is_throw = flag; }
	int Getis_throw() { return is_throw; }

	//front�t���O
	void Setfront(int flag) { front = flag; }
	int Getfront() { return front; }

	//life�̐��l
	void Setlife(int life) { this->life = life; }
	int Getlife() { return life; }

	//���W�u
	float GetPosition() { return position_X; }
	
	void SetDirection() { if (front == 0)direction = 1; else if (front == 1)direction = -1; }

	//�O���t�B�b�N�n���h��
	int knifetex[2];

	//�O�����Ă邩�H
	int front = 0;  //0:�O�A1:���

private:
	float position_X = 0;//�v���C���[�̌��݈ʒu����擾����
	float position_Y = 0;

	//�ω���
	float vector_x = 0.0f;
	float vector_y = 0.0f;

	//�����Ă��邩�ǂ����̃t���O
	int is_throw = 0;

	//�i�C�t�̐�������
	int life = 100;

	int stock = 10;

	//�����Ă����
	int direction = 0;
};
