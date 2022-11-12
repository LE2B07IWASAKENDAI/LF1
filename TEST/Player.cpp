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
	notDrawPlayer = false;//‰B‚ê‚Ä‚¢‚é‚Æ‚«‚Í•`‰æ‚µ‚È‚¢
	keyPermission = false;
	keyCounter = 0;
	SetkeyPermission(false);
}

void Player::Update()
{

	//ˆÚ“®ˆ—(‰B‚ê‚Ä‚¢‚È‚¢‚Æ‚«)
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

	//True‚È‚ç‰B‚ê‚é‚Æ‚¢‚¤ŠÖ”‚ğŒÄ‚Ñ‚¾‚·B
	if (GetHide()) { Hidding(); }

	//‰B‚ê‚Ä‚¢‚éˆÈŠO‚Í•`‰æ‚·‚é
	if (!notDrawPlayer || !GetHide()) {
		//‰æ‘œ“Ç‚İ‚İ
		DrawGraph(position_X, position_Y, ptexture, FALSE);
		SetkeyPermission(false);
	}

	//‰B‚ê‚Ä‚éI‚Ì•`‰æ
	if(notDrawPlayer){ DrawGraph(1602, 0, hidetext, FALSE); SetkeyPermission(true);}
	//Œ»İ‚ÌÀ•W‚ğ•¶š—ñ•`‰æ
	DrawPlayerPos();
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
	//‰B‚ê‚é
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		keyCounter++;
	}
	else
	{
		//ƒL[‰Ÿ‚³‚ê‚Ä‚¢‚È‚¢
		if (keyCounter > 0)keyCounter = -1;//LSHIFTƒL[‚ª—£‚ê‚½uŠÔ
		else { keyCounter = 0; }           //LSHIFTƒL[‚ª—£‚ê‚Ä‚¢‚éó‘Ô
	}

		//‰Ÿ‚³‚ê‚½uŠÔ‚Ìˆ—
		if (keyCounter == 1 && notDrawPlayer) {
			//”à‚É‰B‚ê‚½‚Æ‚¢‚¤‰‰o‚ÅA•`‰æ‚ğ‚µ‚È‚¢‚æ‚¤‚É‚µ‚Ä‚¢‚é(11/11)
			notDrawPlayer = false;
		}
		else if (keyCounter == 1 && !notDrawPlayer) {
			//•`‰æ‚³‚ê‚Ä‚¢‚È‚¢‚ÉLSHIFT‰Ÿ‚·‚ÆH
			notDrawPlayer = true;//ƒvƒŒƒCƒ„[‚ğ•`‰æ‚·‚é
			SetkeyPermission(false);
		}
}

float Player::GetPosition_X()
{
	return position_X;
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
}

void Player::DrawPlayerPos()
{
	DrawFormatString(1607, 100, GetColor(255, 255, 255), "xÀ•W : %f",GetPosition_X());
	DrawFormatString(1607, 128, GetColor(255, 255, 255), "yÀ•W : %f",GetPosition_Y());
}