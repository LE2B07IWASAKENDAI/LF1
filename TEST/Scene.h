#pragma once

class Scene
{
public:
	enum SceneNum
	{
		title,
		gameplay,
		gameover,
		gameclear,
	};

public:
	virtual ~Scene();

	//������
	virtual void Initialize();
	//���t���[���X�V
	virtual void Update();
	//�`��
	virtual void Draw();

public:
	SceneNum GetSceneNum() { return num; }

//Getter,Setter
public:
	//�Q�[���I��
	bool GetEndGame() { return end; }
	//�X�e�[�W�ԍ���Ԃ�
	short GetStageNum() { return stageNum; }

	void SetStageNum(short stageNum) { this->stageNum = stageNum; }
	//�V�[���J��
	bool GetNextScene() { return nextscene; }

protected:

	SceneNum num;

	//�V�[���J�ڂŕK�v�ƂȂ�g���K�[
	bool nextscene = false;
	//�X�e�[�W�ԍ�
	short stageNum = 1;
	//�Q�[���I��
	bool end = false;

};

