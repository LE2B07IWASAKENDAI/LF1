#pragma once
class Scene
{
protected:
	SceneManager* sceneManager;

public:
	Scene(SceneManager* p_sceneManager) { sceneManager = p_sceneManager; }
	
	virtual ~Scene();

public:
	enum SceneNum
	{
		title,
		gameplay,
		gameclear,
		gameover,
	};

	//������
	virtual void Initialize() = 0;
	//���t���[������
	virtual void Initialize() = 0;
	//�`��
	virtual void Initialize() = 0;

	SceneNum GetScenenNum() { return num; }

	//�Q�[���I��
	bool GetEndGame() { return end; }

	//�X�e�[�W�ԍ���Ԃ�
	short GetStageNum() { return stageNum; }

	void SetStageNum(short stageNum) { this->stageNum = stageNum; }

	//�V�[���J��
	bool GetNextScene() { return nextscene; }

	//�|�[�Y��
	bool isPause() { return pause; }

protected:
	SceneNum num;

	//�V�[���J�ڂŕK�v�ƂȂ�g���K�[
	bool nextscene = false;
	//�X�e�[�W�ԍ�(1or2)
	short stageNum = 1;
	//�Q�[���I��
	bool end = false;
	//�X�R�A
	int score = 0;

	//�|�[�Y�t���O
	bool pause;
};

