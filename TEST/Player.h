#pragma once
#include"DxLib.h"

#include "knife.h"

#include <vector>

using namespace std;

class Player
{

public:
	Player();
	~Player();
	void Initialize();
	void Update();
	void Draw();


	//�B��Ă��鎞
	void Hidding();
	//�摜�ǂݍ���
	void LoadTexture();

/*Getter,Setter*/
	bool GetHide();
	void SetHide(bool sethide);

	//���[�J�����W
	float GetPosition_X();
	//�O���[�o�����W
	float GetPosition_x();

	float GetPosition_Y();
	void SetPosition(float x, float y);

	int GetPlayerSizeX() { return size_x; }
	int GetPlayerSizeY() { return size_y; }

	int GetDeath();
	int SetDeath(int d);

	//�v���C���[�̍s�������i�B��Ă���Ƃ��͈ړ����o���Ȃ��j
	void SetkeyPermission(bool keyPermission) {	this->keyPermission = keyPermission; }
	bool GetkeyPermission() { return keyPermission; }

	//�i�C�t�̍��W
	float GetKnifePos() { return knifePosition; }
	void SetKnifePos(float pos) { knifePosition = pos; }

	//�i�C�t�̓����蔻��
	int GetHitFlag() { return hitFlag; }

	//�i�C�t�������g���K�[
	void SetDisapperKnifeTrigger(int flag) { diaspper_knife_trigger = flag; }
	int GetDisapperKnifeTrigger() { return diaspper_knife_trigger; }

	//����g���K�[
	void SetChangeMap(int change) { change_map = change; }
	int GetChangeMap() { return change_map; }


//Debug���[�h�݂̂Ŏg������(�\��)
	void DrawPlayerPos();

private:
	int ptexture_R = 0;
	int ptexture_L = 0;
	int rl = 0;
	int hidetext = 0;
	int keyCounter = 0;//�L�[���������u�Ԃ���邽�߂̃J�E���^�[
	int size_x = 200, size_y = 200;//�v���C���[�摜�̃T�C�Y(11/10�ɒÑ����ǉ� ����ŏ���)
	float position_X = 0.0f;   //X���W
	float position_Y = 576.0f; //Y���W
	float speed = 7.5f;        //�ړ����x
	int hide = 0;//1�F�B��Ă���@0:�����łȂ�
	//bool drawPlayer = false;//�B��Ă���Ƃ��͕`�悵�Ȃ�
	bool keyPermission = false;//���̒��ɂ���Ƃ��́A�ړ��o���Ȃ��悤�ɂ���B

	float return_Positin = 0.0f;
	float center = 708.0f;//��ʒ��S
	float end = 4094.0f;//��ʒ[

	int change_map = 0;

public:
	int death = 0; //�����@0:�����Ă� 1:����ł�

	//�i�C�t
private:
	Knife* knife;

	//�G�Ƃ̓����蔻��p�Ŏg���i�C�t�̍��W
	float knifePosition;

	//�i�C�t�̓G�̓����蔻��
	int hitFlag;

	//�i�C�t�������g���K�[
	int diaspper_knife_trigger;
};