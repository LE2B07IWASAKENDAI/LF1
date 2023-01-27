#include "DxLib.h" 

#include "Title_main.h"
#include "Stage.h"
#include "FPSControl.h"




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
    int cl_bg = LoadGraph("Resources/Scene/Escape_String.png");
    int bgscene1 = LoadGraph("Resources/Scene/bg1.png");
    int bgscene2 = LoadGraph("Resources/Scene/bg2.png");
    int bgscene3 = LoadGraph("Resources/Scene/bg3.png");

    int SCounter = 0;
    float postionCL_x = 0.0f;
    float postiomCL_y = 0.0f;
    int count_CL_X = 0;
    int count_CL_Y = 0;
  
    //ループテスト用
    //int StartTime;

    //FPSの固定で使う変数
    double dNextTime = GetNowCount();

    //クラス呼び出し
    Stage* stage = new Stage();
    Title_main* title = new Title_main();
    FPSControl* fps = new FPSControl();
    fps->Initialize(60.0f, 800);

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
            stage->Initialize();
            //Knife->Initialize();

            //StartTime = GetNowCount();
            //タイトル画面描画
            /*DrawGraph(0, 0, titlescene, FALSE);*/
            postionCL_x = 0.0f;
            count_CL_X = 0;
            title->Draw();
            title->Update();

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
            stage->Update_01();
            //描画
            stage->Drow();
           
            if (stage->SetGameOver() ==1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(1);
                stage->Initialize();
                GameState = GamePlay2;
            }
#pragma endregion
            break;
        case GamePlay2:

#pragma region Stage2
            stage->Update_01();
            //描画
            stage->Drow();
            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }
            //ステージ3へ
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(2);
                stage->Initialize();
                GameState = GamePlay3;
            }        
#pragma endregion
            break;
        case GamePlay3:
#pragma region Stage3       
            stage->Update_01();
            //描画
            stage->Drow();
            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }
            //ステージ4へ
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate(3);
                stage->Initialize();
                GameState = GamePlay4;

            }
#pragma endregion
            break;
        case GamePlay4:

#pragma region Stage4
            stage->Update_01();
            //描画
            stage->Drow();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ5へ
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate2(4);
                GameState = GamePlay5;

                stage->Initialize();

            }
           
#pragma endregion
            break;
        case GamePlay5:

#pragma region Stage5
            stage->Update_02();
            //描画
            stage->Drow();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ6へ
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate2(5);
                GameState = GamePlay6;

                stage->Initialize();

            }

#pragma endregion
            break;
        case GamePlay6:

#pragma region Stage6
            stage->Update_02();
            //描画
            stage->Drow();

            if (stage->SetGameOver() == 1)
            {
                GameState = GameOver;
            }

            //ステージ2へ
            if (stage->SetGool() == 1)
            {
                stage->Release();
                stage->Generate2(6);
                GameState = GamePlay7;

                stage->Initialize();

            }
         
            
#pragma endregion
            break;
        case GamePlay7:

#pragma region Stage7
            stage->Update_02();
            //描画
            stage->Drow();

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

            if (postionCL_x > 10) 
            {
                count_CL_X = 1;
            }
            if (postionCL_x < 0)
            {
                count_CL_X = 0;
            }

            if (postiomCL_y > 20)
            {
                count_CL_Y = 1;
            }
            if (postiomCL_y < 0)
            {
                count_CL_Y = 0;
            }

            if (count_CL_X == 0)
            {
                postionCL_x++;
            }
            else if(count_CL_X ==1)
            {
                postionCL_x--;
            }

            if (count_CL_Y == 0)
            {
                postiomCL_y++;
            }
            else if(count_CL_Y == 1)
            {
                postiomCL_y--;
            }

            //ゲームクリア画面描画
            DrawGraph(0, 0, gameclearscene, FALSE);
            DrawGraph(postionCL_x, postiomCL_y, cl_bg, TRUE);
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

        fps->Wait();
        fps->Draw();
        ScreenFlip();
        //ゲームロジック
        if (ProcessMessage() == -1)break;
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
        

    }
    //何か押されるまで待機 
    //WaitKey();

    //Dxライブラリ終了処理 
    DxLib_End();

    return 0;
}

