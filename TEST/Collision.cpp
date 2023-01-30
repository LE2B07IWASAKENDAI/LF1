#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

float Collision::Found(float playerx, float playery, float enemyx, float enemyy,int flont)
{
	if (flont == 0) {
		if (playerx + character_Size -ad > enemyx - range + ad && playerx < enemyx + character_Size  -ad
			&& playery == enemyy)
		{
			found = 1;
		}
		else
		{
			found = 0;
		}
	}
	else if (flont == 1) {
		if (playerx+ character_Size -ad > enemyx + ad  && playerx < enemyx + character_Size - ad + range)
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

float Collision::FoundXY(float player_X, float player_Y, float enemy_X, float enemy_Y, int flont)
{
	if (flont == 0) {
		if (player_X + character_Size - ad > enemy_X - range + ad && player_X < enemy_X + character_Size -ad && player_Y == enemy_Y)
		{
			found = 1;
		}
		else
		{
			found = 0;
		}
	}
	else if (flont == 1) {
		if (player_X + character_Size -ad > enemy_X + ad && player_X < enemy_X + character_Size - ad  + range && player_Y == enemy_Y)
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
