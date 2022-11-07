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

	//�}�b�v�ԍ�
	int mapNumber = 0;

	MAPDATA mapData[MAP_COUNT];

	//�O���t�B�b�N�n���h��
	int gHandle;
	int gHandle2;

public:
	MapChip();
	~MapChip();

	void Initialize();
	void Update();
	void Draw();


	//�}�b�v�`��
	void MapDraw();

	//�}�b�v�`�b�v�ԍ��ǂݍ���
	void LoadMap();
	//�摜�ǂݍ���
	void LoadTexture();

	//�}�b�v�ԍ��̍X�V
	void UpdateMapNumber(int nowMapNumber);

	//�}�b�v���̍폜
	void DeleteMap();

	//�O���ȂǂŎg���}�b�v�ԍ���ς���Ƃ��Ɏg���֐�
	void SetMapNumber(int mapNumber) { this->mapNumber = mapNumber; }
	int GetMapNumber() { return mapNumber; }
};