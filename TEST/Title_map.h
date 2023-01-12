#pragma once
#include"DxLib.h"
#include<vector>

#define MAP_SIZE  64

#define MAP_WIDTH 29
#define MAP_HEIGHT 14

#define MAP_COUNT 1

using namespace std;

struct MAPdata
{
	int width;
	int height;

	vector<vector<int>>data;
};

class Title_map
{
private:
	int map_width;
	int map_height;

	int mapNumber = 0;
public:
	MAPdata mapdata[MAP_COUNT];


public:
	Title_map();
	~Title_map();
	void Initialize();
	void Update();
	void Draw();

	void LoadMap();
	void LoadTexture();
	void DrawItem(int chipNumber, int drwaNumber);

private:
	int gHandle[21];

	
};

