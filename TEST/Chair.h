#pragma once
#include "DxLib.h";

class Chair
{
public:

	Chair();
	~Chair();

	//������
	void Initialize();
	//���t���[���X�V
	void Update();
	//�摜�̓ǂݍ���
	void LoadTexture();
	//�`��
	void Draw();

	//���W�u
	float GetPosition() { return position_X; }
	void SetPosition(float x, float y) { position_X = x, position_Y = y; }

private:

	float position_X = 0;
	float position_Y = 0;

	//�O���t�B�b�N�n���h��
	int gHandle = 0;
};

