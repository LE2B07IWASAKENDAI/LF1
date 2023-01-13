#include "Stage.h"

Stage::Stage()
{
    mapChip->Initialize();
    player->Initialize();
    bgm->PlayBGM();
    se->Initialize();
    ghandleOPD = LoadGraph("Resources/Map/Open_door.png");
    ghandleCLD = LoadGraph("Resources/Map/Door.png");
    ghandleCHR = LoadGraph("Resources/Map/Chair.png");
    ghandleDSK = LoadGraph("Resources/Map/Desk.png");
    ghandleHID_L = LoadGraph("Resources/Map/light_left.png");
    ghandleHID_R = LoadGraph("Resources/Map/light_right.png");
}

Stage::~Stage()
{
    //delete mapChip;
}

void Stage::Initialize()
{
    mapChip->Initialize();
    player->Initialize();
    over = 0;
    BreakFlag = 0;
    gool = 0;
}

//マップチップ上のアイテム生成関数
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

void Stage::SetItem_28(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int chipNumber) {
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
//マップチップ上のアイテム描画関数
void Stage::DrawItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int ghandle) {

    for (int i = 0; i < posx.size(); i++) {
        DrawGraph(posx[i] + mapchip->GetScroll(), posy[i] + mapchip->GetScroll_Y(), ghandle, TRUE);
    }
}
//マップチップ上のアイテム削除関数
void Stage::DeleteItem(std::vector<float>& posx, std::vector<float>& posy) {
    for (int i = 0; i < posx.size(); i++) {
        posx.clear();
        posx.shrink_to_fit();
        posy.clear();
        posy.shrink_to_fit();
    }
}

//マップチップ上のアイテム全削除関数
void Stage::AllDelete(std::vector<float>& eposx, std::vector<float>& eposy, std::vector<float>& open_doorx, std::vector<float>& open_doory,
    std::vector<float>& doorx, std::vector<float>& doory, std::vector<float>& chairx, std::vector<float>& chairy,
    std::vector<float>& deskx, std::vector<float>& desky, std::vector<float>& vasex, std::vector<float>& vasey,
    std::vector<float>& hidex_left, std::vector<float>& hidey_left, std::vector<float>& hidex_right, std::vector<float>& hidey_right) {

    DeleteItem(eposx, eposy);
    DeleteItem(open_doorx, open_doory);
    DeleteItem(doorx, doory);
    DeleteItem(chairx, chairy);
    DeleteItem(deskx, desky);
    DeleteItem(vasex, vasey);
    DeleteItem(hidex_left, hidey_left);
    DeleteItem(hidex_right, hidey_right);
}

void Stage::Release()
{
    AllDelete(eposx, eposy, open_doorx, open_doory, doorx, doory, chairx, chairy, deskx, desky, vasex, vasey, hidex_left, hidey_left, hidex_right, hidey_right);

    for (int i = 0; i < enemy.size(); i++) {
        enemy.clear();
        //コンテナのサイズまでメモリを解放
        enemy.shrink_to_fit();
    }
    for (int i = 0; i < vase.size(); i++) {
        vase.clear();
        //コンテナのサイズまでメモリを解放
        vase.shrink_to_fit();
    }
    for (int i = 0; i < chair.size(); i++) {
        chair.clear();
        //コンテナのサイズまでメモリを解放
        chair.shrink_to_fit();
    }
}

void Stage::Generate(int map)
{
    mapChip->SetScroll_Y(0);

    //マップ番号をセット
    mapChip->SetMapNumber(map);

    //マップチップ番号の位置を保存する
    //マップチップから位置を挿入
    SetItem(chairx, chairy, mapChip, 6);
    SetItem(eposx, eposy, mapChip, 8);
    SetItem(vasex, vasey, mapChip, 10);
    SetItem(vasex, vasey, mapChip, 18);

    //エネミー生成
    //enemy push_backをしていく
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 84; j++) {
            //プレイヤーが扉の前に来たら当たりの判定を入れる
            if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                //※この状態：全て同じ位置に生成されている
                enemy.push_back(new Enemy());
            }
        }
    }

    for (int i = 0; i < enemy.size(); i++) {
        enemy[i]->Initialize();
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 84; j++) {
            if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10||
                mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 18) {
                //enemyのオブジェクト生成
                vase.push_back(new Vase());
            }
        }
    }

    for (int i = 0; i < vase.size(); i++) {
        vase[i]->Initialize();
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 84; j++) {
            //プレイヤーが扉の前に来たら当たりの判定を入れる
            if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 6) {
                //enemyのオブジェクト生成
                chair.push_back(new Chair());
            }
        }
    }

    for (int i = 0; i < chair.size(); i++) {
        chair[i]->Initialize();
    }
}

