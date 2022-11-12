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


	//隠れている時
	void Hidding();
	//画像読み込み
	void LoadTexture();

/*Getter,Setter*/
	bool GetHide();
	void SetHide(bool sethide);

	float GetPosition_X();
	float GetPosition_Y();
	float SetPosition(float x, float y);

	int GetPlayerSizeX() { return size_x; }
	int GetPlayerSizeY() { return size_y; }

	int GetDeath();
	int SetDeath(int d);

	//プレイヤーの行動制限（隠れているときは移動が出来ない）
	void SetkeyPermission(bool keyPermission) {	this->keyPermission = keyPermission; }
	bool GetkeyPermission() { return keyPermission; }

	bool GetDrawPlayer() { return drawPlayer; }

//Debugモードのみで使うもの(予定)
	void DrawPlayerPos();

private:
	int ptexture = 0;
	int hidetext = 0;
	int keyCounter = 0;//キーを押した瞬間を取るためのカウンター
	int size_x = 64, size_y = 64;//プレイヤー画像のサイズ
	float position_X = 0.0f;   //X座標
	float position_Y = 700.0f; //Y座標
	float speed = 7.5f;        //移動速度
	bool hide = false;//隠れる
	bool drawPlayer = false;//隠れているときは描画しない
	bool keyPermission = false;//扉の中にいるときは、移動出来ないようにする。

public:
	int death = 0; //生死　0:生きてる 1:死んでる
};