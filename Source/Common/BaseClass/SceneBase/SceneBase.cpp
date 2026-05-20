#include <algorithm>

#include "SceneBase.h"

#include "RenderingSystem.h"
#include "RendererComponentStorage.h"

#include "TransformComponentStorage.h"

SceneBase::SceneBase()
{
	// レンダリングシステム追加
	AddSystem(std::make_unique<RenderingSystem>());
	// レンダラーストレージ追加
	AddStorage<RendererComponent>(std::make_unique<RendererComponentStorage>());
	// Transformも同様
	AddStorage<TransformComponent>(std::make_unique<TransformComponentStorage>());
}

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
void SceneBase::AddSystem(std::unique_ptr<SystemBase> _system)
{
	// 入れる位置を探す
	auto it = std::lower_bound(
		systems.begin(),
		systems.end(),
		_system,
		[](const std::unique_ptr<SystemBase>& a, const std::unique_ptr<SystemBase>& b)
		{
			return a->GetPriority() > b->GetPriority();
		});

	// その位置に挿入
	systems.insert(it, std::move(_system));
}

/// <summary>
/// ストレージの追加(moveされる)
// </summary>
/// <param name="storage">入れたいストレージ</param>
template<typename T>
void SceneBase::AddStorage(std::unique_ptr<ComponentStorageBase<T>> _storage)
{
	// コンテナに追加
	storages.push_back(std::move(_storage));
	// 対応付け
	storageMap[typeid(T)] = storages.size() - 1;
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