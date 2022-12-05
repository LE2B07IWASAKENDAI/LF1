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
	void Ready_Throw(float Ppos_X, float Ppos_y);
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

	//�O���t�B�b�N�n���h��
	int knifetexR = 0;
	int knifetexL = 0;

	//�O�����Ă邩�H
	int front = 0;  //0:�O�A1:���

	int Counter = 0;

private:
	float position_X = 0;//�v���C���[�̌��݈ʒu����擾����
	float position_Y = 0;

	//���x
	float speed = 10.0f;

	//�����Ă��邩�ǂ����̃t���O
	int is_throw = 0;

	//�i�C�t�̐�������
	int life = 100;
};
