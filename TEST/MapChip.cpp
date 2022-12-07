#include "MapChip.h"

MapChip::MapChip()
{
}

MapChip::~MapChip()
{
	//メモリの解放（マップチップデータの破棄）
	for (size_t i = 0; i < MAP_COUNT; i++) {
		vector<vector<int>>().swap(mapData[i].data);
	}
}

void MapChip::Initialize()
{
	hide = 0;
	LoadMap();
	LoadTexture();
	scroll_X = 0.0f;
	mapNumber = 1;
}


void MapChip::Update()
{

}

void MapChip::Draw(float position)
{
	if (position >= end)
	{
		scroll_X = endChip * -1;
	}
	if (position >= start && position <= end)
	{
		scroll_X = start - position;
	}

	//現在のマップ番号更新
	UpdateMapNumber(GetMapNumber());

	MapDraw();
}

void MapChip::MapDraw()
{


	//現在のマップ番号を取得し、描画する
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 84; j++) {
			switch (mapData[GetMapNumber()].data[i][j])
			{
			case 0:
				//  "  床   " 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[0], FALSE);
				break;
			case 1:
				//  "  壁   " 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[1], FALSE);
				break;
			case 2:
				//  "スタート" 描画処理
				//DrawGraph(j * MAP_SIZE, i * MAP_SIZE, gHandle[1], FALSE);
				//break;
			case 3:
				//  "ゴール地点" 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[3], FALSE);
				break;
			case 4:
				//  "空いてる扉" 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[1], FALSE);
				break;
			case 5:
				//  "閉じてる扉" 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[1], FALSE);
				break;
			case 6:
				//  " 椅　子 " 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[1], FALSE);
				break;
			case 7:
				//  "   机    " 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[1], FALSE);
				break;

			case 8:
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[9], FALSE);
				break;

			case 9:
				//  "  巾木    " 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[9], FALSE);
				break;
			case 10:
				//  "花瓶" 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[1], FALSE);
				break;

			case 15:
				//  "対右の敵から隠れる " 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[10], FALSE);
				break;
			case 16:
				//  "対左の敵から隠れる" 描画処理
				DrawGraph(j * MAP_SIZE + scroll_X, i * MAP_SIZE, gHandle[11], FALSE);
				break;
			}
		}
	}
	//for (size_t i = 0; i < mapData.size(); i++) {
	//	for (size_t j = 0; j < mapData[0].size(); j++) {
	//		if (mapData[i][j] == 0) {
	//			DrawBox(j * MAP_SIZE, i * MAP_SIZE,
	//				j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
	//				GetColor(255, 255, 255), FALSE);
	//		}
	//	}
	//}

}

void MapChip::LoadMap()
{
	//マップチップ一覧
	mapData[0] =
	{
		14,
		84,
		{
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 4, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 5, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 4, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 5, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1},
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*10*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*20*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*30*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*40*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*50*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*60*/ 9, 9, 8, 9, 9, 9, 9, 9, 9, 9,/*70*/9, 9, 9, 9, 9, 9, 9, 9, 9, 3,/*80*/ 3, 3, 3, 1},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0},
		}
	};

	mapData[1] =
	{
		84,
		14,
		{
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 4, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 6, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 7, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 6, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 7, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*10*/ 9,15, 9, 9,16, 9, 8, 9, 10, 9,/*20*/15, 9, 9, 16, 9, 9, 9, 10, 9, 9,/*30*/ 9, 9, 9,9, 9, 9,15, 9, 9,16,/*40*/9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*50*/ 15,9, 9,16,9, 9, 9, 9, 9, 9,/*60*/9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*70*/9, 9, 9, 9, 9, 9, 9, 9, 9, 3,/*80*/ 3, 3, 3, 1},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
		}
	};

	mapData[2] =
	{
		84,
		14,
		{
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 4, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 5, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 4, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 7, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/7, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 9, 9, 9, 9, 9, 9, 9, 8, 9, 9,/*10*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*20*/9, 9, 9, 9, 9, 9, 9, 9, 9, 15,/*30*/ 9, 9, 16, 9, 9, 9, 9, 9, 9, 9,/*40*/9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*50*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 15,/*60*/9, 9, 16, 9, 9, 9, 9, 9, 9, 9,/*70*/9, 9, 9, 9, 9, 9, 9, 9, 9, 3,/*80*/ 3, 3, 3, 1},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
		}
	};

	mapData[3] =
	{
		84,
		14,
		{
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/10, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1,10, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 7, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 7, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 7, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*10*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*20*/9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*30*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*40*/9, 9, 9, 9, 9, 9, 9, 9, 9, 15,/*50*/ 9, 9, 16, 9, 9, 9, 9, 9, 9, 9,/*60*/9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*70*/9, 9, 9, 9, 9, 9, 9, 9, 9, 3,/*80*/ 3, 3, 3, 1},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
		}
	};

	mapData[4] =
	{
		84,
		14,
		{
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*80*/ 1, 1, 1, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 10,1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 7, 1,/*50*/ 1, 1, 1, 1, 1, 6, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*10*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*20*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*30*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*40*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*50*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*60*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1,/*70*/1, 1, 1, 1, 1, 1, 1, 1, 1, 3,/*80*/ 3, 3, 3, 1} ,
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*10*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*20*/9, 9, 9, 9, 8, 9, 9, 9, 9, 9,/*30*/ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*40*/9, 9, 9, 9, 9, 9, 9, 9, 9, 9,/*50*/ 9, 9, 9, 9, 15, 9, 9, 16, 9, 9,/*60*/9, 9, 9, 9, 9, 8, 9, 9, 9, 9,/*70*/9, 9, 9, 9, 9, 9, 9, 9, 9, 3,/*80*/ 3, 3, 3, 1},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*10*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*20*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*30*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*40*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*50*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*60*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*70*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/*80*/ 0, 0, 0, 0} ,
		}
	};

}

