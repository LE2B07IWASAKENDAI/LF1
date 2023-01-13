#pragma once
#include "DxLib.h" 

class Collision
{
public:
	 Collision();
	 ~Collision();

public:
	float Found(float playerx,float playery, float enemyx,float enemyy, int flont); //敵の索敵範囲に入ったか

	float FoundXY(float player_X, float player_Y, float enemy_X, float enemy_Y, int flont);

	/// <summary>
	/// ナイフと敵
	/// </summary>
	/// <param name="knife">ナイフのX座標</param>
	/// <param name="enemy">敵のX座標</param>
	/// <returns></returns>
	float KnifetoEnemy(float knife, float enemy);

	/// <summary>
	/// ナイフと花瓶？
	/// </summary>
	/// <param name="knife">ナイフ</param>
	/// <param name="vase">花瓶？</param>
	/// <returns></returns>
	float KnifetoVase(float knife, float vase);

public:
	int found = 0;//発見　0:見つかっていない 1:見つかった
	float range = 400; //索敵範囲
	float character_Size = 192; //キャラクターサイズ

};

