#pragma once
#include"DxLib.h"
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

	float GetPosition_X();
	float GetPosition_x();
	float GetPosition_Y();
	float SetPosition(float x, float y);

	int GetPlayerSizeX() { return size_x; }
	int GetPlayerSizeY() { return size_y; }

	int GetDeath();
	int SetDeath(int d);

	//�v���C���[�̍s�������i�B��Ă���Ƃ��͈ړ����o���Ȃ��j
	void SetkeyPermission(bool keyPermission) {	this->keyPermission = keyPermission; }
	bool GetkeyPermission() { return keyPermission; }

	//���݃v���C���[���`�悳��Ă��邩���擾����֐�
	bool GetDrawPlayer() { return drawPlayer; }

//Debug���[�h�݂̂Ŏg������(�\��)
	void DrawPlayerPos();

private:
	int ptexture = 0;
	int hidetext = 0;
	int keyCounter = 0;//�L�[���������u�Ԃ���邽�߂̃J�E���^�[
	int size_x = 200, size_y = 200;//�v���C���[�摜�̃T�C�Y(11/10�ɒÑ����ǉ� ����ŏ���)
	float position_X = 0.0f;   //X���W
	float position_Y = 700.0f; //Y���W
	float speed = 7.5f;        //�ړ����x
	bool hide = false;//�B���
	bool drawPlayer = false;//�B��Ă���Ƃ��͕`�悵�Ȃ�
	bool keyPermission = false;//���̒��ɂ���Ƃ��́A�ړ��o���Ȃ��悤�ɂ���B

	float return_Positin = 0.0f;
	float center = 708.0f;//��ʒ��S
	float end = 4094.0f;//��ʒ[

public:
	int death = 0; //�����@0:�����Ă� 1:����ł�
};