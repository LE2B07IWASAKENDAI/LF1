#pragma once
#include "DxLib.h" 

class Collision
{
public:
	 Collision();
	 ~Collision();

public:
	float Found(float player, float enemy,int flont); //敵の索敵範囲に入ったか


public:
	int found = 0;//発見　0:見つかっていない 1:見つかった
	float range = 448; //索敵範囲
	float character_Size = 192; //キャラクターサイズ

};

