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
	LoadTexture();
	Cariculate();
}

void KnifeCounter::Cariculate()
{
	for (int i = 0; i < 5; i++) {
		positionX.push_back(i * 80 + 1400);
		positionY.push_back(40);
	}
}

void KnifeCounter::Update()
{
}

void KnifeCounter::LoadTexture()
{
	ghandle = LoadGraph("Resources/Player/Knife.png");
}

void KnifeCounter::Delete()
{
	positionX.erase(positionX.end() - 1);
	positionY.erase(positionY.end() - 1);
}

void KnifeCounter::Draw()
{
	for (int i = 0; i < positionX.size(); i++) {
		DrawGraph(positionX[i], positionY[i], ghandle, TRUE);
	}
}
