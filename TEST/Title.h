#pragma once
#include"Scene.h"
#include"DxLib.h"

class Title:public Scene
{
public:
	//�R���X�g���N�^
	Title();
	//�f�X�g���N�^
	~Title();

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	int handle;
};

