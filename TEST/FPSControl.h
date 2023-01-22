#pragma once
#include "DxLib.h"
class FPSControl
{
public:
	FPSControl();
	~FPSControl();

	void Initialize(float RefreshRate, float UpdateTime);
	void Wait();
    void Draw();

private:
    int frame_time; //1フレームの時間(ミリ秒)
    int wait_time; //待ち時間
    int last_time, now_time; //最後に取得した時間と，今の時間
    float count; //フレームのカウント
    float fps; //表示するしたFPS値
    int update_time; //表示値を更新する時間
    int last_update; //最後に表示値を更新した時間

};

