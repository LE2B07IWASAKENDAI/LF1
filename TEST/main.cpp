#include "DxLib.h" 

#include "MapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "Vase.h"
#include "BGM.h"
#include "SE.h"
#include "Collision.h"

void SetItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int mapNumber);
void SetItemX_28(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber);
void DrawItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int ghandle);
void DeleteItem(std::vector<float>& posx, std::vector<float>& posy);

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
    BGM* bgm = new BGM();
    SE* se = new SE();
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
        GamePlay4,
        GamePlay5,
        GamePlay5_1,
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


    int ghandleOPD = LoadGraph("Resources/Map/Open_door.png");
    int ghandleCLD = LoadGraph("Resources/Map/Door.png");
    int ghandleCHR = LoadGraph("Resources/Map/Chair.png");
    int ghandleDSK = LoadGraph("Resources/Map/Desk.png");


    //�ԕr�t���O
    int BreakFlag = 0;

    static bool mapInit = true;

    int mapWarp = 0;
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

    bgm->PlayBGM();


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
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }

                mapChip->SetScroll_Y(0);

                //�}�b�v�ԍ����Z�b�g
                mapChip->SetMapNumber(0);

                //�}�b�v�`�b�v�ԍ��̈ʒu��ۑ�����
                    //�}�b�v�`�b�v����ʒu��}��
                SetItem(open_doorx, open_doory, mapChip, 4);
                SetItem(doorx, doory, mapChip, 5);

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {

                        switch (mapChip->mapData[mapChip->GetMapNumber()].data[i][j]) {
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

#pragma region Stage1
            //�}�b�v�ԍ����Z�b�g
            mapChip->SetMapNumber(0);
            mapChip->Draw(player->GetPosition_X());
            mapChip->MapDraw();

            player->Update();


            //�}�b�v�`�b�v�̕`��
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);

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
                        //se->KillSE_voice();
                        enemy[i]->Dead();
                        
                    }
                }
                //�Q�[���I�[�o�[����           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    //se->DiscoverSE_voice();
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
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(eposx, eposy);

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
                   //�}�b�v�`�b�v����ʒu��}��
                SetItem(open_doorx, open_doory, mapChip, 4);
                SetItem(doorx, doory, mapChip, 5);
                SetItem(chairx, chairy, mapChip, 6);
                SetItem(deskx, desky, mapChip, 7);

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {

                        switch (mapChip->mapData[mapChip->GetMapNumber()].data[i][j]) {
                        case 8:
                            eposx.push_back(float(j * 64));
                            eposy.push_back(float(i * 64));
                            enemy.push_back(new Enemy());
                            break;

                        case 10:
                            vasex.push_back(float(j * 64));
                            vasey.push_back(float(i * 64));
                            vase.push_back(new Vase());
                            break;
                        }
                    }
                }


                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < vase.size(); i++) {
                    vase[i]->Initialize();
                }

            }
#pragma endregion
            break;
        case GamePlay2:

