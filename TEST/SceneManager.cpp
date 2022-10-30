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

	//�V�[���ڍs��true�Ȃ��
	if (scene->GetNextScene())
	{
		//���̃V�[���ԍ��ɁA�ڍs��̃V�[���ԍ�����
		Scene::SceneNum nextNum = scene->GetSceneNum();
	}
}

void SceneManager::Draw()
{
	scene->Draw();
}