void MapChip::LoadTexture()
{
	//変数 画像データ格納
	gHandle[0] = LoadGraph("Resources/Map/Cobblestone.png");
	gHandle[1] = LoadGraph("Resources/Map/Wall.png");
	gHandle[2] = LoadGraph("Resources/Map/.png");
	gHandle[3] = LoadGraph("Resources/Map/goal.png");
	gHandle[4] = LoadGraph("Resources/Map/Open_door.png");
	gHandle[5] = LoadGraph("Resources/Map/Door.png");
	gHandle[6] = LoadGraph("Resources/Map/chair.png");
	gHandle[7] = LoadGraph("Resources/Map/Desk.png");
	/*8は敵の生成場所*/
	gHandle[9] = LoadGraph("Resources/Map/Baseboard_Wall.png");
	gHandle[10] = LoadGraph("Resources/Map/light_right.png");
	gHandle[11] = LoadGraph("Resources/Map/light_left.png");

	gHandle[19] = LoadGraph("Resources/Map/hide_door_message.png");
}

void MapChip::UpdateMapNumber(int nowMapNumber)
{
	//マップ番号を現在の番号に変更する
	mapNumber = nowMapNumber;
}

void MapChip::Scroll(float position)
{

	if (position >= start)
	{
		scroll_X = position - start;
	}
}

float MapChip::Get_position_8_X()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 8) {
				position_8_X = j * MAP_SIZE + scroll_X;
				position_8_Y = i * MAP_SIZE;
			}
		}
	}

	return position_8_X;
}

float MapChip::Get_position_8_Y()
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 82; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 8) {
				position_8_X = j * MAP_SIZE;
				position_8_Y = i * MAP_SIZE;

			}
		}
	}

	return position_8_Y;
}

float MapChip::GetPosition_10_X()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 10) {
				position_12_X = j * MAP_SIZE + scroll_X;
				position_12_Y = i * MAP_SIZE;
			}
		}
	}

	return position_12_X;
}

float MapChip::GetPosition_10_Y()
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 82; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 10) {
				position_12_X = j * MAP_SIZE;
				position_12_Y = i * MAP_SIZE;
			}
		}
	}

	return position_12_Y;
}

bool MapChip::OnCollisionDoor(float x, float y, int sizeX, int sizeY)
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 82; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 4) {
				if (CheckHit(j * MAP_SIZE, i * MAP_SIZE, MAP_SIZE, MAP_SIZE,
					x, y, sizeX, sizeY))
				{
					SetHideTrigger(true);

					return true;
				}
			}
			else {
				SetHideTrigger(false);
			}
		}
	}
	return false;
}

bool MapChip::OnCollisionChair_Right(float x, float y, int sizeX, int sizeY)
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 82; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 15) {
				if (CheckHit(j * MAP_SIZE, i * MAP_SIZE, MAP_SIZE, MAP_SIZE,
					x, y, sizeX, sizeY))
				{
					SetHideTrigger(true);

					return true;
				}
			}
			else {
				SetHideTrigger(false);
			}
		}
	}
	return false;
}

bool MapChip::OnCollisionChair_Left(float x, float y, int sizeX, int sizeY)
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 82; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 16) {
				if (CheckHit(j * MAP_SIZE, i * MAP_SIZE, MAP_SIZE, MAP_SIZE,
					x, y, sizeX, sizeY))
				{
					SetHideTrigger(true);

					return true;
				}
			}
			else {
				SetHideTrigger(false);
			}
		}
	}
	return false;
}

bool MapChip::OnCollisionGoal(float x, float y, int sizeX, int sizeY)
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 82; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapData[GetMapNumber()].data[i][j] == 3)
			{
				if (CheckHit(j * MAP_SIZE, i * MAP_SIZE, MAP_SIZE, MAP_SIZE,
					x, y, sizeX, sizeY))
				{
					return true;
				}
				//当たっていないときはhide = false;
				//else
				//{
				//	SetHideTrigger(false);
				//}
			}
		}
	}
	return false;
}

int MapChip::CheckHit(int x1, int y1, int w1, int h1,
	int x2, int y2, int w2, int h2)
{
	int L1 = x1;
	int R1 = x1 + w1;
	int L2 = x2;
	int R2 = x2 + w2;

	if (R1 < L2)return 0;
	if (R2 < L1)return 0;

	//上記以外は当たっている
	return 1;
}

