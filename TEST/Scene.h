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

	//初期化
	virtual void Initialize() = 0;
	//毎フレーム処理
	virtual void Initialize() = 0;
	//描画
	virtual void Initialize() = 0;

	SceneNum GetScenenNum() { return num; }

	//ゲーム終了
	bool GetEndGame() { return end; }

	//ステージ番号を返す
	short GetStageNum() { return stageNum; }

	void SetStageNum(short stageNum) { this->stageNum = stageNum; }

	//シーン遷移
	bool GetNextScene() { return nextscene; }

	//ポーズ中
	bool isPause() { return pause; }

protected:
	SceneNum num;

	//シーン遷移で必要となるトリガー
	bool nextscene = false;
	//ステージ番号(1or2)
	short stageNum = 1;
	//ゲーム終了
	bool end = false;
	//スコア
	int score = 0;

	//ポーズフラグ
	bool pause;
};

