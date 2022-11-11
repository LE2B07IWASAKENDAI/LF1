#include "DxLib.h" 
#include "MapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"


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
    SetBackgroundColor(0,0,0);

    //Dx���C�u������������ 
    if (DxLib_Init() == -1)
    {
        //�G���[���o����}�C�i�X�l��Ԃ��ďI�� 
        return -1;
    }

    MapChip* mapChip = new MapChip();
    Player* player = new Player();
    Enemy* enemy = new Enemy();
    Collision* collision = new Collision();
    mapChip->Initialize();
    player->Initialize();
    enemy->Initialize();

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

    //���[�v�e�X�g�p
    //int StartTime;

    while (1)
    {
        //�Q�[�����W�b�N
        //����ʂ�����
        ClearDrawScreen();

        //�Q�[�����[�v
        switch (GameState)
        {
        case Title:
            //������
            mapChip->Initialize();
            player->Initialize();
            enemy->Initialize();

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

            //�Q�[����ʕ`��(�v���g)
            DrawGraph(0, 0, bgscene1, FALSE);

            //mapChip->Draw();
            player->Update();
            enemy->Update();
            player->SetDeath(collision->Found(player->GetPosition_X(), enemy->GetPosition_X()));



            //���̃v���C���[�@�̓����蔻��
            mapChip->Collision(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY());

            //�}�b�v�`�b�v.cs��hide�̒l�ƘA��
            player->SetHide(mapChip->GetHideTrigger());

            ////(���e�X�g�p)�Q�[���I�[�o�[��ʂ�
            ////5�b�o�߂ňړ�
            //if (GetNowCount() - StartTime > 5000)
            //{
            //    GameState = GameOver;
            //}

            //�Q�[���I�[�o�[��ʂ֑J��
            if (player->death == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��(�e�X�g�p)
            if (player->GetPosition_X() > 500.f)
            {
                GameState = GamePlay2;
                player->Initialize();
            }

            break;

        case GamePlay2:

            //�Q�[����ʕ`��(�v���g)
            DrawGraph(0, 0, bgscene2, FALSE);

            //mapChip->Draw();
            player->Update();
            enemy->Update();
            player->SetDeath(collision->Found(player->GetPosition_X(), enemy->GetPosition_X()));



            //���̃v���C���[�@�̓����蔻��
            mapChip->Collision(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY());

            //�}�b�v�`�b�v.cs��hide�̒l�ƘA��
            player->SetHide(mapChip->GetHideTrigger());

            if (player->death == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W3��(�e�X�g�p)
            if (player->GetPosition_X() > 500.f)
            {
                GameState = GamePlay3;
                player->Initialize();
            }

            break;

        case GamePlay3:

            //�Q�[����ʕ`��(�v���g)
            DrawGraph(0, 0, bgscene3, FALSE);

            //mapChip->Draw();
            player->Update();
            enemy->Update();
            player->SetDeath(collision->Found(player->GetPosition_X(), enemy->GetPosition_X()));

            //���̃v���C���[�@�̓����蔻��
            mapChip->Collision(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY());

            //�}�b�v�`�b�v.cs��hide�̒l�ƘA��
            player->SetHide(mapChip->GetHideTrigger());

            if (player->death == 1)
            {
                GameState = GameOver;
            }

            //�N���A��ʂ�(�e�X�g�p)
            if (player->GetPosition_X() > 500.f)
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