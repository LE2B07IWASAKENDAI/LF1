#pragma once
#include"Player.h"

class DebugClass
{
	Player* player = nullptr;

public:
	void Initialize();
	void Update();
	void Draw();
};

