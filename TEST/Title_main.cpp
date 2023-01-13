#include "Title_main.h"

Title_main::Title_main()
{
	map->Initialize();
	player->Initialize();
}

Title_main::~Title_main()
{
}

void Title_main::Initialize()
{
	map->Initialize();
	player->Initialize();
}

void Title_main::Update()
{
	player->Update();
}

void Title_main::Draw()
{
	map->Draw();
	player->Draw();
}
