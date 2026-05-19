#include <algorithm>

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

/// <summary>
/// システムの追加(moveされる)
/// </summary>
/// <param name="system">入れたいシステム</param>
void SceneBase::AddSystem(std::unique_ptr<SystemBase> system)
{
	// 入れる位置を探す
	auto it = std::lower_bound(
		systems.begin(),
		systems.end(),
		system,
		[](const std::unique_ptr<SystemBase>& a, const std::unique_ptr<SystemBase>& b)
		{
			return a->GetPriority() > b->GetPriority();
		});

	// その位置に挿入
	systems.insert(it, std::move(system));
}

/// <summary>
/// ストレージの追加(moveされる)
// </summary>
/// <param name="storage">入れたいストレージ</param>
void SceneBase::AddStorage(std::unique_ptr<StorageBase> storage)
{
	// コンテナに追加
	storages.push_back(std::move(storage));
}

void SceneBase::FadeIn()
{
	
}

void SceneBase::FadeOut()
{

}

void SceneBase::Update()
{
	// 更新
	for (int i{ 0 }; i < systems.size(); i++)
	{
		systems[i]->Update(this);
	}
}