#include "Storage/VFXInstanceStorage.h"

#include "VFXWorld.h"

// コンストラクタ
VFXWorld::VFXWorld()
{
	// コンテナに追加
	storages.push_back(std::make_unique<VFXInstanceStorage>());
	// 対応付け
	storageMap[typeid(VFXInstance)] = storages.size() - 1;
}

// 更新
void VFXWorld::Update()
{
	simulatePipeline.Execute(*static_cast<VFXInstanceStorage*>(GetStorage<VFXInstance>()), bufferManager);
}

// 描画
void VFXWorld::Draw()
{
	renderingPipeline.Draw(*static_cast<VFXInstanceStorage*>(GetStorage<VFXInstance>()), bufferManager);
}