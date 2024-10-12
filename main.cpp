//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include"DxLib.h"
#include"Enemy.h"
#include"Player.h"


//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	// 画面モードの設定
	SetGraphMode(1920, 1080, 16);		// 解像度を640*480、colorを16bitに設定.
	ChangeWindowMode(FALSE);			// ウインドウモードを変更(FALSE＝フルクリーン)

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	//インスタンス化
	Boss *boss = new Boss();
	Player* play = new Player();

	//初期化
	play->Init();
	boss->Init();


	// ゲームループ.
	while (1)
	{

		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();

		play->Update(*boss);
		boss->Update(*play);

		play->Draw();
		boss->Draw();



		// 裏画面の内容を表画面にコピーする（描画の確定）.
		ScreenFlip();

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// マイナスの値（エラー値）が返ってきたらループを抜ける
		if (ProcessMessage() < 0)
		{
			return 0;					// ソフトの終了
		}
		// もしＥＳＣキーが押されていたらループから抜ける
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{

			return 0;					// ソフトの終了
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;					// ソフトの終了
}
