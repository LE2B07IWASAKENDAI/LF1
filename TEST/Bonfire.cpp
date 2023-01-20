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
	ghandle_light = LoadGraph("Resources/Map/TorchLight.png");
}

void Bonfire::Draw()
{

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 80);

	DrawGraph(position_X, position_Y, ghandle_light, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawGraph(position_X, position_Y, gHandle, TRUE);

}
