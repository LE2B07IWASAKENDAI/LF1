#include "Title_player.h"

Title_player::Title_player()
{

}

Title_player::~Title_player()
{
}

void Title_player::Initialize()
{
	LoadTexture();
	position_X = 0.0f;
	position_Y = 576.0f;
	pattern_Nuber = 0;
	walk_index = 0;
	direction = 0;
}

void Title_player::Update()
{
	//動き
	Control(direction);


	//アニメ―ション
	Animation();

}

void Title_player::Draw()
{
	/*DrawGraph(position_X, position_Y, texture_R, TRUE);*/
	DrawGraph(position_X, position_Y, walk_R[walk_index], TRUE);
}

void Title_player::LoadTexture()
{
	texture_R = LoadGraph("Resources/Player/Player_R.png");
	texture_L = LoadGraph("Resources/Player/Player_L.png");
	LoadDivGraph("Resources/Player/playerAni_R.png", 6, 6, 1, 192, 192, walk_R);
	LoadDivGraph("Resources/Player/playerAni_L.png", 6, 6, 1, 192, 192, walk_L);
}

void Title_player::Animation()
{
	walk_index++;

	if (walk_index > 5)
	{
		walk_index = 0;
	}
}

void Title_player::Control(int d)
{
	if (d == 0)
	{
		position_X += vector * speed;
	}
	else if (d == 1)
	{
		position_X -= vector * speed;
	}
	else if(d == 2)
	{
		position_X = position_X;
	}

	if (position_X > witdh)
	{
		position_X = -192.0f;
	}
}
