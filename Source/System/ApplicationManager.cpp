#include <DxLib.h>
#include "BaseConstants.h"

#include "ApplicationManager.h"

ApplicationManager::ApplicationManager()
{
	ChangeWindowMode(true);
	SetGraphMode(Config::WINDOW_SIZE_W, Config::WINDOW_SIZE_H, Config::COLOR_BIT);
}

int ApplicationManager::ApplicationMain()
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		DrawCircle(100, 100, 100, GetColor(255, 255, 255), true);

		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;
}