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


	//隠れている時
	void Hidding();
	//画像読み込み
	void LoadTexture();

/*Getter,Setter*/
	bool GetHide();
	void SetHide(bool sethide);

	//ローカル座標
	float GetPosition_X();
	//グローバル座標
	float GetPosition_x();

	float GetPosition_Y();
	void SetPosition(float x, float y);

	int GetPlayerSizeX() { return size_x; }
	int GetPlayerSizeY() { return size_y; }

	int GetDeath();
	int SetDeath(int d);

	//プレイヤーの行動制限（隠れているときは移動が出来ない）
	void SetkeyPermission(bool keyPermission) {	this->keyPermission = keyPermission; }
	bool GetkeyPermission() { return keyPermission; }

	//ナイフの座標
	float GetKnifePos() { return knifePosition; }
	void SetKnifePos(float pos) { knifePosition = pos; }

	//ナイフの当たり判定
	int GetHitFlag() { return hitFlag; }

	//ナイフを消すトリガー
	void SetDisapperKnifeTrigger(int flag) { diaspper_knife_trigger = flag; }
	int GetDisapperKnifeTrigger() { return diaspper_knife_trigger; }

	//分岐トリガー
	void SetChangeMap(int change) { change_map = change; }
	int GetChangeMap() { return change_map; }


//Debugモードのみで使うもの(予定)
	void DrawPlayerPos();

private:
	int ptexture_R = 0;
	int ptexture_L = 0;
	int rl = 0;
	int hidetext = 0;
	int keyCounter = 0;//キーを押した瞬間を取るためのカウンター
	int size_x = 200, size_y = 200;//プレイヤー画像のサイズ(11/10に津村が追加 ※後で消去)
	float position_X = 0.0f;   //X座標
	float position_Y = 576.0f; //Y座標
	float speed = 7.5f;        //移動速度
	int hide = 0;//1：隠れている　0:そうでない
	//bool drawPlayer = false;//隠れているときは描画しない
	bool keyPermission = false;//扉の中にいるときは、移動出来ないようにする。

	float return_Positin = 0.0f;
	float center = 708.0f;//画面中心
	float end = 4094.0f;//画面端

	int change_map = 0;

public:
	int death = 0; //生死　0:生きてる 1:死んでる

	//ナイフ
private:
	Knife* knife;

	//敵との当たり判定用で使うナイフの座標
	float knifePosition;

	//ナイフ⇔敵の当たり判定
	int hitFlag;

	//ナイフを消すトリガー
	int diaspper_knife_trigger;
};