#pragma once
#include"Title_map.h"
#include"Title_plaayer.h"
#include"DxLib.h"

class Title_main
{
public:
	//�R���X�g���N�^
	Title_main();
	//�f�X�g���N�^
	~Title_main();

	void Initialize() ;
	void Update();
	void Draw();

private:
	Title_map* map = new Title_map;
	Title_plaayer* player = new Title_plaayer;
	
};



