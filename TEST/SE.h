#pragma once
#include "DxLib.h"
class SE
{
public:

	void Initialize();
	void  CrackSE();
	void  DiscoverSE_voice();
	void  KillSE_voice();


private:
	int soundHandle[3];
};

