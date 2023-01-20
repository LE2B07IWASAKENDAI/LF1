#pragma once
#include "DxLib.h"

class E_Light
{
public:
	E_Light();
	~E_Light();

	void Initialize();
	void Update(float enemy_x,float enemy_y,int flont);
	void Draw();
	//void 

private:
	int ghandleL, ghandleR, ghandle;
	int flont;
	float position_X, position_Y;

};

