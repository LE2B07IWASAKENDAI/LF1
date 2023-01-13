#include "Chair.h"

Chair::Chair()
{
}

Chair::~Chair()
{
}

void Chair::Initialize()
{
	LoadTexture();
}

void Chair::LoadTexture()
{
	gHandle = LoadGraph("Resources/Map/Chair.png");
}

void Chair::Draw()
{
	DrawGraph(position_X, position_Y, gHandle, TRUE);
}
