#pragma once

#include "SystemBase.h"

#include "System/SimulatePipeline.h"
#include "System/BufferManager.h"
#include "Storage/VFXInstanceStorage.h"

class VFXSimulateSystem :public SystemBase
{
public:
	void Update(IWorld* world) override;
private:
	// シミュレーションパイプライン
	SimulatePipeline sp{};
	// バッファマネージャー
	BufferManager bm{};
	// インスタンスストレージ
	VFXInstanceStorage vfxIS{};
};