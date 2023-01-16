#pragma once
#include "DxLib.h"
class Bonfire
{
public:
	Bonfire();
	~Bonfire();

	//������
	void Initialize();
	//���t���[���X�V
	void Update();
	//�摜�̓ǂݍ���
	void LoadTexture();
	//�`��
	void Draw();

	/*Setter,Getter*/

	//���W�u
	float GetPosition() { return position_X; }
	void SetPosition(float x, float y) { position_X = x, position_Y = y; }

private:
	float position_X = 0;
	float position_Y = 0;

	//�O���t�B�b�N�n���h��
	int gHandle = 0;

};

