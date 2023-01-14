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
	if (position_X > 725.0f && pattern_Nuber ==0 )
	{
		direction = 4;
		
		if (count == 0)
		{
			timer->startTimer();
			count = 1;
		}
		
	}
	timer->Update();
	if (count == 1)
	{
		if (timer->elapsedTimer() > 3000)
		{
			direction = 0;
			
			position_Y = 576.0f;
			count = 2;
		}
	}

	Control(direction);


	//アニメ―ション
	if (direction != 4)
	{
		Animation();
	}
	

}

void Title_player::Draw()
{
	/*DrawGraph(position_X, position_Y, texture_R, TRUE);*/
	if (direction == 0)
	{
		DrawGraph(position_X, position_Y, walk_R[walk_index], TRUE);
	}
	else if(direction == 1)
	{
		DrawGraph(position_X, position_Y, walk_L[walk_index], TRUE);
	}
	else if(direction == 2)
	{
		DrawGraph(position_X, position_Y, texture_R, TRUE);
	}
	else if(direction == 3)
	{
		DrawGraph(position_X, position_Y, texture_L, TRUE);
	}
	else if(direction == 4)
	{
		DrawGraph(position_X, position_Y, hide_R, TRUE);
	}
	else if(direction == 5)
	{
		DrawGraph(position_X, position_Y, hide_L, TRUE);
	}
	
}

void Title_player::LoadTexture()
{
	texture_R = LoadGraph("Resources/Player/Player_R.png");
	texture_L = LoadGraph("Resources/Player/Player_L.png");
	hide_R = LoadGraph("Resources/Player/Assassin_Squat_R.png");
	hide_L = LoadGraph("Resources/Player/Assassin_Squat_L.png");
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
	else if( d == 3)
	{
		position_X = position_X;
	}
	else if (d == 4)
	{
		position_X = 600.0f;
		position_Y = 500.0f;
		pattern_Nuber = 1;
	}
	else if(d == 5)
	{
		position_X = 950.0f;
		position_Y = 500.0f;
	}

	if (position_X > witdh)
	{
		position_X = -192.0f;
		pattern_Nuber = 0;
		count = 0;
	}
}
