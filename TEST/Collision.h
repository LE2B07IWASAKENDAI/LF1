#pragma once
#include "DxLib.h" 

class Collision
{
public:
	 Collision();
	 ~Collision();

public:
	float Found(float playerx,float playery, float enemyx,float enemyy, int flont); //�G�̍��G�͈͂ɓ�������

	float FoundXY(float player_X, float player_Y, float enemy_X, float enemy_Y, int flont);

	/// <summary>
	/// �i�C�t�ƓG
	/// </summary>
	/// <param name="knife">�i�C�t��X���W</param>
	/// <param name="enemy">�G��X���W</param>
	/// <returns></returns>
	float KnifetoEnemy(float knife, float enemy);

	/// <summary>
	/// �i�C�t�Ɖԕr�H
	/// </summary>
	/// <param name="knife">�i�C�t</param>
	/// <param name="vase">�ԕr�H</param>
	/// <returns></returns>
	float KnifetoVase(float knife, float vase);

public:
	int found = 0;//�����@0:�������Ă��Ȃ� 1:��������
	float range = 400; //���G�͈�
	float character_Size = 192; //�L�����N�^�[�T�C�Y

};

