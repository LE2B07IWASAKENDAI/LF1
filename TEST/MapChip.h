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

	MAPDATA mapData[MAP_COUNT];

	//グラフィックハンドル
	int gHandle[11];

	//隠れているかどうか
	bool hide;

	//マップ動く変数
	float scroll_X = 0.0f;
	float start = 708.0f;
	float end = 4115.0f;
	float endChip = 3448.0f;


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
	void SetHideTrigger(bool hide) { this->hide = hide; }
	bool GetHideTrigger() { return hide; }

	//マップスクロール
	void Scroll(float position);

	/// <summary>
	/// 扉との当たり判定
	/// </summary>
	/// <param name="x">:相手のX座標</param>
	/// <param name="y">:相手のY座標</param>
	/// <param name="player_sizeX">:相手のの横幅</param>
	/// <param name="player_sizeY">:相手のの縦幅</param>
	bool OnCollisionDoor(float x,float y,int sizeX,int sizeY);

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
	int CheckHit(int x1,int y1,int w1,int h1,
		int x2, int y2, int w2, int h2);

	//マップ情報の削除
	//void DeleteMap();

	//外部などで使うマップ番号を変えるときに使う関数
	void SetMapNumber(int mapNumber) { this->mapNumber = mapNumber; }
	int GetMapNumber() { return mapNumber; }
};