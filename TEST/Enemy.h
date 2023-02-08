#pragma once
#include"DxLib.h"
#include <vector>

#include"knife.h"
#include"Collision.h"
#include"Vase.h"
#include"E_Light.h"
//#include"MapChip.h"

using namespace std;

class Enemy
{

public:
	Enemy();
	~Enemy();

	//������
	void Initialize();
	//�ړ�
	void Movement();
	//����
	void Horizon();
	//���S���菈��
	void Dead();
	//���t���[���X�V
	void Update();
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
	void Set_map(float x);

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
	};

public:
	//�O���t�B�b�N�n���h��
	int Etexture;
	//���W
	float position_X = 0.0f;
	float position_Y = 0.0f;

	int death = 0; //�����@0:�����Ă��� 1:����ł���
	int flont = 0;//0:���(��)�@1:�O(�E)
private:
	//�E�A���ɐi�ޑ��x
	float speed = 5.0f;
	float speed_ = -5.0f;
	//�ړ���
	float vector = 0.0f;
	//��~���Ԃ̃J�E���g
	int count = 0;

	//�A�j���[�V����
	int walk_L[6];
	int walk_R[6];
	int walk_indec = -1;
	int anime_time = 0;
	int anime_max = 5;

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


	//�������ꂽ���̍��W
	float before_position_X;
	//�����ʒu�ƁA���݈ʒu�Ƃ̍��W��
	float movement_position_X;
	float BreakPoint = 0;
	int EqualFlag = 0; //0:�����B�@1:���B

private:
	Knife* knife;
	Collision* collision;
	Vase* vase;
	E_Light* light;
};