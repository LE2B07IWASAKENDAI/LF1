#include "Title_obj.h"

Title_obj::Title_obj()
{
}

Title_obj::~Title_obj()
{
}

void Title_obj::Initialize()
{
	position_Y = 500.0f;
	LoadTexture();
}

void Title_obj::Update()
{
}

void Title_obj::Draw()
{
	DrawGraph(position_X, position_Y, obj, TRUE);
}

void Title_obj::LoadTexture()
{
	obj = LoadGraph("Resources/Map/chair.png");
}
