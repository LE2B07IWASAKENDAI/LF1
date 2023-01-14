#include "Title_main.h"

Title_main::Title_main()
{
	map->Initialize();
	obj->Initialize();
	player->Initialize();
	bg = LoadGraph("Resources/Scene/title.png");
}

Title_main::~Title_main()
{
}

void Title_main::Initialize()
{
	map->Initialize();
	obj->Initialize();
	player->Initialize();
}

void Title_main::Update()
{
	player->Update();
}

void Title_main::Draw()
{
	map->Draw();
	obj->Draw();
	player->Draw();
	DrawGraph(0, 0, bg, TRUE);
}
