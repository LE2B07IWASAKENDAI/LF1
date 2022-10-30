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

	//初期化
	virtual void Initialize();
	//毎フレーム更新
	virtual void Update();
	//描画
	virtual void Draw();

public:
	SceneNum GetSceneNum() { return num; }

//Getter,Setter
public:
	//ゲーム終了
	bool GetEndGame() { return end; }
	//ステージ番号を返す
	short GetStageNum() { return stageNum; }

	void SetStageNum(short stageNum) { this->stageNum = stageNum; }
	//シーン遷移
	bool GetNextScene() { return nextscene; }

protected:

	SceneNum num;

	//シーン遷移で必要となるトリガー
	bool nextscene = false;
	//ステージ番号
	short stageNum = 1;
	//ゲーム終了
	bool end = false;

};

