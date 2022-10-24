#include "MapChip.h"

MapChip::MapChip()
{
}

MapChip::~MapChip()
{
	//ÉÅÉÇÉäÇÃâï˙
	//vector<vector<int>>().swap(mapData);
	////ÉÅÉÇÉäÇÃâï˙
	//vector<vector<int>>().swap(mapData);
}

void MapChip::Initialize()
{
	mapData/*[MAP_COUNT]*/ = 
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
	//mapData = 
 //   {
	//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	//	{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 } ,
	//	{ 0, 1, 0, 1, 1, 0, 0, 0, 1, 0 } ,
	//	{ 0, 1, 1, 1, 1, 0, 0, 0, 1, 0 } ,
	//	{ 0, 1, 0, 1, 0, 0, 0, 0, 1, 0 } ,
	//	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
	//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
 //   };
}

void MapChip::Update()
{

	for (size_t i = 0; i < mapData.data.size(); i++) {
		for (size_t j = 0; j < mapData.data.size(); j++) {
			if (mapData.data[i][j] == 0) {
				DrawBox(j * MAP_SIZE, i * MAP_SIZE,
					j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
					GetColor(255, 255, 255), FALSE);
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
