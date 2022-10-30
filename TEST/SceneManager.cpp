#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	delete scene;
}

void SceneManager::Initialize()
{
	scene = new Title();
	scene->Initialize();
}

void SceneManager::Update()
{
	scene->Update();

	//シーン移行がtrueならば
	if (scene->GetNextScene())
	{
		//今のシーン番号に、移行後のシーン番号を代入
		Scene::SceneNum nextNum = scene->GetSceneNum();
	}
}

void SceneManager::Draw()
{
	scene->Draw();
}
