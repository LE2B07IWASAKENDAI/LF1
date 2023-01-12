#pragma once
#include"Title_map.h"
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
	
};



