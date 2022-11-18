#include "knife.h";
#include "Player.h"

knife::knife()
{

}

knife::~knife()
{

}

void knife::Initialize()
{
	LoadTexture();
	position_X = -1000.0f;
	position_Y = 600.0f;
}

void knife::Update()
{
	//ˆÚ“®ˆ—
	position_X = position_X + speed;
}

void knife::Draw()
{

}


float knife::GetPosition_X()
{
	return position_X;
}

float knife::GetPosition_Y()
{
	return position_Y;
}

void knife::LoadTexture()
{
	knifetex = LoadGraph("Resources/Player/Knife.png");
}