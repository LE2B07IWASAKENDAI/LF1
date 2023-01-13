#pragma once
#include"DxLib.h"
#include <vector>

class KnifeCounter
{
public:
	KnifeCounter();
	~KnifeCounter();

	//������
	void Initialize();
	//�v�Z
	void Cariculate();
	//���t���[���X�V
	void Update();
	//�摜�̓ǂݍ���
	void LoadTexture();

	void Delete();
	//�`��
	void Draw();

	int GetCounter() { return count; }
	void SetCounter(int knifecount) { count = knifecount; }

private:
	int count = 10;
	int ghandle;
	std::vector<int> positionX,positionY;
};