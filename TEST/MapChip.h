#include"DxLib.h"
#include <vector>

#define MAP_SIZE	64			// �}�b�v�`�b�v��̃h�b�g�T�C�Y

#define MAP_WIDTH	84			// �}�b�v�̕�
#define MAP_HEIGHT	14			// �}�b�v�̏c����// �}�b�v�̃f�[�^

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
	int map_width;
	int map_height;

	//�}�b�v�ԍ�
	int mapNumber = 0;

public:
	MAPDATA mapData[MAP_COUNT];


private:
	//�O���t�B�b�N�n���h��
	int gHandle[20];

	//�B��Ă��邩�ǂ���
	int hide; //1:�B��Ă���@0:�����łȂ�

	//�}�b�v�����ϐ�
	float scroll_X = 0.0f;
	float start = 708.0f;
	float end = 4115.0f;
	float endChip = 3448.0f;

	//�G�ʒu
	float position_8_X = 0.0f;
	float position_8_Y = 0.0f;

	float position_12_X = 0.0f;
	float position_12_Y = 0.0f;


public:
	MapChip();
	~MapChip();

	void Initialize();
	void Update();
	void Draw(float position);


	//�}�b�v�`��
	void MapDraw();

	//�}�b�v�`�b�v�ԍ��ǂݍ���
	void LoadMap();
	//�摜�ǂݍ���
	void LoadTexture();

	//�}�b�v�ԍ��̍X�V
	void UpdateMapNumber(int nowMapNumber);

	//�h�A�ɉB��Ă��邩�ۂ���Setter��Getter
	void SetHideTrigger(int hide) { this->hide = hide; }
	int GetHideTrigger() { return hide; }

	//�C�X�ɐ������Ɍ�����
	void SetHideFalse_Chair() { hide = 0; }


	//�}�b�v�X�N���[��
	void Scroll(float position);

	float GetScroll() { return scroll_X; }

	//�}�b�v���W��n��
	//�G_8
	float Get_position_8_X();
	float Get_position_8_Y();

	//�ԕr�I�Ȃ�
	float GetPosition_10_X();
	float GetPosition_10_Y();

	/// <summary>
	/// ���Ƃ̓����蔻��
	/// </summary>
	/// <param name="x">:�����X���W</param>
	/// <param name="y">:�����Y���W</param>
	/// <param name="player_sizeX">:����̂̉���</param>
	/// <param name="player_sizeY">:����̂̏c��</param>
	bool OnCollisionDoor(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// �C�X�Ƃ̓����蔻��@/*�E���炭��G�݂̂ɗL��*/
	/// </summary>
	/// <param name="x">:�����X���W</param>
	/// <param name="y">:�����Y���W</param>
	/// <param name="player_sizeX">:����̂̉���</param>
	/// <param name="player_sizeY">:����̂̏c��</param>
	bool OnCollisionChair_Right(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// �C�X�Ƃ̓����蔻��@/*�����炭��G�݂̂ɗL��*/
	/// </summary>
	/// <param name="x">:�����X���W</param>
	/// <param name="y">:�����Y���W</param>
	/// <param name="player_sizeX">:����̂̉���</param>
	/// <param name="player_sizeY">:����̂̏c��</param>
	bool OnCollisionChair_Left(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// �S�[���Ƃ̓����蔻��
	/// </summary>
	/// <param name="x">:�����X���W</param>
	/// <param name="y">:�����Y���W</param>
	/// <param name="player_sizeX">:����̂̉���</param>
	/// <param name="player_sizeY">:����̂̏c��</param>
	bool OnCollisionGoal(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// �����蔻��͈�
	/// </summary>
	/// <param name="x1">:�w�肵���}�b�v�`�b�v�ԍ���x���W</param>
	/// <param name="y1">:�w�肵���}�b�v�`�b�v�ԍ���y���W</param>
	/// <param name="w1">:�`�b�v�P���̉���</param>
	/// <param name="h1">:�`�b�v�P���̏c��</param>
	/// <param name="x2">:���葤��x���W</param>
	/// <param name="y2">:���葤��y���W</param>
	/// <param name="w2">:���葤�̉���</param>
	/// <param name="h2">:���葤�̏c��</param>
	/// <returns>: return = 1�Ȃ瓖�����Ă��� </returns>
	int CheckHit(int x1, int y1, int w1, int h1,
		int x2, int y2, int w2, int h2);

	//�}�b�v���̍폜
	//void DeleteMap();

	//�O���ȂǂŎg���}�b�v�ԍ���ς���Ƃ��Ɏg���֐�
	void SetMapNumber(int mapNumber) { this->mapNumber = mapNumber; }
	int GetMapNumber() { return mapNumber; }
};