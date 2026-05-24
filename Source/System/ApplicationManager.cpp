#include "BaseConstants.h"

#include "ServiceLocator.h"

#include "Dxlib\DxlibRenderer.h"
#include "Dxlib\DxlibInput.h"

#include "ApplicationManager.h"

ApplicationManager::ApplicationManager()
{
	ChangeWindowMode(true);
	SetGraphMode(Config::WINDOW_SIZE_W, Config::WINDOW_SIZE_H, Config::COLOR_BIT);

	// 生成
	renderer = std::make_unique<DxlibRenderer>();
	input = std::make_unique<DxlibInput>();
	sceneManager = std::make_unique<SceneManager>();
	timeManager = std::make_unique<TimeManager>();

	// サービスロケータに登録
	ServiceLocator::SetRenderer(renderer.get());
	ServiceLocator::SetInput(input.get());
	ServiceLocator::SetTimeManager(timeManager.get());
}

int ApplicationManager::ApplicationMain()
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		input->Update();
		timeManager->Update();

		ClearDrawScreen();

		sceneManager->Update();

		DrawCircle(100, 100, 100, GetColor(255, 255, 255), true);

		ScreenFlip();

		timeManager->WaitNextFrame();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;
}