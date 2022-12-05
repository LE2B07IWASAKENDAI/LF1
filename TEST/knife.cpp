#include "knife.h"

#define PI 3.1415926535897932384626433832795f

Knife::Knife()
{
}

Knife::~Knife()
{
}

void Knife::Initialize()
{
	LoadTexture();
	is_throw = 0;
	life = 30;
	position_X = 0;
	position_Y = 0;
	speed = 20.0f;
	front = 0;
	Counter = 0;
	stock = 10;
}

void Knife::Ready_Throw(float Ppos_x, float Ppos_y)
{
	//ナイフが画面内に無ければ
	if (Getis_throw() == 0) {

		//プレイヤーの現在位置格納
		position_X = Ppos_x;
		position_Y = Ppos_y;

		//更新：ナイフが画面内にある
		is_throw = 1;
	}
}

void Knife::Throw()
{
	if (front == 0)
	{
		//右にとんでく
		position_X += speed;
		position_Y += speed / 20;
	}
	else if (front == 1)
	{
		//左にとんでく
		position_X -= speed;
		position_Y += speed / 20;
	}

	//移動方向によって向きを変える
	if (CheckHitKey(KEY_INPUT_A))
	{
		Counter++;
	}
	else
	{
		if (Counter > 0)
		{
			Counter = -1;
		}
		else
		{
			Counter = 0;
		}
	}
	if (Counter == 1)
	{
		front = 1;
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		Counter++;
	}
	else
	{
		if (Counter > 0)
		{
			Counter = -1;
		}
		else
		{
			Counter = 0;
		}
	}
	if (Counter == 1)
	{
		front = 0;
	}

	//生存時間を減らす
	life--;

	
}

void Knife::Dead()
{
	//リセット
	//ライフ
	life = 30;
	//投げるフラグ
	is_throw = 0;
	//位置
	position_X = 0;
	//残機
	stock--;
	if (stock == 0)
	{
		is_throw = -1;
	}
}

void Knife::Update()
{
	if (is_throw == 1) {
		Throw();
		//lifeが0以上なら描画それ以外は死亡処理
		life >= 0 ? Draw() : Dead();
		
		
	}
	DrawFormatString(0, 225, GetColor(255, 255, 255), "stock : %d", stock);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "life : %d", life);
	DrawFormatString(0, 250, GetColor(255, 255, 255), "position : %f", GetPosition());
}

void Knife::Draw()
{
	if (front == 0)
	{
		//右方向
		DrawRotaGraph(position_X, position_Y, 1.0f, PI * 3 / 4, knifetexR, TRUE);
	}
	else if (front == 1)
	{
		//左方向
		DrawRotaGraph(position_X, position_Y, 1.0f, PI * -1 / 4, knifetexL, TRUE);
	}
}

void Knife::LoadTexture()
{
	knifetexR = LoadGraph("Resources/Player/KnifeR.png");
	knifetexL = LoadGraph("Resources/Player/KnifeL.png");
}
