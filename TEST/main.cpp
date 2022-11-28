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
    Enemy* enemy = new Enemy();
    Vase* vase = new Vase();

    Collision* collision = new Collision();

    mapChip->Initialize();
    player->Initialize();
    enemy->Initialize();
    vase->Initialize();

    //ゲームループ
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

    GameState = GamePlay2;

    //背景(プロト)
    int titlescene = LoadGraph("Resources/Scene/title.png");
    int gameoverscene = LoadGraph("Resources/Scene/GameOver.png");
    int gameclearscene = LoadGraph("Resources/Scene/GameClear.png");
    int bgscene1 = LoadGraph("Resources/Scene/bg1.png");
    int bgscene2 = LoadGraph("Resources/Scene/bg2.png");
    int bgscene3 = LoadGraph("Resources/Scene/bg3.png");

    int SCounter = 0;

    int load = 0;

    static bool mapInit = true;
    //ループテスト用
    //int StartTime;

    //FPSの固定で使う変数
    double dNextTime = GetNowCount();


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
            enemy->Initialize();
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
                GameState = GamePlay1;

            }
            break;

        case GamePlay1:
            load += 1;

            //マップ番号をセット
            mapChip->SetMapNumber(0);
            mapChip->Draw(player->GetPosition_X());

            player->Update();
            
            enemy->Set_position(mapChip->Get_position_8_X(), mapChip->Get_position_8_Y());
            enemy->Update();
            enemy->Draw();

            //ナイフと敵との当たり判定
            if (collision->KnifetoEnemy(player->GetKnifePos(), enemy->GetPosition_X())) {
                if (player->GetHitFlag() == 1) {
                    enemy->Dead();
                }
            }

            //扉⇔プレイヤー　の当たり判定
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }            

            //ゲームオーバー処理           
            if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy->GetDeath() == 0) {
                player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont()));
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
                mapChip->Initialize();
                player->Initialize();
                enemy->Initialize();

                GameState = GamePlay2;
            }

            break;

        case GamePlay2:
            //for (int i = 0; i < 10; i++) {
            //    if (mapInit) {
            //        //初期化
            //        mapChip->Initialize();
            //        player->Initialize();
            //        enemy->Initialize();
            //        mapInit = false;
            //    }
            //}


            //マップ番号をセット
            mapChip->SetMapNumber(1);
            mapChip->Draw(player->GetPosition_X());

            vase->SetPosition(mapChip->GetPosition_12_X(), mapChip->GetPosition_12_Y());
            vase->Draw();

            player->Update();

            if (enemy->GetDeath() == 0) {
                enemy->Set_position(mapChip->Get_position_8_X(), mapChip->Get_position_8_Y());
                enemy->Update();
                enemy->Draw();
            }


            //ナイフと敵との当たり判定
            if (collision->KnifetoEnemy(player->GetKnifePos(), enemy->GetPosition_X())) {
                if (player->GetHitFlag() == 1) {
                    enemy->Dead();
                    if (enemy->GetDeath() == 1) {
                        player->SetDisapperKnifeTrigger(1);

                        //delete以外でやるならトリガー用意して、一度当たったらtrueで二度と判定の条件式内に処理が通らないようにする
                        delete enemy;
                    }
                }
            }

            //ナイフと花瓶の当たり判定
            if (collision->KnifetoVase(player->GetKnifePos(), vase->GetPosition())) {
                //まだ花瓶があるなら
                if (vase->GetDead() == 0) {
                    vase->SetDead(1);
                    player->SetDisapperKnifeTrigger(1);

                    delete vase;
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

                if (enemy->GetFlont() == 1 && enemy->GetDeath() == 0 &&
                    collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont())) 
                {
                    player->SetHide(0);
                }
            }

            //イス⇔プレイヤー　の当たり判定　/*対左*/
            else if (mapChip->OnCollisionChair_Left(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                 player->Hidding();
                 if (enemy->GetFlont() == 0 && enemy->GetDeath() == 0 &&
                        player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont())))
                 {
                     player->SetHide(0);
                 }
            }

            //ゲームオーバー処理           
            if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy->GetDeath() == 0) {
                player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont()));
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
                mapChip->Initialize();
                player->Initialize();
                enemy->Initialize();

                GameState = GamePlay3;
            }

            break;

        case GamePlay3:

            //マップ番号をセット
            mapChip->SetMapNumber(2);
            mapChip->Draw(player->GetPosition_X());

            player->Update();

            enemy->Set_position(mapChip->Get_position_8_X(), mapChip->Get_position_8_Y());
            enemy->Update();
            enemy->Draw();


            //ナイフと敵との当たり判定
            if (collision->KnifetoEnemy(player->GetKnifePos(), enemy->GetPosition_X())) {
                if (player->GetHitFlag() == 1) {
                    enemy->Dead();
                }
            }

            //扉⇔プレイヤー　の当たり判定
            if (mapChip->OnCollisionDoor(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY()))
            {
                player->Hidding();
            }

            //ゲームオーバー処理           
            if (player->GetkeyPermission() == false && player->GetHide() == 0 && enemy->GetDeath() == 0) {
                player->SetDeath(collision->Found(player->GetPosition_x(), enemy->GetPosition_X(), enemy->GetFlont()));
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
                GameState = GameClear;
            }

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