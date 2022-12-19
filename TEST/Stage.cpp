#include "Stage.h"

Stage::Stage()
{
    mapChip->Initialize();
    player->Initialize();
    bgm->PlayBGM();
    ghandleOPD = LoadGraph("Resources/Map/Open_door.png");
    ghandleCLD = LoadGraph("Resources/Map/Door.png");
    ghandleCHR = LoadGraph("Resources/Map/Chair.png");
    ghandleDSK = LoadGraph("Resources/Map/Desk.png");
}

Stage::~Stage()
{
    delete mapChip;
}

void Stage::Initialize()
{
    mapChip->Initialize();
    player->Initialize();
    over = 0;
    BreakFlag = 0;
    gool = 0;
}

//�}�b�v�`�b�v��̃A�C�e�������֐�
void Stage::SetItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber)
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


void Stage::SetItemX_28(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber) {
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
void Stage::DrawItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int ghandle) {

    for (int i = 0; i < posx.size(); i++) {
        DrawGraph(posx[i] + mapchip->GetScroll(), posy[i] + mapchip->GetScroll_Y(), ghandle, TRUE);
    }
}
//�}�b�v�`�b�v��̃A�C�e���폜�֐�
void Stage::DeleteItem(std::vector<float>& posx, std::vector<float>& posy) {
    for (int i = 0; i < posx.size(); i++) {
        posx.clear();
        posx.shrink_to_fit();
        posy.clear();
        posy.shrink_to_fit();
    }
}

//�}�b�v�`�b�v��̃A�C�e���S�폜�֐�
void Stage::AllDelete(std::vector<float>& eposx, std::vector<float>& eposy, std::vector<float>& open_doorx, std::vector<float>& open_doory,
    std::vector<float>& doorx, std::vector<float>& doory, std::vector<float>& chairx, std::vector<float>& chairy,
    std::vector<float>& deskx, std::vector<float>& desky, std::vector<float>& vasex, std::vector<float>& vasey) {

    DeleteItem(eposx, eposy);
    DeleteItem(open_doorx, open_doory);
    DeleteItem(doorx, doory);
    DeleteItem(chairx, chairy);
    DeleteItem(deskx, desky);
    DeleteItem(vasex, vasey);
}

void Stage::Release()
{
    AllDelete(eposx, eposy, open_doorx, open_doory, doorx, doory, chairx, chairy, deskx, desky, vasex, vasey);

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

void Stage::Generate(int map)
{
    mapChip->SetScroll_Y(0);

    //�}�b�v�ԍ����Z�b�g
    mapChip->SetMapNumber(map);

    //�}�b�v�`�b�v�ԍ��̈ʒu��ۑ�����
    //�}�b�v�`�b�v����ʒu��}��
    SetItem(open_doorx, open_doory, mapChip, 4);
    SetItem(doorx, doory, mapChip, 5);
    SetItem(chairx, chairy, mapChip, 6);
    SetItem(deskx, desky, mapChip, 7);
    SetItem(eposx, eposy, mapChip, 8);
    SetItem(vasex, vasey, mapChip, 10);

    //�G�l�~�[����
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

void Stage::SetMap(int map)
{
    mapChip->SetMapNumber(map);
}

void Stage::Drow()
{
    mapChip->Draw(player->GetPosition_X());
    mapChip->MapDraw();


    //�}�b�v�`�b�v�̕`��
    DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
    DrawItem(doorx, doory, mapChip, ghandleCLD);
    DrawItem(chairx, chairy, mapChip, ghandleCHR);
    DrawItem(deskx, desky, mapChip, ghandleDSK);

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

}

void Stage::Update_01()
{
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
        over = 1;
    }
}

void Stage::Update_02()
{
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
        over = 1;
    }
}

int Stage::SetGool()
{
    if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY())) 
    {
        gool = 1;
    }

    return gool;
}


