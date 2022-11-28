#pragma once
#pragma once
#include "DxLib.h";
#include <vector>;

using namespace std;

class Vase
{
public:
	Vase();
	~Vase();

	//������
	void Initialize();
	//�i�C�t���S��
	void Break();
	//���t���[���X�V
	void Update();
	//�摜�̓ǂݍ���
	void LoadTexture();
	//�`��
	void Draw();

/*Setter,Getter*/
	//����
	int GetDead() { return dead; }
	void SetDead(int dead) { this->dead = dead; }

	//���W�u
	float GetPosition() { return position_X; }
	void SetPosition(float x, float y) { position_X = x, position_Y = y; }

private:
	float position_X = 0;
	float position_Y = 0;

	//�O���t�B�b�N�n���h��
	int gHandle = 0;

	//�����t���O
	int dead = 0;//0:�����Ă�,1:����ł�
};
