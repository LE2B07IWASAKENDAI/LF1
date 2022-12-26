#pragma once
#include"Scene.h"

#include"Title.h"
#include"Select.h"
#include"GamePlay.h"
#include"GameClear.h"
#include"GameOver.h"

class SceneManager
{
	SceneManager();
	~SceneManager();

	void Update();
	void Draw();
	void Initialize();

	bool EndGame();

private:
	Scene* scene = nullptr;

	int back;
};

