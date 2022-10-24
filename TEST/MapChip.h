#include"DxLib.h"
#include <vector>

#define MAP_SIZE	64			// マップチップ一つのドットサイズ

#define MAP_WIDTH	10			// マップの幅
#define MAP_HEIGHT	8			// マップの縦長さ// マップのデータ

#define MAP_COUNT 1			//マップの総数

using namespace std;

struct MAPDATA
{
	int width;
	int height;

	vector<vector<int>> data;
};

class MapChip
{

private:
	int map_width = 10;
	int map_height = 8;

	MAPDATA mapData/*[MAP_COUNT]*/;

//private:
//	vector<vector<int>> mapData;

public:
	MapChip();
	~MapChip();

	void Initialize();
	void Update();
	void Draw();
};