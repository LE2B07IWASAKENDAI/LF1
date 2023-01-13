#pragma once
#include "DxLib.h" 

#include "MapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "Vase.h"
#include "BGM.h"
#include "SE.h"
#include "Chair.h"
#include "Collision.h"


class Stage
{
public:
	Stage();
	~Stage();

	void Initialize();

	void SetItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber);

	void SetItem_28(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber);

	void DrawItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int ghandle);

	void DeleteItem(std::vector<float>& posx, std::vector<float>& posy);

	void AllDelete(std::vector<float>& eposx, std::vector<float>& eposy, std::vector<float>& open_doorx, std::vector<float>& open_doory,
		std::vector<float>& doorx, std::vector<float>& doory, std::vector<float>& chairx, std::vector<float>& chairy,
		std::vector<float>& deskx, std::vector<float>& desky, std::vector<float>& vasex, std::vector<float>& vasey,
		std::vector<float>& hidex_left, std::vector<float>& hidey_left, std::vector<float>& hidex_right, std::vector<float>& hidey_right);

	void Release();

	void Generate(int map);
	void Generate2(int map);

	void SetMap(int map);

	void Drow();

	void Update_01();

	void Update_02();

	int SetGool();

	int SetGameOver() { return over; }


private:
	//クラス
	MapChip* mapChip = new MapChip();
	Player* player = new Player();
	BGM* bgm = new BGM();
	SE* se = new SE();
	std::vector<Enemy*> enemy;
	std::vector<Vase*> vase;
	std::vector<Chair*>chair;

	Collision* collision = new Collision();

	//マップチップで標示する物の座標格納変数
	std::vector<float>eposx;
	std::vector<float>eposy;

	std::vector<float>open_doorx;
	std::vector<float>open_doory;

	std::vector<float>doorx;
	std::vector<float>doory;

	std::vector<float>chairx;
	std::vector<float>chairy;

	std::vector<float>deskx;
	std::vector<float>desky;

	std::vector<float>vasex;
	std::vector<float>vasey;

	std::vector<float>hidex_left;
	std::vector<float>hidey_left;

	std::vector<float>hidex_right;
	std::vector<float>hidey_right;

	int ghandleOPD ;
	int ghandleCLD ;
	int ghandleCHR ;
	int ghandleDSK ;
	int ghandleHID_L;
	int ghandleHID_R;
	
	// 花瓶フラグ
	int BreakFlag = 0;

	int mapWarp = 0;

	const bool mapInit = true;

	//ゲームオ―バー
	int over = 0;
	//ゴール
	int gool = 0;
};

