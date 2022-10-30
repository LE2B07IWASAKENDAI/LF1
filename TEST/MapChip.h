#include"DxLib.h"
#include <vector>

#define MAP_SIZE	64			// �}�b�v�`�b�v��̃h�b�g�T�C�Y

#define MAP_WIDTH	10			// �}�b�v�̕�
#define MAP_HEIGHT	8			// �}�b�v�̏c����// �}�b�v�̃f�[�^

#define MAP_COUNT 10			//�}�b�v�̑���

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

	int mapNumber = 0;

	MAPDATA mapData[MAP_COUNT];

//private:
//	vector<vector<int>> mapData;

public:
	MapChip();
	~MapChip();

	void Initialize();
	void LoadMap();
	void Update();
	void Draw();

	void SetMapNumber(int nowMapNumber) { mapNumber = nowMapNumber; }
	int GetMapNumber() { return mapNumber; }
};