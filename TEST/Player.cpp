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
	position_Y = 576.0f;
	death = 0;
	hide = 0;
	//drawPlayer = false;//隠れているときは描画しない
	keyPermission = false;
	keyCounter = 0;
	SetkeyPermission(false);

	/*ナイフ関連*/
		knife = new Knife();
		//初期化
		knife->Initialize();
		hitFlag = 0;
		diaspper_knife_trigger = 0;
}

void Player::Update()
{

	//移動処理(隠れていないとき)
	if (!GetkeyPermission()) {
		if (CheckHitKey(KEY_INPUT_A))
		{
			position_X = position_X - speed;
			rl = 1;
		}
		if (CheckHitKey(KEY_INPUT_D))
		{
			position_X = position_X + speed;
			rl = 0;
		}
	}

	//隠れている時以外は描画する
	if (hide == 0 || !GetHide()) {
		//画像読み込み
		
		if (rl == 0) {
			if (position_X >= end)
			{
				return_Positin = position_X - end + center;
				DrawGraph(position_X - end + center, position_Y, ptexture_R, TRUE);
			}
			else if (position_X >= center)
			{
				return_Positin = center;
				DrawGraph(center, position_Y, ptexture_R, TRUE);
			}
			else
			{
				return_Positin = position_X;
				DrawGraph(position_X, position_Y, ptexture_R, TRUE);
			}
		}
		else if(rl ==1)
		{
			if (position_X >= end)
			{
				return_Positin = position_X - end + center;
				DrawGraph(position_X - end + center, position_Y, ptexture_L, TRUE);
			}
			else if (position_X >= center)
			{
				return_Positin = center;
				DrawGraph(center, position_Y, ptexture_L, TRUE);
			}
			else
			{
				return_Positin = position_X;
				DrawGraph(position_X, position_Y, ptexture_L, TRUE);
			}
		}
		
		SetkeyPermission(false);
	}

	//隠れてる！の描画
	if (hide == 1) { DrawGraph(1602, 0, hidetext, FALSE); SetkeyPermission(true); }
	//現在の座標を文字列描画
	DrawPlayerPos();


////////////////ナイフ投げ処理////////////////////////////////

	//エンター押下時　ナイフ位置、トリガー更新
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && hide == 0)
	{
		keyCounter_knife++;
	}
	else
	{
		if (keyCounter_knife > 0)
		{
			keyCounter_knife = -1;
		}
		else
		{
			keyCounter_knife = 0;
		}
	}

	if (keyCounter_knife == 1)
	{
		//ナイフの発射位置をセット
		knife->Ready_Throw(GetPosition_x() + 100, GetPosition_Y() + 100);
		SetDisapperKnifeTrigger(0);
	}

	if (GetDisapperKnifeTrigger() == 1) {
		knife->Dead();
	}

	//ナイフ更新処理
	knife->Update();

	SetKnifePos(knife->GetPosition());
	hitFlag = knife->Getis_throw();
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
	if (keyCounter == 1 && hide == 0) {
		//扉に隠れたという演出で、描画をしないようにしている
		hide = 1;
	}
	else if (keyCounter == 1 && hide == 1) {
		//描画されていない時にLSHIFT押すと？
		hide = 0;//プレイヤーを描画する
		SetkeyPermission(false);
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
	ptexture_R = LoadGraph("Resources/Player/Player_R.png");
	ptexture_L = LoadGraph("Resources/Player/Player_L.png");
	hidetext = LoadGraph("Resources/Player/hidding2.png");
}

void Player::DrawPlayerPos()
{
	DrawFormatString(1607, 100, GetColor(255, 255, 255), "x座標 : %f",GetPosition_X());
	DrawFormatString(1607, 128, GetColor(255, 255, 255), "y座標 : %f",GetPosition_Y());
}