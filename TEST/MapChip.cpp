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
	LoadMap();
	LoadTexture();
}


void MapChip::Update()
{
}

void MapChip::Draw()
{
	//キー押下でマップ番号変更
	if (CheckHitKey(KEY_INPUT_L) == 1) {
		//マップ番号の指定
		mapNumber = 0;
	}
	if (CheckHitKey(KEY_INPUT_P) == 1) {
		mapNumber = 1;
	}
	//現在のマップ番号更新
	UpdateMapNumber(GetMapNumber());
	
	MapDraw();
}

void MapChip::MapDraw()
{
	//現在のマップ番号を取得し、描画する
	for (size_t i = 0; i < mapData[GetMapNumber()].data.size(); i++) {
		for (size_t j = 0; j < mapData[GetMapNumber()].data.size(); j++) {
			if (mapData[GetMapNumber()].data[i][j] == 0) {
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,
				//	j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
				//	GetColor(255, 255, 255), FALSE);

				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, gHandle, FALSE);
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
		10,
		8,
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 } ,
			{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 } ,
			{ 0, 1, 0, 1, 1, 0, 0, 0, 1, 0 } ,
			{ 0, 1, 1, 1, 1, 0, 0, 0, 1, 0 } ,
			{ 0, 1, 0, 1, 0, 0, 0, 0, 1, 0 } ,
			{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		}
	};

	mapData[1] =
	{
		10,
		8,
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
			{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 } ,
			{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 } ,
			{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 } ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
			{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		}
	};

}

void MapChip::LoadTexture()
{
	gHandle = LoadGraph("Resources/Map/flor.png");
}

void MapChip::UpdateMapNumber(int nowMapNumber)
{
	//マップ番号の更新
	mapNumber = nowMapNumber;
}

