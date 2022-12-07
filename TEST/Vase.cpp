#include "Vase.h"

Vase::Vase()
{
}

Vase::~Vase()
{
}

void Vase::Initialize()
{
	//position_X = 800;
	//position_Y = 600;
	LoadTexture();
	dead = 0;
}

void Vase::Break()
{
	//SetDead(1);
}

void Vase::Update()
{
}

void Vase::LoadTexture()
{
	gHandle = LoadGraph("Resources/Item/break.png");
}

void Vase::Draw()
{
	if(GetDead() == 0)
	DrawGraph(position_X, position_Y, gHandle, TRUE);
}