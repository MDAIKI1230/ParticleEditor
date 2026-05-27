#include "ServiceLocator.h"

#include "VFXComponent.h"

#include "TransformComponent.h"

#include "VFXPlaySystem.h"

void VFXPlaySystem::Update(IWorld* world)
{
	// ストレージ取得
	SparseSetStorageBase<VFXComponent>* vfxStorage{ world->GetStorage<VFXComponent>() };
	SparseSetStorageBase<TransformComponent>* transformStorage{ world->GetStorage<TransformComponent>() };

	for (int entity : *vfxStorage->GetEntities())
	{
		VFXComponent* vfx{ vfxStorage->Get(entity) };
		if (vfx->GetHandle() == -1 && vfx->GetIsPlay() == true)
		{
			ServiceLocator::GetVFXWorld()->CreateInstance(vfx->GetAsset(), transformStorage->Get(entity));
		}
	}
}