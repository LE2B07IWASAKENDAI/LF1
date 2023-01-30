#include "KnifeCounter.h"

KnifeCounter::KnifeCounter()
{
}

KnifeCounter::~KnifeCounter()
{
}

void KnifeCounter::Initialize()
{
	count = 5;
	positionX = 1630;
	positionY = 30;

	positionX_k = 1500;
	positionY_k = 40;

	positionX_x = 1550;
	positionY_y = 40;

	LoadTexture();
}

void KnifeCounter::Update()
{
}

void KnifeCounter::LoadTexture()
{
	ghandle[0] = LoadGraph("Resources/Player/Number0.png");
	ghandle[1] = LoadGraph("Resources/Player/Number1.png");
	ghandle[2] = LoadGraph("Resources/Player/Number2.png");
	ghandle[3] = LoadGraph("Resources/Player/Number3.png");
	ghandle[4] = LoadGraph("Resources/Player/Number4.png");
	ghandle[5] = LoadGraph("Resources/Player/Number5.png");

	gh_knife = LoadGraph("Resources/Player/BeamSwordCounter.png");
	gh_x = LoadGraph("Resources/Player/x.png");
}

void KnifeCounter::DisCount()
{
	count--;
}


void KnifeCounter::Draw()
{
	DrawGraph(positionX, positionY, ghandle[count], TRUE);
}

void KnifeCounter::AlwaysDraw()
{
	//gh_knife
	DrawGraph(positionX_k, positionY_k, gh_knife, TRUE);
	//gh_x
	DrawGraph(positionX_x, positionY_y, gh_x, TRUE);
}
