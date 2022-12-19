#include "DxLib.h" 


#include "Stage.h"




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

    //�Q�[�����[�v
    int GameState;
    enum GameState
    {
        Title,
        GamePlay1,
        GamePlay2,
        GamePlay3,
        GamePlay4,
        GamePlay5,
        GamePlay6,
        GamePlay7,
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

    //FPS�̌Œ�Ŏg���ϐ�
    double dNextTime = GetNowCount();


    //�N���X�Ăяo��
    Stage* stage = new Stage();

    


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
            stage->Initialize();
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
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                stage-> Release();

                stage->Generate(0);

                GameState = GamePlay1;

            }
            break;

        case GamePlay1:

#pragma region Stage1
   
            //�`��
            stage->Drow();
            stage->Update_01();
           
            if (stage->SetGameOver() ==1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(1);
                GameState = GamePlay2;

                stage->Initialize();

            }

#pragma endregion
            break;
        case GamePlay2:

#pragma region Stage2

            //�`��
            stage->Drow();
            stage->Update_01();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(2);
                GameState = GamePlay3;

                stage->Initialize();

            }
         
#pragma endregion
            break;
        case GamePlay3:

#pragma region Stage3
          
            //�`��
            stage->Drow();
            stage->Update_01();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(3);
                GameState = GamePlay4;

                stage->Initialize();

            }
#pragma endregion
            break;
        case GamePlay4:

#pragma region Stage4
            //�`��
            stage->Drow();
            stage->Update_01();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(4);
                GameState = GamePlay5;

                stage->Initialize();

            }
           
#pragma endregion
            break;
        case GamePlay5:

#pragma region Stage5
            //�`��
            stage->Drow();
            stage->Update_02();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(5);
                GameState = GamePlay6;

                stage->Initialize();

            }

#pragma endregion
            break;
        case GamePlay6:

#pragma region Stage6
            //�`��
            stage->Drow();
            stage->Update_02();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(6);
                GameState = GamePlay7;

                stage->Initialize();

            }
         
            
#pragma endregion
            break;
        case GamePlay7:

#pragma region Stage7
            //�`��
            stage->Drow();
            stage->Update_02();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (stage->SetGool() == 1)
            {
                stage->Release();

                GameState = GameClear;

                stage->Initialize();

            }
#pragma endregion
            break;

        case GameOver:
#pragma region GameOver
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
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                stage->Release();
            }

#pragma endregion
            break;

        case GameClear:
#pragma region GameClear
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

#pragma endregion

        ScreenFlip();

        //�Q�[�����W�b�N

        WaitTimer(20);

        if (ProcessMessage() == -1)break;
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
        

    }
    //�����������܂őҋ@ 
    //WaitKey();

    //Dx���C�u�����I������ 
    DxLib_End();

    return 0;
}

