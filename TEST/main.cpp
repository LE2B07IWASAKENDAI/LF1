#include "DxLib.h" 
#include "MapChip.h"
#include "Player.h"
#include "Enemy.h"


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
    mapChip->Initialize();
    player->Initialize();
    enemy->Initialize();

    while (1)
    {
        //ゲームロジック

        //裏画面を消す
        ClearDrawScreen();

        mapChip->Draw();
        player->Update();
        enemy->Update();

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