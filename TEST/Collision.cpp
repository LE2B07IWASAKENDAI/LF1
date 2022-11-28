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
	//ナイフの左側
	float knife_L = knife;
	//ナイフの右側
	float knife_R = knife + 64;
	//敵の左側
	float enemy_L = enemy;
	//敵の右側
	float enemy_R = enemy + 192;

	//範囲
	if (knife_L > enemy_R)return 0;
	if (enemy_L > knife_R)return 0;

	//上記以外の条件は当たっている
	return 1;
}

float Collision::KnifetoVase(float knife, float vase)
{
	//ナイフの左側
	float knife_L = knife;
	//ナイフの右側
	float knife_R = knife + 64;
	//敵の左側
	float vase_L = vase;
	//敵の右側
	float vase_R = vase + 128;

	//範囲
	if (knife_L > vase_R)return 0;
	if (vase_L > knife_R)return 0;

	//上記以外の条件は当たっている
	return 1;
}
