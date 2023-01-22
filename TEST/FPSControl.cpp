#include "FPSControl.h"

FPSControl::FPSControl()
{
}

FPSControl::~FPSControl()
{
}

void FPSControl::Initialize(float RefreshRate, float UpdateTime)
{
    frame_time = (int)(1000.0f / RefreshRate); //1�t���[���̎��Ԃ̌v�Z
    update_time = UpdateTime;
    wait_time = 0;
    last_time = now_time = 0;
    count = 0.0f;
    fps = 0.0f;
    last_update = 0;
}

void FPSControl::Wait()
{
    count += 1.0f;
    if (update_time < (last_time - last_update)) { //�A�b�v�f�[�g���ԂɂȂ��Ă����
        fps = count / (float)(last_time - last_update) * 1000.0f; //FPS�l�̌v�Z
        last_update = last_time;
        count = 0.0f;
    }

    now_time = GetNowCount();
    wait_time = frame_time - (now_time - last_time);
    if (wait_time > 0) { //�҂����Ԃ������
        WaitTimer(wait_time); //�w�莞�ԑ҂�
    }
    last_time = GetNowCount();
}

void FPSControl::Draw()
{
    DrawFormatString(7, 180, GetColor(255, 255, 255), "fps : %0.1f", fps);
    
}
