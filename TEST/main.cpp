#include "DxLib.h" 
#include "MapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
//#include "knife.h";


int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow

)
{
    //�E�B���h�E���[�h�ɐݒ� 
    ChangeWindowMode(TRUE);

    const char TITLE[] = "title01";

    const int WIN_HEIGHT = 900;
    const int WIN_WITDH = 1800;



    // �E�B���h�E�̃^�C�g��
    //SetMainWindowText("title01");
    //�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A 
    //���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ��� 
    SetWindowSizeChangeEnableFlag(FALSE, FALSE);

    // ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�
    SetGraphMode(WIN_WITDH, WIN_HEIGHT, 32);

    // ��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
    SetWindowSizeExtendRate(1.0);

    // ��ʂ̔w�i�F��ݒ肷��
    SetBackgroundColor(0, 0, 0);

    //Dx���C�u������������ 
    if (DxLib_Init() == -1)
    {
        //�G���[���o����}�C�i�X�l��Ԃ��ďI�� 
        return -1;
    }
    SetDrawScreen(DX_SCREEN_BACK);



    MapChip* mapChip = new MapChip();
    Player* player = new Player();
    Enemy* enemy = new Enemy();
    Collision* collision = new Collision();
    //knife* Knife = new knife();
    mapChip->Initialize();
    player->Initialize();
    enemy->Initialize();
    //Knife->Initialize();

    //�Q�[�����[�v
    int GameState;
    enum GameState
    {
        Title,
        GamePlay1,
        GamePlay2,
        GamePlay3,
        GameOver,
        GameClear
    };

    GameState = Title;

    //�w�i(�v���g)
    int titlescene = LoadGraph("Resources/Scene/title.png");
    int gameoverscene = LoadGraph("Resources/Scene/GameOver.png");
    int gameclearscene = LoadGraph("Resources/Scene/GameClear.png");
    int bgscene1 = LoadGraph("Resources/Scene/bg1.png");
    int bgscene2 = LoadGraph("Resources/Scene/bg2.png");
    int bgscene3 = LoadGraph("Resources/Scene/bg3.png");

    int SCounter = 0;

    int load = 0;

    static bool mapInit = true;
    //���[�v�e�X�g�p
    //int StartTime;

    //FPS�̌Œ�Ŏg���ϐ�
    double dNextTime = GetNowCount();


    while (1)
    {
        //�Q�[�����W�b�N
        //����ʂ�����
        ClearDrawScreen();
        //60FPS�ł̌Œ�
        dNextTime += 16.66f;
        if (dNextTime > GetNowCount())
        {
            WaitTimer((int)dNextTime - GetNowCount());
        }

        //�Q�[�����[�v
        switch (GameState)
        {
        case Title:
            //������
            mapChip->Initialize();
            player->Initialize();
            enemy->Initialize();
            //Knife->Initialize();

            //StartTime = GetNowCount();
            //�^�C�g����ʕ`��
            DrawGraph(0, 0, titlescene, FALSE);

            //(�e�X�g�p)�X�y�[�X�L�[�����ŃQ�[���J�n
            //�X�y�[�X�L�[��������
            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                SCounter++;
            }
            else
            {
                if (SCounter > 0)
                {
                    SCounter = -1;
                }
                else
                {
                    SCounter = 0;
                }
            }
            //�Q�[����ʂ֑J��
            if (SCounter == 1)
            {
                GameState = GamePlay1;

            }
            break;

        case GamePlay1:
            load += 1;

            //�}�b�v�ԍ����Z�b�g
            mapChip->SetMapNumber(0);
            mapChip->Draw(player->GetPosition_X());
            player->Update();
            //Knife->Update();
            

            enemy->Set_position(mapChip->Get_position_8_X(), mapChip->Get_position_8_Y());
            enemy->Update();

            //�Q�[���I�[�o�[����           
            if (player->GetkeyPermission() == false) {
                float a = enemy->GetPosition_X();
                a = enemy->GetPosition_X();
                player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont()));
            }

            //�v���C���[�̕`��̃g���K�[�ɍ��킹�āA�}�b�v�̓����蔻���ON,OFF�𑀍삵�Ă���
            mapChip->SetHideTrigger(player->GetDrawPlayer());

            //���̃v���C���[�@�̓����蔻��
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }            

            //�}�b�v�`�b�v.cs��hide�̒l�ƘA��
            player->SetHide(mapChip->GetHideTrigger());

            //�Q�[���I�[�o�[��ʂ֑J��
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "�������Ă���I�I�I");
                //GameState = GameOver;
            }

            //�X�e�[�W2��
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                mapChip->Initialize();
                player->Initialize();
                enemy->Initialize();

                GameState = GamePlay2;
            }

            break;

        case GamePlay2:
            //for (int i = 0; i < 10; i++) {
            //    if (mapInit) {
            //        //������
            //        mapChip->Initialize();
            //        player->Initialize();
            //        enemy->Initialize();
            //        mapInit = false;
            //    }
            //}

            //�}�b�v�ԍ����Z�b�g
            mapChip->SetMapNumber(1);
            mapChip->Draw(player->GetPosition_X());
            player->Update();

            enemy->Set_position(mapChip->Get_position_8_X(), mapChip->Get_position_8_Y());
            enemy->Update();

            //�Q�[���I�[�o�[����           
            if (player->GetkeyPermission() == false) {
                float a = enemy->GetPosition_X();
                a = enemy->GetPosition_X();
                player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont()));
            }

            //�v���C���[�̕`��̃g���K�[�ɍ��킹�āA�}�b�v�̓����蔻���ON,OFF�𑀍삵�Ă���
            mapChip->SetHideTrigger(player->GetDrawPlayer());

            //���̃v���C���[�@�̓����蔻��
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }

            //�}�b�v�`�b�v.cs��hide�̒l�ƘA��
            player->SetHide(mapChip->GetHideTrigger());

            //�Q�[���I�[�o�[��ʂ֑J��
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "�������Ă���I�I�I");

                //GameState = GameOver;
            }

            //�X�e�[�W3��
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                mapChip->Initialize();
                player->Initialize();
                enemy->Initialize();

                GameState = GamePlay3;
            }

            break;

        case GamePlay3:

            //�}�b�v�ԍ����Z�b�g
            mapChip->SetMapNumber(2);
            mapChip->Draw(player->GetPosition_X());
            player->Update();

            enemy->Set_position(mapChip->Get_position_8_X(), mapChip->Get_position_8_Y());
            enemy->Update();

            //�Q�[���I�[�o�[����           
            if (player->GetkeyPermission() == false) {
                float a = enemy->GetPosition_X();
                a = enemy->GetPosition_X();
                player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont()));
            }

            //�v���C���[�̕`��̃g���K�[�ɍ��킹�āA�}�b�v�̓����蔻���ON,OFF�𑀍삵�Ă���
            mapChip->SetHideTrigger(player->GetDrawPlayer());

            //���̃v���C���[�@�̓����蔻��
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }

            //�}�b�v�`�b�v.cs��hide�̒l�ƘA��
            player->SetHide(mapChip->GetHideTrigger());

            //�Q�[���I�[�o�[��ʂ֑J��
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "�������Ă���I�I�I");

                //GameState = GameOver;
            }

            //�N���A
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                GameState = GameClear;
            }

            break;

        case GameOver:
            //�Q�[���I�[�o�[��ʕ`��
            DrawGraph(0, 0, gameoverscene, FALSE);

            //(�e�X�g�p)�X�y�[�X�����Ń^�C�g���֖߂�
            //�X�y�[�X�L�[��������
            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                SCounter++;
            }
            else
            {
                if (SCounter > 0)
                {
                    SCounter = -1;
                }
                else
                {
                    SCounter = 0;
                }
            }
            //�^�C�g����ʂ֑J��
            if (SCounter == 1)
            {
                GameState = Title;
            }
            break;

        case GameClear:
            //�Q�[���N���A��ʕ`��
            DrawGraph(0, 0, gameclearscene, FALSE);

            //(�e�X�g�p)�X�y�[�X�����Ń^�C�g���֖߂�
            //�X�y�[�X�L�[��������
            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                SCounter++;
            }
            else
            {
                if (SCounter > 0)
                {
                    SCounter = -1;
                }
                else
                {
                    SCounter = 0;
                }
            }
            //�^�C�g����ʂ֑J��
            if (SCounter == 1)
            {
                GameState = Title;
            }
            break;
        }

        ScreenFlip();

        //�Q�[�����W�b�N

        WaitTimer(20);

        if (ProcessMessage() == -1)break;
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;

    }
    //�����������܂őҋ@ 
    //WaitKey();
    delete mapChip;
    //Dx���C�u�����I������ 
    DxLib_End();

    return 0;
}