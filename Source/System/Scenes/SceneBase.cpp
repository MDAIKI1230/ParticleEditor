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

void SceneBase::AddSystem(std::unique_ptr<SystemBase> system)
{
	systems.push_back(std::move(system));
	

}

void SceneBase::AddStorage(std::unique_ptr<StorageBase> storage)
{

}

void SceneBase::FadeIn()
{

}

void SceneBase::FadeOut()
{

}

void Update()
{

}