#pragma region Stage2
            mapChip->Draw(player->GetPosition_X());
            mapChip->MapDraw();

            //�}�b�v�`�b�v�̕`��
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);

            //�v���C���[�̍X�V
            player->Update();

            /*�ԕr�̍X�V*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*�G�̍X�V*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }


            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //�i�C�t�ƓG�Ƃ̓����蔻��
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        //se->KillSE_voice();
                        enemy[i]->Dead();
                    }
                }

                //�Q�[���I�[�o�[����           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    //se->DiscoverSE_voice();
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Draw();
            }

            for (int i = 0; i < vase.size(); i++) {
                //�i�C�t�Ɖԕr�̓����蔻��
                if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
                    //�܂��ԕr������Ȃ�
                    if (player->GetHitFlag() == 1) {
                        if (vase[i]->GetDead() == 0) {
                            vase[i]->SetDead(1);
                            se->CrackSE();
                            player->SetDisapperKnifeTrigger(1);

                        }
                    }
                }

                if (vase[i]->GetDead() == 1)
                {
                    for (int j = 0; j < enemy.size(); j++) {
                        enemy[j]->CheckSound();
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
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }
                for (int i = 0; i < vase.size(); i++) {
                    vase.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    vase.shrink_to_fit();
                }

                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay3;

                //�}�b�v�ԍ����Z�b�g
                mapChip->SetMapNumber(2);


                //�}�b�v�`�b�v�ԍ��̈ʒu��ۑ�����
                   //�}�b�v�`�b�v����ʒu��}��
                SetItem(open_doorx, open_doory, mapChip, 4);
                SetItem(doorx, doory, mapChip, 5);
                SetItem(chairx, chairy, mapChip, 6);
                SetItem(deskx, desky, mapChip, 7);

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {

                        switch (mapChip->mapData[mapChip->GetMapNumber()].data[i][j]) {
                        case 8:
                            eposx.push_back(float(j * 64));
                            eposy.push_back(float(i * 64));
                            break;

                        case 10:
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

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //�v���C���[�����̑O�ɗ����瓖����̔��������
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                            //enemy�̃I�u�W�F�N�g����
                            vase.push_back(new Vase());
                        }
                    }
                }

                for (int i = 0; i < vase.size(); i++) {
                    vase[i]->Initialize();
                }
            }

#pragma endregion
            break;
        case GamePlay3:

#pragma region Stage3
            //�}�b�v�ԍ����Z�b�g
            mapChip->Draw(player->GetPosition_X());
            mapChip->MapDraw();

            player->Update();

            //�}�b�v�`�b�v�̕`��
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);


            //�v���C���[�̍X�V
            player->Update();


            /*�ԕr�̍X�V*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*�G�̍X�V*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            //�ԕr�̕`��
            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            //�G�̖��t���[������
            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //�i�C�t�ƓG�Ƃ̓����蔻��
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        //se->KillSE_voice();
                        enemy[i]->Dead();
                    }
                }

                //�Q�[���I�[�o�[����           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    //se->DiscoverSE_voice();
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            //�G�̕`��
            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Draw();
            }

            //�ԕr�̖��t���[������
            for (int i = 0; i < vase.size(); i++) {
                //�i�C�t�Ɖԕr�̓����蔻��
                if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
                    //�܂��ԕr������Ȃ�
                    if (player->GetHitFlag() == 1) {
                        if (vase[i]->GetDead() == 0) {
                            se->CrackSE();
                            vase[i]->SetDead(1);
                            player->SetDisapperKnifeTrigger(1);

                        }
                    }
                }

                if (vase[i]->GetDead() == 1)
                {
                    for (int j = 0; j < enemy.size(); j++) {
                        enemy[j]->CheckSound();
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

            //�N���A
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }

                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay4;

                //�}�b�v�ԍ����Z�b�g
                mapChip->SetMapNumber(3);


                //�}�b�v�`�b�v�ԍ��̈ʒu��ۑ�����
                   //�}�b�v�`�b�v����ʒu��}��
                SetItem(open_doorx, open_doory, mapChip, 4);
                SetItem(doorx, doory, mapChip, 5);
                SetItem(chairx, chairy, mapChip, 6);
                SetItem(deskx, desky, mapChip, 7);

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {

                        switch (mapChip->mapData[mapChip->GetMapNumber()].data[i][j]) {
                        case 8:
                            eposx.push_back(float(j * 64));
                            eposy.push_back(float(i * 64));
                            break;

                        case 10:
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

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //�v���C���[�����̑O�ɗ����瓖����̔��������
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                            //enemy�̃I�u�W�F�N�g����
                            vase.push_back(new Vase());
                        }
                    }
                }

                for (int i = 0; i < vase.size(); i++) {
                    vase[i]->Initialize();
                }

            }
#pragma endregion
            break;
        case GamePlay4:

#pragma region Stage4
            //�}�b�v�ԍ����Z�b�g
            mapChip->Draw(player->GetPosition_X());
            mapChip->MapDraw();

            player->Update();

            //�}�b�v�`�b�v�̕`��
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);


            //�v���C���[�̍X�V
            player->Update();


            /*�ԕr�̍X�V*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*�G�̍X�V*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            //�ԕr�̕`��
            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            //�G�̖��t���[������
            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //�i�C�t�ƓG�Ƃ̓����蔻��
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        //se->KillSE_voice();
                        enemy[i]->Dead();
                    }
                }

                //�Q�[���I�[�o�[����           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    //se->DiscoverSE_voice();
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            //�G�̕`��
            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Draw();
            }

            //�ԕr�̖��t���[������
            for (int i = 0; i < vase.size(); i++) {
                //�i�C�t�Ɖԕr�̓����蔻��
                if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
                    //�܂��ԕr������Ȃ�
                    if (player->GetHitFlag() == 1) {
                        if (vase[i]->GetDead() == 0) {
                            se->CrackSE();
                            vase[i]->SetDead(1);
                            player->SetDisapperKnifeTrigger(1);
                        }
                    }
                }

                if (vase[i]->GetDead() == 1)
                {
                    for (int j = 0; j < enemy.size(); j++) {
                        enemy[j]->CheckSound();
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

            //�N���A
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }
                for (int i = 0; i < vase.size(); i++) {
                    vase.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    vase.shrink_to_fit();
                }

                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay5;

                //�}�b�v�ԍ����Z�b�g
                mapChip->SetMapNumber(4);


                //�}�b�v�`�b�v�ԍ��̈ʒu��ۑ�����
                 //�}�b�v�`�b�v����ʒu��}��
                SetItemX_28(open_doorx, open_doory, mapChip, 4);
                SetItemX_28(doorx, doory, mapChip, 5);
                SetItemX_28(chairx, chairy, mapChip, 6);
                SetItemX_28(deskx, desky, mapChip, 7);

                for (int i = 0; i < 28; i++) {
                    for (int j = 0; j < 84; j++) {

                        switch (mapChip->mapData[mapChip->GetMapNumber()].data[i][j]) {
                        case 8:
                            eposx.push_back(float(j * 64));
                            eposy.push_back(float(i * 64));
                            break;

                        case 10:
                            vasex.push_back(float(j * 64));
                            vasey.push_back(float(i * 64));
                            break;
                        }
                    }
                }

                //enemy push_back�����Ă���
                for (int i = 0; i < 28; i++) {
                    for (int j = 0; j < 84; j++) {
                        //�v���C���[�����̑O�ɗ����瓖����̔��������
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                            //enemy�̃I�u�W�F�N�g����
                            enemy.push_back(new Enemy());
                        }
                    }
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < 28; i++) {
                    for (int j = 0; j < 84; j++) {
                        //�v���C���[�����̑O�ɗ����瓖����̔��������
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                            //enemy�̃I�u�W�F�N�g����
                            vase.push_back(new Vase());
                        }
                    }
                }

                for (int i = 0; i < vase.size(); i++) {
                    vase[i]->Initialize();
                }
            }
#pragma endregion
            break;
        case GamePlay5:
#pragma region Stage5
            mapChip->SetMapNumber(4);

            //�}�b�v�ԍ����Z�b�g
            mapChip->Draw(player->GetPosition_X());
            mapChip->MapDraw5();

            player->Update();

            //�}�b�v�`�b�v�̕`��
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);


            //�v���C���[�̍X�V
            player->Update();

            /*�ԕr�̍X�V*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i] + mapChip->GetScroll_Y());
            }
            /*�G�̍X�V*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i] + mapChip->GetScroll_Y());
            }

            //�ԕr�̕`��
            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            //�G�̖��t���[������
            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //�i�C�t�ƓG�Ƃ̓����蔻��
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        //se->KillSE_voice();
                        enemy[i]->Dead();
                    }
                }

                //�Q�[���I�[�o�[����           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    //se->DiscoverSE_voice();
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }

                enemy[i]->Draw();
            }

            //�ԕr�̖��t���[������
            for (int i = 0; i < vase.size(); i++) {
                //�i�C�t�Ɖԕr�̓����蔻��
                if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
                    //�܂��ԕr������Ȃ�
                    if (player->GetHitFlag() == 1) {
                        if (vase[i]->GetDead() == 0) {
                            se->CrackSE();
                            vase[i]->SetDead(1);
                            player->SetDisapperKnifeTrigger(1);

                        }
                    }
                }

                if (vase[i]->GetDead() == 1)
                {
                    for (int j = 0; j < enemy.size(); j++) {
                        enemy[j]->CheckSound();
                    }
                    vase[i]->SetDead(2);
                }
            }

            //���̃v���C���[�@�̓����蔻��
            if (mapChip->OnCollisionDoor_28(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }

            //�C�X�̃v���C���[�@�̓����蔻�� /*�ΉE*/
            if (mapChip->OnCollisionChair_Right_28(player->GetPosition_X(), player->GetPosition_Y(),
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
            else if (mapChip->OnCollisionChair_Left_28(player->GetPosition_X(), player->GetPosition_Y(),
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

            //����
            if (mapChip->OnCollisionWarp_20(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                if (CheckHitKey(KEY_INPUT_S) == 1) {
                    //�ʒu���u�Ԉړ�����΂悢
                    player->SetPosition(mapChip->GetPosition_21_X(), mapChip->GetPosition_21_Y());
                    mapChip->SetScroll_Y(1);
                }
            }

            if (mapChip->OnCollisionWarp_22(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                if (CheckHitKey(KEY_INPUT_W) == 1) {
                    //�ʒu���u�Ԉړ�����΂悢
                    mapChip->SetScroll_Y(0);
                    player->SetPosition(mapChip->GetPosition_23_X(), mapChip->GetPosition_23_Y());
                }
            }

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
                //vector�^�̕ϐ��̗v�f��S�폜�A����������B
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }
                for (int i = 0; i < vase.size(); i++) {
                    vase.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    vase.shrink_to_fit();
                }

                GameState = GameClear;
            }


#pragma endregion
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

                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(chairx, chairy);
                DeleteItem(deskx, desky);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    enemy.shrink_to_fit();
                }
                for (int i = 0; i < vase.size(); i++) {
                    vase.clear();
                    //�R���e�i�̃T�C�Y�܂Ń����������
                    vase.shrink_to_fit();
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

//�}�b�v�`�b�v��̃A�C�e�������֐�
void SetItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber)
{
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 84; j++) {
            if (mapchip->mapData[mapchip->GetMapNumber()].data[i][j] == chipNumber)
            {
                posx.push_back(float(j * 64));
                posy.push_back(float(i * 64));
            }
        }
    }
}

void SetItemX_28(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber) {
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 84; j++) {
            if (mapchip->mapData[mapchip->GetMapNumber()].data[i][j] == chipNumber)
            {
                posx.push_back(float(j * 64));
                posy.push_back(float(i * 64));
            }
        }
    }
}
//�}�b�v�`�b�v��̃A�C�e���`��֐�
void DrawItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int ghandle) {

    for (int i = 0; i < posx.size(); i++) {
        DrawGraph(posx[i] + mapchip->GetScroll(), posy[i] + mapchip->GetScroll_Y(), ghandle, TRUE);
    }
}
//�}�b�v�`�b�v��̃A�C�e���폜�֐�
void DeleteItem(std::vector<float>& posx, std::vector<float>& posy) {
    for (int i = 0; i < posx.size(); i++) {
        posx.clear();
        posx.shrink_to_fit();
        posy.clear();
        posy.shrink_to_fit();
    }
}
