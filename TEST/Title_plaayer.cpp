#include "Title_plaayer.h"

Title_plaayer::Title_plaayer()
{

}

Title_plaayer::~Title_plaayer()
{
}

void Title_plaayer::Initialize()
{
	LoadTexture();
	position_X = 0.0f;
	position_Y = 576.0f;
	pattern_Nuber = 0;
}

void Title_plaayer::Update()
{
	position_X += vector * speed;
	if (position_X > witdh)
	{
		position_X = -192.0f;
	}
}

void Title_plaayer::Draw()
{
	DrawGraph(position_X, position_Y, texture_R, TRUE);
}

void Title_plaayer::LoadTexture()
{
	texture_R = LoadGraph("Resources/Player/Player_R.png");
	texture_L = LoadGraph("Resources/Player/Player_L.png");
	LoadDivGraph("Resources/Player/playerAni_R.png", 6, 6, 1, 192, 192, walk_R);
	LoadDivGraph("Resources/Player/playerAni_L.png", 6, 6, 1, 192, 192, walk_L);
}
