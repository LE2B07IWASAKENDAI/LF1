#include "E_Light.h"

E_Light::E_Light()
{
}

E_Light::~E_Light()
{
}

void E_Light::Initialize()
{
	ghandleL = LoadGraph("Resources/Enemy/Flashlight_L.png");
	ghandleR = LoadGraph("Resources/Enemy/Flashlight.png");
}

void E_Light::Update(float enemy_x, float enemy_y,int flont)
{
	position_X = enemy_x;
	position_Y = enemy_y;
	this->flont = flont;

	if (flont == 1)
	{
		ghandle = ghandleR;
	}
	else if (flont == 0)
	{
		ghandle = ghandleL;
	}
}

void E_Light::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);

	if (flont == 0) {
		//ç∂å¸Ç´
		DrawGraph(position_X - 150, position_Y + 30, ghandle, true);
	}
	else if(flont == 1)
	{
		//âEå¸Ç´
		DrawGraph(position_X + 135, position_Y + 30, ghandle, true);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
