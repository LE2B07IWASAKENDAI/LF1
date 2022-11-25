#include "Player.h"

Player::Player()
{

}

Player::~Player()
{
}


void Player::Initialize()
{
	LoadTexture();
	position_X = 0.0f;
	position_Y = 600.0f;
	death = 0;
	hide = 0;
	drawPlayer = false;//隠れているときは描画しない
	keyPermission = false;
	keyCounter = 0;
	SetkeyPermission(false);

	Kposition_X = -400.0f;
	Kposition_Y = 600.0f;
	Kspeed = 40.0f;
}

void Player::Update()
{

	//移動処理(隠れていないとき)
	if (!GetkeyPermission()) {
		if (CheckHitKey(KEY_INPUT_A))
		{
			position_X = position_X - speed;
		}
		if (CheckHitKey(KEY_INPUT_D))
		{
			position_X = position_X + speed;
		}
	}

	//Trueなら隠れるという関数を呼びだす。
	if (GetHide()) { Hidding(); }

	//隠れている時以外は描画する
	if (!drawPlayer || !GetHide()) {
		//画像読み込み
		
		if(position_X >= end )
		{
			return_Positin = position_X - end + center;
			DrawGraph(position_X - end + center, position_Y, ptexture, FALSE);
		}
		else if (position_X >= center)
		{
			return_Positin = center;
			DrawGraph(center, position_Y, ptexture, FALSE);
		}
		else
		{
			return_Positin = position_X;
			DrawGraph(position_X, position_Y, ptexture, FALSE);
		}
		
		SetkeyPermission(false);
	}

	//隠れてる！の描画
	if(drawPlayer){ DrawGraph(1602, 0, hidetext, FALSE); SetkeyPermission(true);}
	//現在の座標を文字列描画
	DrawPlayerPos();

	//ナイフ投げ
	//Zキー押下時ナイフをプレイヤーの座標へ
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && ShootFlag == 0)
	{
		Kposition_X = position_X + 200;
		Kposition_Y = position_Y + 50;
		if (position_X > center)
		{
			Kposition_X = center + 200;
		}

		ShootFlag = 1;
	}
	//ナイフ移動処理
	if (ShootFlag == 1)
	{
		Kposition_X = Kposition_X + Kspeed;
		DrawGraph(Kposition_X, Kposition_Y, knifetex, FALSE);

	}

}

void Player::Draw()
{

}

bool Player::GetHide()
{
	return hide;
}

void Player::SetHide(bool sethide)
{
	hide = sethide;
}

void Player::Hidding()
{
	//隠れる
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		keyCounter++;
	}
	else
	{
		//キー押されていない
		if (keyCounter > 0)keyCounter = -1;//LSHIFTキーが離れた瞬間
		else { keyCounter = 0; }           //LSHIFTキーが離れている状態


	}

	//押された瞬間の処理
	if (keyCounter == 1 && drawPlayer) {
		//扉に隠れたという演出で、描画をしないようにしている(11/11)
		drawPlayer = false;
		ShootFlag = 0;
	}
	else if (keyCounter == 1 && !drawPlayer) {
		//描画されていない時にLSHIFT押すと？
		drawPlayer = true;//プレイヤーを描画する
		SetkeyPermission(false);
		ShootFlag = -1;
	}
}

float Player::GetPosition_X()
{
	return position_X;
}

float Player::GetPosition_x()
{
	return return_Positin;
}

float Player::GetPosition_Y()
{
	return position_Y;
}

float Player::SetPosition(float x, float y)
{
	position_X = x;
	position_Y = y;

	return 0;
}

int Player::GetDeath()
{
	return death;
}

int Player::SetDeath(int d)
{
	death = d;

	return 0;
}


void Player::LoadTexture()
{
	ptexture = LoadGraph("Resources/Player/green.png");
	hidetext = LoadGraph("Resources/Player/hidding2.png");
	knifetex = LoadGraph("Resources/Player/Knife.png");
}

void Player::DrawPlayerPos()
{
	DrawFormatString(1607, 100, GetColor(255, 255, 255), "x座標 : %f",GetPosition_X());
	DrawFormatString(1607, 128, GetColor(255, 255, 255), "y座標 : %f",GetPosition_Y());
}