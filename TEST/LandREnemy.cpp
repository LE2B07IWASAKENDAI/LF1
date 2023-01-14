#include "LandREnemy.h"

LandREnemy::LandREnemy()
{

}

LandREnemy::~LandREnemy()
{

}

void LandREnemy::Initialize()
{
	LoadTexture();
	flont = 0;
	death = 0;
	//count = 0;
	//checkCount = 0;
	//‰¼À•W(Œˆ‚ß‘Å‚¿)
	//position_X = 500;
	//position_Y = 500;
}

void LandREnemy::Horizon()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

	if (flont == 1)
	{
		LandREtexture = LoadGraph("Resources/Enemy/Yakuza2Light_R.png");
		//DrawBox(GetPosition_X(), position_Y, GetPosition_X() + 450, position_Y + 192, GetColor(255, 0, 0), true);
		DrawBox(position_X, position_Y, position_X + 450, position_Y + 192, GetColor(255, 0, 0), true);
	}
	else if (flont == 0)
	{
		LandREtexture = LoadGraph("Resources/Enemy/Yakuza2Light_L.png");
		//DrawBox(GetPosition_X() - 250, position_Y, GetPosition_X() + 192, position_Y + 192, GetColor(255, 0, 0), true);
		DrawBox(position_X - 250, position_Y, position_X + 192, position_Y + 192, GetColor(255, 0, 0), true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

void LandREnemy::Dead()
{
	SetDeath(1);
}

void LandREnemy::Monitoring()
{
	switch (Mode)
	{
	case Normal:
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
			Mode = Normal;
		}
		break;
	}
}

void LandREnemy::Update()
{
	if (GetDeath() == 0) {
		Horizon();
		Monitoring();
	}
}

void LandREnemy::LoadTexture()
{
	LandREtexture = LoadGraph("Resources/Enemy/Yakuza2Light_R.png");
}

void LandREnemy::Draw()
{
	if (GetDeath() == 0) {
		DrawGraph(position_X, position_Y, LandREtexture, TRUE);
	}
	//DebugLog();
}

void LandREnemy::Set_position(float position_x, float position_y)
{
	position_X = position_x;
	position_Y = position_y;
}

void LandREnemy::Breaking(float x)
{
	BreakPoint = x;
}

void LandREnemy::CheckSound()
{
	Mode = Check;
}