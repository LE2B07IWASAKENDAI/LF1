#include "Title_map.h"

Title_map::Title_map()
{
}

Title_map::~Title_map()
{
	for (size_t i = 0; i < MAP_COUNT; i++) {
		vector<vector<int>>().swap(mapdata[i].data);
	}
}

void Title_map::Initialize()
{
	LoadMap();
	LoadTexture();
}

void Title_map::Update()
{
}

void Title_map::Draw()
{
	DrawItem(0, 0);
	DrawItem(1, 1);
	DrawItem(2, 2);
	DrawItem(3, 3);
	DrawItem(9, 9);
	DrawItem(4, 4);
	DrawItem(5, 5);
	DrawItem(6, 6);
	DrawItem(7, 7);
	DrawItem(8, 8);
	DrawItem(15, 15);
	DrawItem(16, 16);

	DrawItem(10, 9);
	DrawItem(18, 1);
}

void Title_map::LoadMap()
{
	mapdata[0] =
	{
		14,29,
		{
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1/*1*/,1,1,1,1,1,1,1,1,1,1/*2*/,1,1,1,1,1,1,1,1,1},
			{9,9,9,9,9,9,9,9,9,9/*1*/,9,9,9,9,9,9,9,9,9,9/*2*/,9,9,9,9,9,9,9,9,9},
			{0,0,0,0,0,0,0,0,0,0/*1*/,0,0,0,0,0,0,0,0,0,0/*2*/,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0/*1*/,0,0,0,0,0,0,0,0,0,0/*2*/,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0/*1*/,0,0,0,0,0,0,0,0,0,0/*2*/,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0/*1*/,0,0,0,0,0,0,0,0,0,0/*2*/,0,0,0,0,0,0,0,0,0},
		}
	};
}

void Title_map::LoadTexture()
{
	gHandle[0] = LoadGraph("Resources/Map/Cobblestone.png");
	gHandle[1] = LoadGraph("Resources/Map/Wall.png");
	gHandle[2] = LoadGraph("Resources/Map/.png");
	gHandle[3] = LoadGraph("Resources/Map/goal.png");
	gHandle[4] = LoadGraph("Resources/Map/Open_door.png");
	gHandle[5] = LoadGraph("Resources/Map/Door.png");
	gHandle[6] = LoadGraph("Resources/Map/chair.png");
	gHandle[7] = LoadGraph("Resources/Map/Desk.png");
	/*8は敵の生成場所*/
	gHandle[8] = LoadGraph("Resources/Map/Baseboard_Wall.png");
	gHandle[9] = LoadGraph("Resources/Map/Baseboard_Wall.png");
	gHandle[10] = LoadGraph("Resources/Map/Vase.png");
	gHandle[15] = LoadGraph("Resources/Map/light_right.png");
	gHandle[16] = LoadGraph("Resources/Map/light_left.png");

	gHandle[19] = LoadGraph("Resources/Map/hide_door_message.png");

	gHandle[20] = LoadGraph("Resources/Map/Corridor.png");
}

void Title_map::DrawItem(int chipNumber, int drwaNumber)
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//プレイヤーが扉の前に来たら当たりの判定を入れる
			if (mapdata[0].data[i][j] == chipNumber) {
				DrawGraph(j * MAP_SIZE, i * MAP_SIZE, gHandle[drwaNumber], TRUE);
			}
		}
	}
}
