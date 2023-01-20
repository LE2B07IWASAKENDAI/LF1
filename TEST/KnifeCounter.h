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
	//���t���[���X�V
	void Update();
	//�摜�̓ǂݍ���
	void LoadTexture();

	//�������炷
	void DisCount();

	//�`��
	void Draw();
	void AlwaysDraw();

	int GetCounter() { return count; }
	void SetCounter(int knifecount) { count = knifecount; }

private:
	int count = 5;
	int ghandle[6];
	int gh_knife;
	int gh_x;

	//ghandle[6]�̈ʒu
	int positionX,positionY;
	//gh_knife�̈ʒu
	int positionX_k, positionY_k;
	//gh_x
	int positionX_x, positionY_y;
};