#include <DxLib.h>

#include "TransformComponent.h"
#include "RendererComponentStorage.h"

#include "RenderingSystem.h"

void RenderingSystem::Update(IWorld* world)
{
	// レンダラーコンポーネントストレージ
	ComponentStorageBase<RendererComponent>* rendererStorage{ world->GetStorage<RendererComponent>() };
	// Transformストレージ
	ComponentStorageBase<TransformComponent>* transformStorage{ world->GetStorage<TransformComponent>() };
	// エンティティ
	std::vector<int>* entities{ rendererStorage->GetEntities() };
	// 全コンポーネントを描画
	for (auto id : *entities)
	{
		// トランスフォーム
		TransformComponent* trans{ transformStorage->Get(id) };
		// レンダー
		RendererComponent* renderer{ rendererStorage->Get(id) };
		// 行列をセット
		MV1SetMatrix(renderer->GetHandle(), trans->GetWorldMatrix());
		// 描画
		MV1DrawModel(renderer->GetHandle());
	}
}