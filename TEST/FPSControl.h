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
    int frame_time; //1�t���[���̎���(�~���b)
    int wait_time; //�҂�����
    int last_time, now_time; //�Ō�Ɏ擾�������ԂƁC���̎���
    float count; //�t���[���̃J�E���g
    float fps; //�\�����邵��FPS�l
    int update_time; //�\���l���X�V���鎞��
    int last_update; //�Ō�ɕ\���l���X�V��������

};