void Stage::Generate2(int map)
{
    mapChip->SetScroll_Y(0);

    //マップ番号をセット
    mapChip->SetMapNumber(map);

    //マップチップ番号の位置を保存する
    //マップチップから位置を挿入
    SetItem_28(chairx, chairy, mapChip, 6);
    SetItem_28(eposx, eposy, mapChip, 8);
    SetItem_28(vasex, vasey, mapChip, 10);
    SetItem_28(vasex, vasey, mapChip, 18);

    //エネミー生成
    //enemy push_backをしていく
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 84; j++) {
            //プレイヤーが扉の前に来たら当たりの判定を入れる
            if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                //※この状態：全て同じ位置に生成されている
                enemy.push_back(new Enemy());
            }
        }
    }

    for (int i = 0; i < enemy.size(); i++) {
        enemy[i]->Initialize();
    }

    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 84; j++) {
            if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10 ||
                mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 18) {
                //enemyのオブジェクト生成
                vase.push_back(new Vase());
            }
        }
    }

    for (int i = 0; i < vase.size(); i++) {
        vase[i]->Initialize();
    }

    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 84; j++) {
            if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 6) {
                //enemyのオブジェクト生成
                chair.push_back(new Chair());
            }
        }
    }

    for (int i = 0; i < chair.size(); i++) {
        chair[i]->Initialize();
    }

}

void Stage::SetMap(int map)
{
    mapChip->SetMapNumber(map);
}

void Stage::Drow()
{
    mapChip->Draw(player->GetPosition_X());
    if (mapChip->GetMapNumber() <= 3) {
        mapChip->MapDraw();
    }
    else
    {
        mapChip->MapDraw5();
    }

    DrawFormatString(0, 100, GetColor(255, 255, 255), "マップ番号 : %d ", mapChip->GetMapNumber() + 1);

    //マップチップの描画
    //DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
    //DrawItem(doorx, doory, mapChip, ghandleCLD);
    //DrawItem(chairx, chairy, mapChip, ghandleCHR);
    //DrawItem(deskx, desky, mapChip, ghandleDSK);
    //DrawItem(hidex_left, hidey_left, mapChip, ghandleHID_L);
    //DrawItem(hidex_right, hidey_right, mapChip, ghandleHID_R);

    /*敵の描画処理*/
    for (int i = 0; i < enemy.size(); i++) {
        enemy[i]->Draw();
    }

    //花瓶の描画
    for (int i = 0; i < vase.size(); i++) {
       if (vase.size() >= 2) {
           vase[i]->Draw();
       }
    }

    //花瓶の描画
    for (int i = 0; i < chair.size(); i++) {
       if (chair.size() >= 2) {
           chair[i]->Draw();
       }
    }
    player->Draw();
}

