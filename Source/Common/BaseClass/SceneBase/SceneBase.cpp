#include "SceneBase.h"

void SceneBase::Execute()
{
	switch (state)
	{
	case SceneState::INITIALIZE:
		// 初期化タスクの生成
		Initialize();
		break;
	case SceneState::LOADING:
		// wait処理
		break;
	case SceneState::FADEIN:
		// ロード画面からシーンに移行。
		FadeIn();
		break;
	case SceneState::UPDATE:
		// 更新(物理更新も含む)
		Update();
		break;
	case SceneState::TERMINATE:
		// 終了
		Terminate();
		break;
	case SceneState::FADEOUT:
		// ロードシーンに移行
		FadeOut();
		break;
	default:
		break;
	}
}

void SceneBase::FadeIn()
{

}

void SceneBase::FadeOut()
{

}

void SceneBase::Update()
{
	// システムコンテナ
	const std::vector<std::unique_ptr<SystemBase>>* systems{ GetSystems() };

	// 更新
	for (int i{ 0 }; i < systems->size(); i++)
	{
		systems->at(i)->Update();
	}
}