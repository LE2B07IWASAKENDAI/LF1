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

	//life�̐��l
	void Setlife(int life) { this->life = life; }
	int Getlife() { return life; }

	//���W�u
	float GetPosition() { return position_X; }

private:
	float position_X = 0;//�v���C���[�̌��݈ʒu����擾����
	float position_Y = 0;

	//���x
	float speed = 10.0f;

	//�O���t�B�b�N�n���h��
	int knifetex = 0;

	//�����Ă��邩�ǂ����̃t���O
	int is_throw = 0;

	//�i�C�t�̐�������
	int life = 100;
};
