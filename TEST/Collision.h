#pragma once
#include "DxLib.h" 

class Collision
{
public:
	 Collision();
	 ~Collision();

public:
	float Found(float player, float enemy,int flont); //�G�̍��G�͈͂ɓ�������


public:
	int found = 0;//�����@0:�������Ă��Ȃ� 1:��������
	float range = 448; //���G�͈�
	float character_Size = 192; //�L�����N�^�[�T�C�Y

};

