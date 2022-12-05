#include "DxLib.h" 

#include "MapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "Vase.h"

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
    std::vector<Enemy*> enemy;
    std::vector<Vase*> vase;

    Collision* collision = new Collision();

    mapChip->Initialize();
    player->Initialize();

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

    int ghandleOPD = LoadGraph("Resources/Map/Open_door.png");
    int ghandleCLD = LoadGraph("Resources/Map/Door.png");
    int ghandleCHR = LoadGraph("Resources/Map/Chair.png");
    int ghandleDSK = LoadGraph("Resources/Map/Desk.png");


    //�ԕr�t���O
    int BreakFlag = 0;

    static bool mapInit = true;
    //���[�v�e�X�g�p
    //int StartTime;

    //FPS�̌Œ�Ŏg���ϐ�
    double dNextTime = GetNowCount();


    //�}�b�v�`�b�v�ŕW�����镨�̍��W�i�[�ϐ�
    std::vector<float>eposx;
    std::vector<float>eposy;

    std::vector<float>open_doorx;
    std::vector<float>open_doory;

    std::vector<float>doorx;
    std::vector<float>doory;

    std::vector<float>chairx;
    std::vector<float>chairy;

    std::vector<float>deskx;
    std::vector<float>desky;

    std::vector<float>vasex;
    std::vector<float>vasey;
    



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
                for (int i = 0; i < open_doorx.size(); i++) {
                    open_doorx.clear();
                    open_doorx.shrink_to_fit();
                    open_doory.clear();
                    open_doory.shrink_to_fit();
                }
                for (int i = 0; i < doorx.size(); i++) {
                    doorx.clear();
                    doorx.shrink_to_fit();
                    doory.clear();
                    doory.shrink_to_fit();
                }
                for (int i = 0; i < eposx.size(); i++) {
                    eposx.clear();
                    eposx.shrink_to_fit();
                    eposy.clear();
                    eposy.shrink_to_fit();
                }
                for (int i = 0; i < vasex.size(); i++) {
                    vasex.clear();
                    vasex.shrink_to_fit();
                    vasey.clear();
                    vasey.shrink_to_fit();
                }
                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }

                //�}�b�v�ԍ����Z�b�g
                mapChip->SetMapNumber(0);

                //�}�b�v�`�b�v�ԍ��̈ʒu��ۑ�����
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {

                        switch (mapChip->mapData[mapChip->GetMapNumber()].data[i][j]) {

                        case 4:
                            open_doorx.push_back(float(j * 64));
                            open_doory.push_back(float(i * 64));
                            break;

                        case 5:
                            doorx.push_back(float(j * 64));
                            doory.push_back(float(i * 64));
                            break;

                        case 8:
                            eposx.push_back(float(j * 64));
                            eposy.push_back(float(i * 64));
                            break;
                        }
                    }
                }

                //enemy push_back�����Ă���
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //�v���C���[�����̑O�ɗ����瓖����̔��������
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                            //�����̏�ԁF�S�ē����ʒu�ɐ�������Ă���
                            enemy.push_back(new Enemy());
                        }
                    }
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                GameState = GamePlay1;

            }
            break;

        case GamePlay1:
            load += 1;

            //�}�b�v�ԍ����Z�b�g
            mapChip->SetMapNumber(0);
            mapChip->Draw(player->GetPosition_X());

            player->Update();
            

            /*�󂢂Ă���h�A�̕`��*/
            for (int i = 0; i < open_doorx.size(); i++) {
                DrawGraph(open_doorx[i] + mapChip->GetScroll(), open_doory[i], ghandleOPD, TRUE);
            }
            /*���܂��Ă�h�A�̕`��*/
            for (int i = 0; i < doorx.size(); i++) {
                DrawGraph(doorx[i] + mapChip->GetScroll(), doory[i], ghandleCLD, TRUE);
            }

            //�v���C���[�̍X�V
            player->Update();

            /*�G�̈ʒu�}��*/
            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Update();

                //�i�C�t�ƓG�Ƃ̓����蔻��
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        enemy[i]->Dead();
                    }
                }
                //�Q�[���I�[�o�[����           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            /*�G�̕`�揈��*/
            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Draw();
            }


            //���̃v���C���[�@�̓����蔻��
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }            

            //�Q�[���I�[�o�[��ʂ֑J��
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "�������Ă���I�I�I");
                GameState = GameOver;
            }

            //�X�e�[�W2��
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                for (int i = 0; i < open_doorx.size(); i++) {
                    open_doorx.clear();
                    open_doorx.shrink_to_fit();
                    open_doory.clear();
                    open_doory.shrink_to_fit();
                }
                for (int i = 0; i < doorx.size(); i++) {
                    doorx.clear();
                    doorx.shrink_to_fit();
                    doory.clear();
                    doory.shrink_to_fit();
                }
                for (int i = 0; i < eposx.size(); i++) {
                    eposx.clear();
                    eposx.shrink_to_fit();
                    eposy.clear();
                    eposy.shrink_to_fit();
                }
                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }


                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay2;

                //�}�b�v�ԍ����Z�b�g
                mapChip->SetMapNumber(1);


                //�}�b�v�`�b�v�ԍ��̈ʒu��ۑ�����
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {

                        switch (mapChip->mapData[mapChip->GetMapNumber()].data[i][j]) {
                        case 4:
                            open_doorx.push_back(float(j * 64));
                            open_doory.push_back(float(i * 64));
                            break;

                        case 5:
                            doorx.push_back(float(j * 64));
                            doory.push_back(float(i * 64));
                            break;

                        case 6:
                            chairx.push_back(float(j * 64));
                            chairy.push_back(float(i * 64));
                            break;

                        case 7:
                            deskx.push_back(float(j * 64));
                            desky.push_back(float(i * 64));
                            break;

                        case 8:
                            eposx.push_back(float(j * 64));
                            eposy.push_back(float(i * 64));
                            break;

                        case 12:
                            vasex.push_back(float(j * 64));
                            vasey.push_back(float(i * 64));
                            break;
                        }
                    }
                }

                //enemy push_back�����Ă���
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //�v���C���[�����̑O�ɗ����瓖����̔��������
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                            //enemy�̃I�u�W�F�N�g����
                            enemy.push_back(new Enemy());
                        }
                    }
                }
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //�v���C���[�����̑O�ɗ����瓖����̔��������
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 12) {
                            //enemy�̃I�u�W�F�N�g����
                            vase.push_back(new Vase());
                        }
                    }
                }

                for (int i = 0; i < vase.size(); i++) {
                    vase[i]->Initialize();
                }
                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

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


            mapChip->Draw(player->GetPosition_X());



            /*�󂢂Ă���h�A�`��*/
            for (int i = 0; i < open_doorx.size(); i++) {
                DrawGraph(open_doorx[i] + mapChip->GetScroll(), open_doory[i], ghandleOPD, TRUE);
            }

            /*���܂��Ă�h�A�̕`��*/
            for (int i = 0; i < doorx.size(); i++) {
                DrawGraph(doorx[i] + mapChip->GetScroll(), doory[i], ghandleCLD, TRUE);
            }

            /*���܂��Ă�h�A�̕`��*/
            for (int i = 0; i < chairx.size(); i++) {
                DrawGraph(chairx[i] + mapChip->GetScroll(), chairy[i], ghandleCHR, TRUE);
            }

            /*���̕`��*/
            for (int i = 0; i < deskx.size(); i++) {
                DrawGraph(deskx[i] + mapChip->GetScroll(), desky[i], ghandleDSK, TRUE);
            }

            //�v���C���[�̍X�V
            player->Update();

            /*�G�̍X�V*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            /*�ԕr�̍X�V*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*�ԕr�`��*/
            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //�i�C�t�ƓG�Ƃ̓����蔻��
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        enemy[i]->Dead();
                    }
                }

                //�Q�[���I�[�o�[����           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Draw();
            }

            //�i�C�t�Ɖԕr�̓����蔻��
            for (int i = 0; i < vase.size(); i++) {
                if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
                    //�܂��ԕr������Ȃ�
                    if (player->GetHitFlag() == 1) {
                        if (vase[i]->GetDead() == 0) {
                            vase[i]->SetDead(1);
                            player->SetDisapperKnifeTrigger(1);

                        }
                    }
                }

                if (vase[i]->GetDead() == 1)
                {
                    for (int i = 0; i < enemy.size(); i++) {
                        enemy[i]->CheckSound(vase[i]->GetPosition());
                    }
                    vase[i]->SetDead(2);
                }

            }




            //���̃v���C���[�@�̓����蔻��
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }

            //�C�X�̃v���C���[�@�̓����蔻�� /*�ΉE*/
            if (mapChip->OnCollisionChair_Right(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();

                for (int i = 0; i < enemy.size(); i++) {
                    if (enemy[i]->GetFlont() == 1 && enemy[i]->GetDeath() == 0 &&
                        collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()))
                    {
                        player->SetHide(0);
                    }
                }
            }

            //�C�X�̃v���C���[�@�̓����蔻��@/*�΍�*/
            else if (mapChip->OnCollisionChair_Left(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
                for (int i = 0; i < enemy.size(); i++) {

                    if (enemy[i]->GetFlont() == 0 && enemy[i]->GetDeath() == 0 &&
                        player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont())))
                    {
                        player->SetHide(0);
                    }
                }
            }

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
                //enemy->Initialize();

                GameState = GamePlay3;
            }

            break;

        case GamePlay3:

            //�}�b�v�ԍ����Z�b�g
            mapChip->SetMapNumber(2);
            mapChip->Draw(player->GetPosition_X());

            player->Update();

            //enemy->Set_position(mapChip->Get_position_8_X(), mapChip->Get_position_8_Y());
            //enemy->Update();
            //enemy->Draw();


            //�i�C�t�ƓG�Ƃ̓����蔻��
            //if (collision->KnifetoEnemy(player->GetKnifePos(), enemy->GetPosition_X())) {
            //    if (player->GetHitFlag() == 1) {
            //        //enemy->Dead();
            //    }
            //}

            //���̃v���C���[�@�̓����蔻��
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }

            //�Q�[���I�[�o�[����           
            //if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy->GetDeath() == 0) {
            //    player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont()));
            //}

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
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                for (int i = 0; i < open_doorx.size(); i++) {
                    open_doorx.clear();
                    open_doorx.shrink_to_fit();
                    open_doory.clear();
                    open_doory.shrink_to_fit();
                }
                for (int i = 0; i < doorx.size(); i++) {
                    doorx.clear();
                    doorx.shrink_to_fit();
                    doory.clear();
                    doory.shrink_to_fit();
                }
                for (int i = 0; i < eposx.size(); i++) {
                    eposx.clear();
                    eposx.shrink_to_fit();
                    eposy.clear();
                    eposy.shrink_to_fit();
                }
                for (int i = 0; i < vasex.size(); i++) {
                    vasex.clear();
                    vasex.shrink_to_fit();
                    vasey.clear();
                    vasey.shrink_to_fit();
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }
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
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                for (int i = 0; i < open_doorx.size(); i++) {
                    open_doorx.clear();
                    open_doorx.shrink_to_fit();
                    open_doory.clear();
                    open_doory.shrink_to_fit();
                }
                for (int i = 0; i < doorx.size(); i++) {
                    doorx.clear();
                    doorx.shrink_to_fit();
                    doory.clear();
                    doory.shrink_to_fit();
                }
                for (int i = 0; i < eposx.size(); i++) {
                    eposx.clear();
                    eposx.shrink_to_fit();
                    eposy.clear();
                    eposy.shrink_to_fit();
                }
                for (int i = 0; i < vasex.size(); i++) {
                    vasex.clear();
                    vasex.shrink_to_fit();
                    vasey.clear();
                    vasey.shrink_to_fit();
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }


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