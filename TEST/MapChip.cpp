#include "MapChip.h"

MapChip::MapChip()
{
}

MapChip::~MapChip()
{
	//ƒƒ‚ƒŠ‚Ì‰ğ•ú
	for (size_t i = 0; i < mapData[0].data.size(); i++) {
		for (size_t j = 0; j < mapData[0].data.size(); j++) {
			vector<vector<int>>().swap(mapData[i].data);
		}
	}
}

void MapChip::Initialize()
{
	LoadMap();
	LoadTexture();
}


void MapChip::Update()
{
	for (size_t i = 0; i < mapData[GetMapNumber()].data.size(); i++) {
		for (size_t j = 0; j < mapData[GetMapNumber()].data.size(); j++) {
			if (mapData[GetMapNumber()].data[i][j] == 0) {
				//DrawBox(j * MAP_SIZE, i * MAP_SIZE,
				//	j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
				//	GetColor(255, 255, 255), FALSE);

				DrawGraph(j*MAP_SIZE, i*MAP_SIZE, gHandle, FALSE);
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

void MapChip::Draw()
{
}

void MapChip::LoadMap()
{
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
	gHandle = LoadGraph("flor.png");
}

