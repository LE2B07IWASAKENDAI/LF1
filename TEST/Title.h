#pragma once
#include"Scene.h"
#include"DxLib.h"

class Title:public Scene
{
public:
	//コンストラクタ
	Title();
	//デストラクタ
	~Title();

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	int handle;
};

