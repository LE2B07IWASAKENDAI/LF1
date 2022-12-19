#include "DxLib.h" 


#include "Stage.h"




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
        GamePlay6,
        GamePlay7,
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

    //FPSの固定で使う変数
    double dNextTime = GetNowCount();


    //クラス呼び出し
    Stage* stage = new Stage();

    


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
            stage->Initialize();
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
                stage-> Release();

                stage->Generate(0);

                GameState = GamePlay1;

            }
            break;

        case GamePlay1:

#pragma region Stage1
   
            //描画
            stage->Drow();
            stage->Update_01();
           
            if (stage->SetGameOver() ==1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
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

            //描画
            stage->Drow();
            stage->Update_01();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
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
          
            //描画
            stage->Drow();
            stage->Update_01();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
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
            //描画
            stage->Drow();
            stage->Update_01();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
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
            //描画
            stage->Drow();
            stage->Update_02();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
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
            //描画
            stage->Drow();
            stage->Update_02();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
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
            //描画
            stage->Drow();
            stage->Update_02();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
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
                stage->Release();
            }

#pragma endregion
            break;

        case GameClear:
#pragma region GameClear
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

#pragma endregion

        ScreenFlip();

        //ゲームロジック

        WaitTimer(20);

        if (ProcessMessage() == -1)break;
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
        

    }
    //何か押されるまで待機 
    //WaitKey();

    //Dxライブラリ終了処理 
    DxLib_End();

    return 0;
}

