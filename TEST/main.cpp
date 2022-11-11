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
    SetBackgroundColor(0,0,0);

    //Dxライブラリを初期化 
    if (DxLib_Init() == -1)
    {
        //エラーが出たらマイナス値を返して終了 
        return -1;
    }

    MapChip* mapChip = new MapChip();
    Player* player = new Player();
    Enemy* enemy = new Enemy();
    Collision* collision = new Collision();
    mapChip->Initialize();
    player->Initialize();
    enemy->Initialize();

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

    GameState = Title;

    //背景(プロト)
    int titlescene = LoadGraph("Resources/Scene/title.png");
    int gameoverscene = LoadGraph("Resources/Scene/GameOver.png");
    int gameclearscene = LoadGraph("Resources/Scene/GameClear.png");
    int bgscene1 = LoadGraph("Resources/Scene/bg1.png");
    int bgscene2 = LoadGraph("Resources/Scene/bg2.png");
    int bgscene3 = LoadGraph("Resources/Scene/bg3.png");

    int SCounter = 0;

    //ループテスト用
    //int StartTime;

    while (1)
    {
        //ゲームロジック
        //裏画面を消す
        ClearDrawScreen();

        //ゲームループ
        switch (GameState)
        {
        case Title:
            //初期化
            mapChip->Initialize();
            player->Initialize();
            enemy->Initialize();

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

            //ゲーム画面描画(プロト)
            DrawGraph(0, 0, bgscene1, FALSE);

            //mapChip->Draw();
            player->Update();
            enemy->Update();
            player->SetDeath(collision->Found(player->GetPosition_X(), enemy->GetPosition_X()));



            //扉⇔プレイヤー　の当たり判定
            mapChip->Collision(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY());

            //マップチップ.csのhideの値と連動
            player->SetHide(mapChip->GetHideTrigger());

            ////(※テスト用)ゲームオーバー画面へ
            ////5秒経過で移動
            //if (GetNowCount() - StartTime > 5000)
            //{
            //    GameState = GameOver;
            //}

            //ゲームオーバー画面へ遷移
            if (player->death == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ(テスト用)
            if (player->GetPosition_X() > 500.f)
            {
                GameState = GamePlay2;
                player->Initialize();
            }

            break;

        case GamePlay2:

            //ゲーム画面描画(プロト)
            DrawGraph(0, 0, bgscene2, FALSE);

            //mapChip->Draw();
            player->Update();
            enemy->Update();
            player->SetDeath(collision->Found(player->GetPosition_X(), enemy->GetPosition_X()));



            //扉⇔プレイヤー　の当たり判定
            mapChip->Collision(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY());

            //マップチップ.csのhideの値と連動
            player->SetHide(mapChip->GetHideTrigger());

            if (player->death == 1)
            {
                GameState = GameOver;
            }

            //ステージ3へ(テスト用)
            if (player->GetPosition_X() > 500.f)
            {
                GameState = GamePlay3;
                player->Initialize();
            }

            break;

        case GamePlay3:

            //ゲーム画面描画(プロト)
            DrawGraph(0, 0, bgscene3, FALSE);

            //mapChip->Draw();
            player->Update();
            enemy->Update();
            player->SetDeath(collision->Found(player->GetPosition_X(), enemy->GetPosition_X()));

            //扉⇔プレイヤー　の当たり判定
            mapChip->Collision(player->GetPosition_X(), player->GetPosition_Y(),
                player->GetPlayerSizeX(), player->GetPlayerSizeY());

            //マップチップ.csのhideの値と連動
            player->SetHide(mapChip->GetHideTrigger());

            if (player->death == 1)
            {
                GameState = GameOver;
            }

            //クリア画面へ(テスト用)
            if (player->GetPosition_X() > 500.f)
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