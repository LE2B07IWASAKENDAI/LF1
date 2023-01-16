#include "Bonfire.h"

Bonfire::Bonfire()
{
}

Bonfire::~Bonfire()
{
}

void Bonfire::Initialize()
{
	LoadTexture();
}

void Bonfire::Update()
{
}

void Bonfire::LoadTexture()
{
	gHandle = LoadGraph("Resources/Map/Bonfire.png");
}

void Bonfire::Draw()
{
	DrawGraph(position_X, position_Y, gHandle, TRUE);
}
