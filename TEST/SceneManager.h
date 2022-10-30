#pragma once
#include"Scene.h"
#include"Title.h"
#include"Play.h"
#include"GameOver.h"


class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Initialize();
	void Update();
	void Draw();

private:
	Scene* scene = nullptr;
	int saveStageNum;
};

