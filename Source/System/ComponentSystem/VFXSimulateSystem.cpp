#include "VFXComponent.h"

#include "VFXSimulateSystem.h"

void VFXSimulateSystem::Update(IWorld* world)
{
	// ストレージ
	SparseSetStorageBase<VFXComponent>* vfxStorage{ world->GetStorage<VFXComponent>() };
	
	// 初期化チェック
	for (auto& component : *vfxStorage->GetDense())
	{
		if (component.GetIsInit() == false)
		{
			// ハンドル渡す
			component.SetHandle(vfxIS.GetSize());
			// ストレージに入れ込む
			vfxIS.Add(vfxIS.GetSize(), VFXInstance{ component.GetAsset() });
			// 初期化完了
			component.CompleteInit();
		}
	}

	// シミュレーション
	sp.Execute(&vfxIS, bm);
}