void Stage::Update_01()
{
    //プレイヤーの更新
    player->Update();
    /*花瓶の更新*/
    for (int i = 0; i < vasex.size(); i++) {
        vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i] + mapChip->GetScroll_Y());
    }
    for (int i = 0; i < chairx.size(); i++) {
        chair[i]->SetPosition(chairx[i] + mapChip->GetScroll(), chairy[i] + mapChip->GetScroll_Y());
    }
    /*敵の更新*/
    for (int i = 0; i < eposx.size(); i++) {
        enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
    }

    for (int i = 0; i < enemy.size(); i++) {
        enemy[i]->Update();

        //ナイフと敵との当たり判定
        if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
            if (player->GetHitFlag() == 1) {
                se->KillSE_voice();
                enemy[i]->Dead();
            }
        }
        //ゲームオーバー処理           
        if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
            player->SetDeath(collision->Found(player->GetPosition_x(),player->GetPosition_Y(), enemy[i]->GetPosition_X(),enemy[i]->Getposition_Y(), enemy[i]->GetFlont()));
        }
    }


    //花瓶の毎フレーム処理
    for (int i = 0; i < vase.size(); i++) {
        //ナイフと花瓶の当たり判定
        if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
            //まだ花瓶があるなら
            if (player->GetHitFlag() == 1) {
                if (vase[i]->GetDead() == 0) {
                    se->CrackSE();
                    vase[i]->SetDead(1);
                    //player->SetDisapperKnifeTrigger(1);
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

    //扉⇔プレイヤー　の当たり判定
    if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();
    }

    //扉⇔プレイヤー　の当たり判定
    if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();
    }

    //イス⇔プレイヤー　の当たり判定 /*対右*/
    if (mapChip->OnCollisionChair_Right(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();

        for (int i = 0; i < enemy.size(); i++) {
            if (enemy[i]->GetFlont() == 1 && enemy[i]->GetDeath() == 0 &&
                collision->Found(player->GetPosition_x(), player->GetPosition_Y(), enemy[i]->GetPosition_X(), enemy[i]->Getposition_Y(), enemy[i]->GetFlont()))
            {
                player->SetHide(0);
            }
        }
    }

    //イス⇔プレイヤー　の当たり判定　/*対左*/
    else if (mapChip->OnCollisionChair_Left(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();
        for (int i = 0; i < enemy.size(); i++) {

            if (enemy[i]->GetFlont() == 0 && enemy[i]->GetDeath() == 0 &&
                player->SetDeath(collision->Found(player->GetPosition_x(), player->GetPosition_Y(), enemy[i]->GetPosition_X(), enemy[i]->Getposition_Y(), enemy[i]->GetFlont())))
            {
                player->SetHide(0);
            }
        }
    }

    if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        gool = 1;
        Release();
    }

    //ゲームオーバー画面へ遷移
    if (player->death == 1)
    {
        DrawFormatString(1607, 210, GetColor(255, 255, 255), "当たっている！！！");
        se->DiscoverSE_voice();
        //over = 1;
    }
}

void Stage::Update_02()
{
    //プレイヤーの更新
    player->Update();

    /*敵の位置挿入*/
    for (int i = 0; i < enemy.size(); i++) {
        enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i] + mapChip->GetScroll_Y());
    }
    for (int i = 0; i < chairx.size(); i++) {
        chair[i]->SetPosition(chairx[i] + mapChip->GetScroll(), chairy[i] + mapChip->GetScroll_Y());
    }

    for (int i = 0; i < enemy.size(); i++) {
        enemy[i]->Update();

        //ナイフと敵との当たり判定
        if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
            if (player->GetHitFlag() == 1) {
                se->KillSE_voice();
                enemy[i]->Dead();

            }
        }

        //ゲームオーバー処理           
        if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
            player->SetDeath(collision->FoundXY(player->GetPosition_x(), player->GetPosition_Y(), enemy[i]->GetPosition_X(), enemy[i]->Getposition_Y(), enemy[i]->GetFlont()));
        }
    }

    /*敵の描画処理*/
    for (int i = 0; i < enemy.size(); i++) {
        enemy[i]->Draw();
    }

    //花瓶の毎フレーム処理
    for (int i = 0; i < vase.size(); i++) {
        //ナイフと花瓶の当たり判定
        if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
            //まだ花瓶があるなら
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

    //扉⇔プレイヤー　の当たり判定
    if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();
    }

    //扉⇔プレイヤー　の当たり判定
    if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();
    }

    //イス⇔プレイヤー　の当たり判定 /*対右*/
    if (mapChip->OnCollisionChair_Right(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();

        for (int i = 0; i < enemy.size(); i++) {
            if (enemy[i]->GetFlont() == 1 && enemy[i]->GetDeath() == 0 &&
                collision->FoundXY(player->GetPosition_x(), player->GetPosition_Y(), enemy[i]->GetPosition_X(), enemy[i]->Getposition_Y(), enemy[i]->GetFlont()))
            {
                player->SetHide(0);
            }
        }
    }

    //イス⇔プレイヤー　の当たり判定　/*対左*/
    else if (mapChip->OnCollisionChair_Left(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        player->Hidding();
        for (int i = 0; i < enemy.size(); i++) {

            if (enemy[i]->GetFlont() == 0 && enemy[i]->GetDeath() == 0 &&
                player->SetDeath(collision->FoundXY(player->GetPosition_x(), player->GetPosition_Y(), enemy[i]->GetPosition_X(), enemy[i]->Getposition_Y(), enemy[i]->GetFlont())))
            {
                player->SetHide(0);
            }
        }
    }

    //分岐
    if (mapChip->OnCollisionWarp_20(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        if (CheckHitKey(KEY_INPUT_S) == 1) {
            //位置を瞬間移動すればよい
            player->SetPosition(mapChip->GetPosition_21_X(), mapChip->GetPosition_21_Y());
            mapChip->SetScroll_Y(1);
        }
    }

    if (mapChip->OnCollisionWarp_22(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        if (CheckHitKey(KEY_INPUT_W) == 1) {
            //位置を瞬間移動すればよい
            mapChip->SetScroll_Y(0);
            player->SetPosition(mapChip->GetPosition_23_X(), mapChip->GetPosition_23_Y());
        }
    }

    if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
        player->GetPlayerSizeX(), player->GetPlayerSizeY()))
    {
        gool = 1;
        Release();
    }

    //ゲームオーバー画面へ遷移
    if (player->death == 1)
    {
        DrawFormatString(1607, 210, GetColor(255, 255, 255), "当たっている！！！");
        se->DiscoverSE_voice();
        over = 1;
    }
}

int Stage::SetGool()
{
    return gool;
}


