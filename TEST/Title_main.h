#pragma once
#include"Title_map.h"
#include"Title_player.h"
#include"Title_obj.h"
#include"DxLib.h"

class Title_main
{
public:
	//コンストラクタ
	Title_main();
	//デストラクタ
	~Title_main();

	void Initialize() ;
	void Update();
	void Draw();

private:
	Title_map* map = new Title_map;
	Title_player* player = new Title_player;
	Title_obj* obj = new Title_obj;
	int bg = 0;
	
};



