#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

float Collision::Found(float player, float enemy, int flont)
{
	if (flont == 0) {
		if (player > enemy - range && player < enemy + character_Size)
		{
			found = 1;
		}
		else
		{
			found = 0;
		}
	}
	else if (flont == 1) {
		if (player+ character_Size > enemy  && player < enemy + range)
		{
			found = 1;
		}
		else
		{
			found = 0;
		}
	}

	return found;
}

float Collision::KnifetoEnemy(float knife, float enemy)
{
	//�i�C�t�̍���
	float knife_L = knife;
	//�i�C�t�̉E��
	float knife_R = knife + 64;
	//�G�̍���
	float enemy_L = enemy;
	//�G�̉E��
	float enemy_R = enemy + 192;

	//�͈�
	if (knife_L > enemy_R)return 0;
	if (enemy_L > knife_R)return 0;

	//��L�ȊO�̏����͓������Ă���
	return 1;
}

float Collision::KnifetoVase(float knife, float vase)
{
	//�i�C�t�̍���
	float knife_L = knife;
	//�i�C�t�̉E��
	float knife_R = knife + 64;
	//�G�̍���
	float vase_L = vase;
	//�G�̉E��
	float vase_R = vase + 128;

	//�͈�
	if (knife_L > vase_R)return 0;
	if (vase_L > knife_R)return 0;

	//��L�ȊO�̏����͓������Ă���
	return 1;
}
