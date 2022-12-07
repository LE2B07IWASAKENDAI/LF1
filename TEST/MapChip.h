#include"DxLib.h"
#include <vector>

#define MAP_SIZE	64			// マップチップ一つのドットサイズ

#define MAP_WIDTH	84			// マップの幅
#define MAP_HEIGHT	14			// マップの縦長さ// マップのデータ

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
	int map_width;
	int map_height;

	//マップ番号
	int mapNumber = 0;

public:
	MAPDATA mapData[MAP_COUNT];


private:
	//グラフィックハンドル
	int gHandle[20];

	//隠れているかどうか
	int hide; //1:隠れている　0:そうでない

	//マップ動く変数
	float scroll_X = 0.0f;
	float start = 708.0f;
	float end = 4115.0f;
	float endChip = 3448.0f;

	//敵位置
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


	//マップ描画
	void MapDraw();

	//マップチップ番号読み込み
	void LoadMap();
	//画像読み込み
	void LoadTexture();

	//マップ番号の更新
	void UpdateMapNumber(int nowMapNumber);

	//ドアに隠れているか否かのSetterとGetter
	void SetHideTrigger(int hide) { this->hide = hide; }
	int GetHideTrigger() { return hide; }

	//イスに潜伏中に見つかる
	void SetHideFalse_Chair() { hide = 0; }


	//マップスクロール
	void Scroll(float position);

	float GetScroll() { return scroll_X; }

	//マップ座標を渡す
	//敵_8
	float Get_position_8_X();
	float Get_position_8_Y();

	//花瓶的なの
	float GetPosition_10_X();
	float GetPosition_10_Y();

	/// <summary>
	/// 扉との当たり判定
	/// </summary>
	/// <param name="x">:相手のX座標</param>
	/// <param name="y">:相手のY座標</param>
	/// <param name="player_sizeX">:相手のの横幅</param>
	/// <param name="player_sizeY">:相手のの縦幅</param>
	bool OnCollisionDoor(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// イスとの当たり判定　/*右からくる敵のみに有効*/
	/// </summary>
	/// <param name="x">:相手のX座標</param>
	/// <param name="y">:相手のY座標</param>
	/// <param name="player_sizeX">:相手のの横幅</param>
	/// <param name="player_sizeY">:相手のの縦幅</param>
	bool OnCollisionChair_Right(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// イスとの当たり判定　/*左からくる敵のみに有効*/
	/// </summary>
	/// <param name="x">:相手のX座標</param>
	/// <param name="y">:相手のY座標</param>
	/// <param name="player_sizeX">:相手のの横幅</param>
	/// <param name="player_sizeY">:相手のの縦幅</param>
	bool OnCollisionChair_Left(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// ゴールとの当たり判定
	/// </summary>
	/// <param name="x">:相手のX座標</param>
	/// <param name="y">:相手のY座標</param>
	/// <param name="player_sizeX">:相手のの横幅</param>
	/// <param name="player_sizeY">:相手のの縦幅</param>
	bool OnCollisionGoal(float x, float y, int sizeX, int sizeY);

	/// <summary>
	/// 当たり判定範囲
	/// </summary>
	/// <param name="x1">:指定したマップチップ番号のx座標</param>
	/// <param name="y1">:指定したマップチップ番号のy座標</param>
	/// <param name="w1">:チップ１枚の横幅</param>
	/// <param name="h1">:チップ１枚の縦幅</param>
	/// <param name="x2">:相手側のx座標</param>
	/// <param name="y2">:相手側のy座標</param>
	/// <param name="w2">:相手側の横幅</param>
	/// <param name="h2">:相手側の縦幅</param>
	/// <returns>: return = 1なら当たっている </returns>
	int CheckHit(int x1, int y1, int w1, int h1,
		int x2, int y2, int w2, int h2);

	//マップ情報の削除
	//void DeleteMap();

	//外部などで使うマップ番号を変えるときに使う関数
	void SetMapNumber(int mapNumber) { this->mapNumber = mapNumber; }
	int GetMapNumber() { return mapNumber; }
};