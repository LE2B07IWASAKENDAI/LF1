#include "knife.h"

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
	life = 100;
	position_X = 0;
	position_Y = 0;
	speed = 10.0f;
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
	//右方向へ加算
	position_X += speed;
	//生存時間を減らす
	life--;
}

void Knife::Dead()
{
//リセット
	//ライフ
	life = 100;
	//投げるフラグ
	is_throw = 0;
	//位置
	position_X = 0;
}

void Knife::Update()
{
	if (is_throw == 1) {
		Throw();
		//lifeが0以上なら描画それ以外は死亡処理
		life >= 0 ? Draw() : Dead();
	}
	DrawFormatString(0, 200, GetColor(255, 255, 255), "life : %d", life);
	DrawFormatString(0, 250, GetColor(255, 255, 255), "position : %f", GetPosition());
}

void Knife::Draw()
{
	DrawGraph(position_X,position_Y, knifetex, TRUE);
}

void Knife::LoadTexture()
{
	knifetex = LoadGraph("Resources/Player/Knife.png");
}
