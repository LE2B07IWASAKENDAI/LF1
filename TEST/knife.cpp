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
	vector_x = 15.0f;
	vector_y = 1.05f;
	front = 0;
	stock = 10;
}

void Knife::Ready_Throw(float Ppos_x, float Ppos_y,int flont)
{
	//ナイフが画面内に無ければ
	if (Getis_throw() == 0) {

		//プレイヤーの現在位置格納
		position_X = Ppos_x;
		position_Y = Ppos_y;

		//更新：ナイフが画面内にある
		is_throw = 1;
	}
	front = flont;
	SetDirection();
}

void Knife::Throw()
{
	if (front == 0) {
		//右にとんでく
		position_X = position_X + vector_x;
		position_Y += vector_y;
	}
	else if (front == 1) {
		position_X = position_X - vector_x;
		position_Y += vector_y;
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
	if (stock <= 0)
	{
		is_throw = -1;
		stock = 0;
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
	//DrawFormatString(0, 200, GetColor(255, 255, 255), "life : %d", life);
	//DrawFormatString(0, 250, GetColor(255, 255, 255), "position_X : %f", GetPosition());
}

void Knife::Draw()
{	
	//右方向
	DrawRotaGraph(position_X, position_Y, 1.0f, PI * (1 / 4 * (float)direction), knifetex[front], TRUE);
}

void Knife::Cariculate()
{
}

void Knife::LoadTexture()
{
	knifetex[0] = LoadGraph("Resources/Player/ThrowingKnife.png");
	knifetex[1] = LoadGraph("Resources/Player/ThrowingKnife_copy.png");
}
