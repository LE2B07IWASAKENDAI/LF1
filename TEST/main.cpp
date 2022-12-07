#include "DxLib.h" 

#include "MapChip.h"
#include "Player.h"
#include "Enemy.h"
#include "Vase.h"

#include "Collision.h"

void SetItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int mapNumber);
void DrawItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int ghandle);
void DeleteItem(std::vector<float>& posx, std::vector<float>& posy);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow

)
{
    //ウィンドウモードに設定 
    ChangeWindowMode(TRUE);

    const char TITLE[] = "title01";

    const int WIN_HEIGHT = 900;
    const int WIN_WITDH = 1800;



    // ウィンドウのタイトル
    //SetMainWindowText("title01");
    //ウィンドウサイズを手動では変更できず、 
    //かつウィンドウサイズに合わせて拡大できないようにする 
    SetWindowSizeChangeEnableFlag(FALSE, FALSE);

    // 画面サイズの最大サイズ、カラービット数を設定
    SetGraphMode(WIN_WITDH, WIN_HEIGHT, 32);

    // 画面サイズを設定（解像度との比率で設定）
    SetWindowSizeExtendRate(1.0);

    // 画面の背景色を設定する
    SetBackgroundColor(0, 0, 0);

    //Dxライブラリを初期化 
    if (DxLib_Init() == -1)
    {
        //エラーが出たらマイナス値を返して終了 
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

    //ゲームループ
    int GameState;
    enum GameState
    {
        Title,
        GamePlay1,
        GamePlay2,
        GamePlay3,
        GamePlay4,
        GamePlay5,
        GameOver,
        GameClear
    };

    GameState = Title;

    //背景(プロト)
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


    //花瓶フラグ
    int BreakFlag = 0;

    static bool mapInit = true;
    //ループテスト用
    //int StartTime;

    //FPSの固定で使う変数
    double dNextTime = GetNowCount();


    //マップチップで標示する物の座標格納変数
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
        //ゲームロジック
        //裏画面を消す
        ClearDrawScreen();
        //60FPSでの固定
        dNextTime += 16.66f;
        if (dNextTime > GetNowCount())
        {
            WaitTimer((int)dNextTime - GetNowCount());
        }

        //ゲームループ
        switch (GameState)
        {
        case Title:
            //初期化
            mapChip->Initialize();
            player->Initialize();
            //Knife->Initialize();

            //StartTime = GetNowCount();
            //タイトル画面描画
            DrawGraph(0, 0, titlescene, FALSE);

            //(テスト用)スペースキー押下でゲーム開始
            //スペースキー押したら
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
            //ゲーム画面へ遷移
            if (SCounter == 1)
            {
                //vector型の変数の要素を全削除、メモリ解放。
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //コンテナのサイズまでメモリを解放
                    enemy.shrink_to_fit();
                }

                //マップ番号をセット
                mapChip->SetMapNumber(0);

                //マップチップ番号の位置を保存する
                    //マップチップから位置を挿入
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

                GameState = GamePlay1;

            }
            break;

        case GamePlay1:

#pragma region Stage1
            //マップ番号をセット
            mapChip->SetMapNumber(0);
            mapChip->Draw(player->GetPosition_X());

            player->Update();


            //マップチップの描画
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);

            //プレイヤーの更新
            player->Update();

            /*敵の位置挿入*/
            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Update();

                //ナイフと敵との当たり判定
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        enemy[i]->Dead();
                    }
                }
                //ゲームオーバー処理           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            /*敵の描画処理*/
            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Draw();
            }


            //扉⇔プレイヤー　の当たり判定
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }

            //ゲームオーバー画面へ遷移
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "当たっている！！！");
                GameState = GameOver;
            }

            //ステージ2へ
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector型の変数の要素を全削除、メモリ解放。
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(eposx, eposy);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //コンテナのサイズまでメモリを解放
                    enemy.shrink_to_fit();
                }

                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay2;

                //マップ番号をセット
                mapChip->SetMapNumber(1);


                //マップチップ番号の位置を保存する
                   //マップチップから位置を挿入
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

                //enemy push_backをしていく
                //for (int i = 0; i < 14; i++) {
                //    for (int j = 0; j < 84; j++) {
                //        //プレイヤーが扉の前に来たら当たりの判定を入れる
                //        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                //            //enemyのオブジェクト生成
                //            enemy.push_back(new Enemy());
                //        }
                //    }
                //}

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                //for (int i = 0; i < 14; i++) {
                //    for (int j = 0; j < 84; j++) {
                //        //プレイヤーが扉の前に来たら当たりの判定を入れる
                //        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                //            //enemyのオブジェクト生成
                //            vase.push_back(new Vase());
                //        }
                //    }
                //}

                for (int i = 0; i < vase.size(); i++) {
                    vase[i]->Initialize();
                }

            }
