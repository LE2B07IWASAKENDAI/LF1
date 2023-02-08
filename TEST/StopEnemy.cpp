#include "StopEnemy.h"

StopEnemy::StopEnemy()
{

}

StopEnemy::~StopEnemy()
{

}

void StopEnemy::Initialize()
{
	LoadTexture();
	flont = 0;
	death = 0;
	count = 0;
	checkCount = 0;
	Mode = 0;
	//‰¼À•W(Œˆ‚ß‘Å‚¿)
	//position_X = 500;
	//position_Y = 500;
	light = new E_Light();
	light->Initialize();
	death_indec = 0;
	death_Xvector = 0;
	death_Yvector = 0;
	death_X = 0.0f;
	death_Y = 0.0f;
	a = 100;
}

void StopEnemy::Horizon()
{
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

	if (flont == 1)
	{
		StopEtexture = LoadGraph("Resources/Enemy/Yakuza2Light_R.png");
	}
	else if (flont == 0)
	{
		StopEtexture = LoadGraph("Resources/Enemy/Yakuza2Light_L.png");
	}
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

void StopEnemy::Dead()
{
	SetDeath(1);
}

void StopEnemy::Monitoring()
{
	switch (Mode)
	{
	case Normal:
		count++;
		if (count <= 100)
		{
			flont = 1;
		}
		else if (count >= 101 && count < 200)
		{
			flont = 0;
		}
		else if (count > 200)
		{
			count = 0;
		}
		break;
	case Check:
		if (position_X > BreakPoint)
		{
			flont = 0;
			if (EqualFlag == 0)
			{
				speed_ = -5;
			}
		}
		if (position_X < BreakPoint)
		{
			flont = 1;
			if (EqualFlag == 0)
			{
				speed = 5;
			}
		}

		if (position_X + 10 > BreakPoint && position_X - 10 < BreakPoint)
		{
			speed = 0;
			speed_ = 0;
			EqualFlag = 1;
		}

		if (EqualFlag == 1)
		{
			checkCount++;
		}

		if (checkCount >= 1 && checkCount < 100)
		{
			flont = 0;
		}
		else if (checkCount >= 101 && checkCount < 200)
		{
			flont = 1;
		}
		else if (checkCount >= 201)
		{
			Mode = Back;
			checkCount = 0;
			EqualFlag = 0;
		}
		break;
	case Back:
		if (position_X > before_position_X)
		{
			speed_ = -5;
		}
		else if (position_X < before_position_X)
		{
			speed = 5;
		}

		if (position_X == before_position_X)
		{
			speed = 0;
			speed_ = 0;
			Mode = Normal;
		}
	}
	light->Update(GetPosition_X(), Getposition_Y(), GetFlont());
}

void StopEnemy::DeadAnime()
{
	if (death_Xvector > 5 && deathX_LR == 0)
	{
		deathX_LR = 1;
	}
	else if (death_Xvector < -5 && deathX_LR == 1)
	{
		deathX_LR = 0;
	}

	if (deathX_LR == 0)
	{
		death_Xvector += death_speedX;
		death_X += death_speedX;
		death_x += death_X;

	}
	else if (deathX_LR == 1)
	{
		death_Xvector -= death_speedX;
		death_X -= death_speedX;
		death_x -= death_X;
	}

	if (death_y < death_Yvector - 100)
	{
		death_indec = 0;
	}

	a--;
	death_y -= death_speedY;
}

void StopEnemy::DeadAnimeSet(float x, float y)
{
	death_Yvector = y;
	death_x = x;
	death_y = y;
}

void StopEnemy::Update()
{
	if (GetDeath() == 0) {
		Monitoring();
		DeadAnimeSet(GetPosition_X(), Getposition_Y());
	}
	if (death == 1)
	{

		death_indec = 1;
		death = 2;
	}

	if (death_indec == 1)
	{

		DeadAnime();
	}
}

void StopEnemy::LoadTexture()
{
	StopEtexture = LoadGraph("Resources/Enemy/Yakuza2Light_R.png");
	death_anime = LoadGraph("Resources/Enemy/Enemy2Dokuro.png");
}

void StopEnemy::Draw()
{
	if (GetDeath() == 0) {
		Horizon();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(position_X, position_Y, StopEtexture, TRUE);
		light->Draw();
	}

	if (death_indec == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);
		DrawGraph(death_x, death_y, death_anime, TRUE);
	}
	//DebugLog();
}

void StopEnemy::DebugLog()
{
	DrawFormatString(7, 300, GetColor(255, 255, 255), "count : %d", count);
	DrawFormatString(7, 360, GetColor(255, 255, 255), "Mode : %d", Mode);
}

void StopEnemy::Set_position(float position_x, float position_y)
{
	position_X = position_x;
	position_Y = position_y;

	before_position_X = position_X;
}

void StopEnemy::Breaking(float x)
{
	BreakPoint = x;
}

void StopEnemy::CheckSound()
{
	Mode = Check;
}