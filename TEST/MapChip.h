#include"DxLib.h"
#include <vector>

#define MAP_SIZE	64			// マップチップ一つのドットサイズ

#define MAP_WIDTH	10			// マップの幅
#define MAP_HEIGHT	8			// マップの縦長さ// マップのデータ

#define MAP_COUNT 10			//マップの総数

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

	//マップ番号
	int mapNumber = 0;

	MAPDATA mapData[MAP_COUNT];

	//グラフィックハンドル
	int gHandle;
	int gHandle2;

public:
	MapChip();
	~MapChip();

	void Initialize();
	void Update();
	void Draw();


	//マップ描画
	void MapDraw();

	//マップチップ番号読み込み
	void LoadMap();
	//画像読み込み
	void LoadTexture();

	//マップ番号の更新
	void UpdateMapNumber(int nowMapNumber);

	//マップ情報の削除
	void DeleteMap();

	//外部などで使うマップ番号を変えるときに使う関数
	void SetMapNumber(int mapNumber) { this->mapNumber = mapNumber; }
	int GetMapNumber() { return mapNumber; }
};