#pragma endregion
            break;
        case GamePlay2:

#pragma region Stage2
            mapChip->Draw(player->GetPosition_X());

            //マップチップの描画
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);

            //プレイヤーの更新
            player->Update();

            /*花瓶の更新*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*敵の更新*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }


            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //ナイフと敵との当たり判定
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        enemy[i]->Dead();
                    }
                }

                //ゲームオーバー処理           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            for (int i = 0; i < enemy.size(); i++) {
                enemy[i]->Draw();
            }

            for (int i = 0; i < vase.size(); i++) {
                //ナイフと花瓶の当たり判定
                if (collision->KnifetoVase(player->GetKnifePos(), vase[i]->GetPosition())) {
                    //まだ花瓶があるなら
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
                        collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()))
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
                        player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont())))
                    {
                        player->SetHide(0);
                    }
                }
            }

            //ゲームオーバー画面へ遷移
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "当たっている！！！");

                //GameState = GameOver;
            }

            //ステージ3へ
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector型の変数の要素を全削除、メモリ解放。
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

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

                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay3;

                //マップ番号をセット
                mapChip->SetMapNumber(2);


                //マップチップ番号の位置を保存する
                   //マップチップから位置を挿入
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

                //enemy push_backをしていく
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                            //enemyのオブジェクト生成
                            enemy.push_back(new Enemy());
                        }
                    }
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                            //enemyのオブジェクト生成
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
            //マップ番号をセット
            mapChip->Draw(player->GetPosition_X());

            player->Update();

            //マップチップの描画
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);


            //プレイヤーの更新
            player->Update();


            /*花瓶の更新*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*敵の更新*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            //花瓶の描画
            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            //敵の毎フレーム処理
            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //ナイフと敵との当たり判定
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        enemy[i]->Dead();
                    }
                }

                //ゲームオーバー処理           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            //敵の描画
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
                        collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()))
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
                        player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont())))
                    {
                        player->SetHide(0);
                    }
                }
            }

            //ゲームオーバー画面へ遷移
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "当たっている！！！");

                //GameState = GameOver;
            }

            //クリア
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector型の変数の要素を全削除、メモリ解放。
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //コンテナのサイズまでメモリを解放
                    enemy.shrink_to_fit();
                }

                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay4;

                //マップ番号をセット
                mapChip->SetMapNumber(3);


                //マップチップ番号の位置を保存する
                   //マップチップから位置を挿入
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

                //enemy push_backをしていく
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                            //enemyのオブジェクト生成
                            enemy.push_back(new Enemy());
                        }
                    }
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                            //enemyのオブジェクト生成
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
            //マップ番号をセット
            mapChip->Draw(player->GetPosition_X());

            player->Update();

            //マップチップの描画
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);


            //プレイヤーの更新
            player->Update();


            /*花瓶の更新*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*敵の更新*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            //花瓶の描画
            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            //敵の毎フレーム処理
            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //ナイフと敵との当たり判定
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        enemy[i]->Dead();
                    }
                }

                //ゲームオーバー処理           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            //敵の描画
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
                        collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()))
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
                        player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont())))
                    {
                        player->SetHide(0);
                    }
                }
            }

            //ゲームオーバー画面へ遷移
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "当たっている！！！");

                //GameState = GameOver;
            }

            //クリア
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector型の変数の要素を全削除、メモリ解放。
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

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

                mapChip->Initialize();
                player->Initialize();
                GameState = GamePlay5;

                //マップ番号をセット
                mapChip->SetMapNumber(4);


                //マップチップ番号の位置を保存する
                   //マップチップから位置を挿入
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

                //enemy push_backをしていく
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                            //enemyのオブジェクト生成
                            enemy.push_back(new Enemy());
                        }
                    }
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                            //enemyのオブジェクト生成
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
            //マップ番号をセット
            mapChip->Draw(player->GetPosition_X());

            player->Update();

            //マップチップの描画
            DrawItem(open_doorx, open_doory, mapChip, ghandleOPD);
            DrawItem(doorx, doory, mapChip, ghandleCLD);
            DrawItem(chairx, chairy, mapChip, ghandleCHR);
            DrawItem(deskx, desky, mapChip, ghandleDSK);


            //プレイヤーの更新
            player->Update();


            /*花瓶の更新*/
            for (int i = 0; i < vasex.size(); i++) {
                vase[i]->SetPosition(vasex[i] + mapChip->GetScroll(), vasey[i]);
            }
            /*敵の更新*/
            for (int i = 0; i < eposx.size(); i++) {
                enemy[i]->Set_position(eposx[i] + mapChip->GetScroll(), eposy[i]);
            }

            //花瓶の描画
            for (int i = 0; i < vase.size(); i++) {
                vase[i]->Draw();
            }

            //敵の毎フレーム処理
            for (int i = 0; i < enemy.size(); i++) {

                enemy[i]->Update();

                //ナイフと敵との当たり判定
                if (collision->KnifetoEnemy(player->GetKnifePos(), enemy[i]->GetPosition_X())) {
                    if (player->GetHitFlag() == 1) {
                        enemy[i]->Dead();
                    }
                }

                //ゲームオーバー処理           
                if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy[i]->GetDeath() == 0) {
                    player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()));
                }
            }

            //敵の描画
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
                        collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont()))
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
                        player->SetDeath(collision->Found(player->GetPosition_x(), enemy[i]->GetPosition_X(), enemy[i]->GetFlont())))
                    {
                        player->SetHide(0);
                    }
                }
            }

            //ゲームオーバー画面へ遷移
            if (player->death == 1)
            {
                DrawFormatString(1607, 210, GetColor(255, 255, 255), "当たっている！！！");

                //GameState = GameOver;
            }

            //クリア
            if (mapChip->OnCollisionGoal(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                //vector型の変数の要素を全削除、メモリ解放。
                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(deskx, desky);
                DeleteItem(chairx, chairy);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

                for (int i = 0; i < enemy.size(); i++) {
                    enemy.clear();
                    //コンテナのサイズまでメモリを解放
                    enemy.shrink_to_fit();
                }

                mapChip->Initialize();
                player->Initialize();
                GameState = GameClear;

                //マップ番号をセット
                //mapChip->SetMapNumber(4);


                //マップチップ番号の位置を保存する
                   //マップチップから位置を挿入
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

                //enemy push_backをしていく
                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 8) {
                            //enemyのオブジェクト生成
                            enemy.push_back(new Enemy());
                        }
                    }
                }

                for (int i = 0; i < enemy.size(); i++) {
                    enemy[i]->Initialize();
                }

                for (int i = 0; i < 14; i++) {
                    for (int j = 0; j < 84; j++) {
                        //プレイヤーが扉の前に来たら当たりの判定を入れる
                        if (mapChip->mapData[mapChip->GetMapNumber()].data[i][j] == 10) {
                            //enemyのオブジェクト生成
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

        case GameOver:
            //ゲームオーバー画面描画
            DrawGraph(0, 0, gameoverscene, FALSE);

            //(テスト用)スペース押下でタイトルへ戻る
            //スペースキー押したら
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
            //タイトル画面へ遷移
            if (SCounter == 1)
            {
                GameState = Title;
                //vector型の変数の要素を全削除、メモリ解放。

                DeleteItem(open_doorx, open_doory);
                DeleteItem(doorx, doory);
                DeleteItem(chairx, chairy);
                DeleteItem(deskx, desky);

                DeleteItem(eposx, eposy);
                DeleteItem(vasex, vasey);

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
            }
            break;

        case GameClear:
            //ゲームクリア画面描画
            DrawGraph(0, 0, gameclearscene, FALSE);

            //(テスト用)スペース押下でタイトルへ戻る
            //スペースキー押したら
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
            //タイトル画面へ遷移
            if (SCounter == 1)
            {
                GameState = Title;
            }
            break;
        }

        ScreenFlip();

        //ゲームロジック

        WaitTimer(20);

        if (ProcessMessage() == -1)break;
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;

    }
    //何か押されるまで待機 
    //WaitKey();
    delete mapChip;
    //Dxライブラリ終了処理 
    DxLib_End();

    return 0;
}

void SetItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip,int chipNumber ) {
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

void DrawItem(std::vector<float>& posx, std::vector<float>& posy, MapChip* mapchip, int ghandle) {

    for (int i = 0; i < posx.size(); i++) {
        DrawGraph(posx[i] + mapchip->GetScroll(), posy[i], ghandle, TRUE);
    }
}

void DeleteItem(std::vector<float>& posx, std::vector<float>& posy) {
    for (int i = 0; i < posx.size(); i++) {
        posx.clear();
        posx.shrink_to_fit();
        posy.clear();
        posy.shrink_to_fit();
    }
}
