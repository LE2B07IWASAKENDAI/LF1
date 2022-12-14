#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	LoadTexture();
	count = 0;
	flont = 0;
	death = 0;
	Mode = Normal;

//オブジェクト生成
	knife = new Knife();
	collision = new Collision();
	vase = new Vase();
}

void Enemy::Movement()
{
	//トリガー毎でスピードを変化
	if (flont == 0)
	{
		vector += speed_;
	}
	else if(flont == 1)
	{
		vector += speed;
	}

	position_X += vector;


	//初期位置と現在位置の座標差を取得

	switch (Mode)
	{
	case Normal:
		movement_position_X = position_X - before_position_X;
		//移動量が一定値超えたら反対方向へ走る///////////////////
		if (movement_position_X <= -1000)
		{
			count++;
			//停止処理
			if (count <= 150)
			{
				speed = 0;
				speed_ = 0;
			}
			else if (count >= 151)
			{
				speed = 5;
				speed_ = -5;
				count = 0;
				flont = 1;
			}
		}
		else if (movement_position_X >= 1000)
		{
			count++;
			//停止処理
			if (count <= 150)
			{
				speed = 0;
				speed_ = 0;
			}
			else if (count >= 151)
			{
				speed = 5;
				speed_ = -5;
				count = 0;
				flont = 0;
			}
		}
		break;
	case Check:
		if (position_X > BreakPoint)
		{
			flont = 0;
			if (speed_ == 0 && EqualFlag == 0)
			{
				speed_ = -5;
			}
		}
		if (position_X < BreakPoint)
		{
			flont = 1;
			if (speed == 0 && EqualFlag == 0)
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
			count++;
		}

		if (count >= 1 && count < 100)
		{
			flont = 0;
		}
		else if (count >= 101 && count < 200)
		{
			flont = 1;
		}
		else if (count >= 201)
		{
			Mode = Normal;
			count = 0;
			speed = 5;
			speed_ = -5;
			EqualFlag = 0;
		}
		break;
	}
}

void Enemy::Horizon()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

	if (flont == 1)
	{
		Etexture = LoadGraph("Resources/Enemy/01_Enemy_R.png");
		DrawBox(GetPosition_X(), position_Y, GetPosition_X() + 450, position_Y + 192, GetColor(255, 0, 0), true);
	}
	else if (flont == 0)
	{
		Etexture = LoadGraph("Resources/Enemy/01_Enemy_L.png");
		DrawBox(GetPosition_X() - 250, position_Y, GetPosition_X() + 192, position_Y + 192, GetColor(255, 0, 0), true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

void Enemy::Dead()
{
	SetDeath(1);
}

void Enemy::Update()
{
	if (GetDeath() == 0) {
		Movement();
	}
}

void Enemy::LoadTexture()
{
	Etexture = LoadGraph("Resources/Enemy/01_Enemy_R.png");
}

void Enemy::Draw()
{
	if (GetDeath() == 0) {
		Horizon();
		DrawGraph(position_X, position_Y, Etexture, TRUE);
	}
	DebugLog();
}

void Enemy::DebugLog()
{
	//DrawFormatString(1607, 180, GetColor(255, 255, 255), "vector + eye : %f", position_X);
	//DrawFormatString(7, 180, GetColor(255, 255, 255), "FirstPosition : %f", before_position_X);
	//DrawFormatString(7, 300, GetColor(255, 255, 255), "position_X : %f", position_X);
	//DrawFormatString(7, 400, GetColor(255, 255, 255), "Knife_position_X : %f", knife->GetPosition());
}

void Enemy::Set_position(float position_x, float position_y)
{
	position_X = position_x;
	position_Y = position_y;

	before_position_X = position_X;
}

void Enemy::Breaking(float x)
{
	BreakPoint = x;
}

void Enemy::CheckSound()
{
	Mode = Check;
}