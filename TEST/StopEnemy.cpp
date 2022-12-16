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
	//âºç¿ïW(åàÇﬂë≈Çø)
	//position_X = 500;
	//position_Y = 500;
}

void StopEnemy::Horizon()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

	if (flont == 1)
	{
		StopEtexture = LoadGraph("Resources/Enemy/01_Enemy_R.png");
		//DrawBox(GetPosition_X(), position_Y, GetPosition_X() + 450, position_Y + 192, GetColor(255, 0, 0), true);
		DrawBox(position_X, position_Y, position_X + 450, position_Y + 192, GetColor(255, 0, 0), true);
	}
	else if (flont == 0)
	{
		StopEtexture = LoadGraph("Resources/Enemy/01_Enemy_L.png");
		//DrawBox(GetPosition_X() - 250, position_Y, GetPosition_X() + 192, position_Y + 192, GetColor(255, 0, 0), true);
		DrawBox(position_X - 250, position_Y, position_X + 192, position_Y + 192, GetColor(255, 0, 0), true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

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
}

void StopEnemy::Update()
{
	if (GetDeath() == 0) {
		Horizon();
		Monitoring();
	}
}

void StopEnemy::LoadTexture()
{
	StopEtexture = LoadGraph("Resources/Enemy/01_Enemy_R.png");
}

void StopEnemy::Draw()
{
	if (GetDeath() == 0) {
		DrawGraph(position_X, position_Y, StopEtexture, TRUE);
	}
	//DebugLog();
}

//void StopEnemy::DebugLog()
//{
//	DrawFormatString(1607, 180, GetColor(255, 255, 255), "vector + eye : %f", position_X);
//	DrawFormatString(7, 180, GetColor(255, 255, 255), "FirstPosition : %f", before_position_X);
//	DrawFormatString(7, 280, GetColor(255, 255, 255), "eye : %f", eye);
//	DrawFormatString(7, 300, GetColor(255, 255, 255), "position_X : %f", position_X);
//	DrawFormatString(7, 400, GetColor(255, 255, 255), "Knife_position_X : %f", knife->GetPosition());
//}

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