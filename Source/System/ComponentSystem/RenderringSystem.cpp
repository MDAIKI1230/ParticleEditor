#include <DxLib.h>

#include "TransformComponent.h"
#include "RendererComponentStorage.h"

#include "RenderingSystem.h"

void RenderingSystem::Update(IWorld* world)
{
	// レンダラーコンポーネントストレージ
	SparseSetStorageBase<RendererComponent>* rendererStorage{ world->GetStorage<RendererComponent>() };
	// Transformストレージ
	SparseSetStorageBase<TransformComponent>* transformStorage{ world->GetStorage<TransformComponent>() };
	// エンティティ
	std::vector<int>* entities{ rendererStorage->GetEntities() };
	// トランスフォーム
	TransformComponent trans{};
	// 全コンポーネントを描画
	for (auto id : *entities)
	{
		// 取得&チェック
		if (!transformStorage->TryGet(id, trans))
		{
			continue;
		}

		// レンダー
		RendererComponent* renderer{ rendererStorage->Get(id) };
		// 行列をセット
		MV1SetMatrix(renderer->GetHandle(), trans.GetWorldMatrix());
		// 描画
		MV1DrawModel(renderer->GetHandle());
	}
}