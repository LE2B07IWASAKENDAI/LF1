#pragma once

#include"DxLib.h"
#include"E_Light.h"

class StopEnemy
{
public:
	StopEnemy();
	~StopEnemy();

	//������
	void Initialize();
	//����
	void Horizon();
	//���S���菈��
	void Dead();
	//���t���[���X�V
	void Update();
	//�Ď�
	void Monitoring();
	void DeadAnime();
	void DeadAnimeSet(float x, float y);

	//�摜�ǂݍ���
	void LoadTexture();
	//�`��
	void Draw();
	//�f�o�b�O�\��
	void DebugLog();

	/*Getter,Setter*/
	//���W�l
	void Set_position(float position_x, float position_y);

	float GetPosition_X() { return position_X; }
	float Getposition_Y() { return position_Y; }

	//��������
	int GetDeath() { return death; }
	void SetDeath(int d) { death = d; }

	//�����Ă������
	int GetFlont() { return flont; }

	void CheckSound();
	void Breaking(float x);
	int Mode;
	enum Mode
	{
		Normal,
		Check,
		Back,
	};

public:
	//�O���t�B�b�N�n���h��
	int StopEtexture;
	//���W
	float position_X = 0.0f;
	float position_Y = 0.0f;

	int death = 0; //�����@0:�����Ă��� 1:����ł���
	int flont = 0;//0:�O�@1:���
	//�������̈ʒu
	float before_position_X;
	float BreakPoint = 0;
	int EqualFlag = 0; //0:�����B�@1:���B

private:
	//�E�A���ɐi�ޑ��x
	float speed = 5.0f;
	float speed_ = -5.0f;
	//�ړ���
	float vector = 0.0f;
	//�U������̃J�E���g
	float count = 0;
	//�`�F�b�N�p�J�E���g
	float checkCount = 0;

	//���S�A�j���[�V����
	int death_anime = 0;
	int death_indec = 0;
	float death_x = 0.0f;
	float death_y = 0.0f;
	float death_X = 0.0f;
	float death_Y = 0.0f;
	float death_speedX = 0.1f;
	float death_Xvector = 0;
	float death_speedY = 0.5f;
	float death_Yvector = 0;
	int deathX_LR = 0;
	float a = 100;

private:
	E_Light* light;
};