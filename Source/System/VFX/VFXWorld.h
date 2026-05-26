#pragma once

#include "IWorld.h"

#include "Storage/VFXInstanceStorage.h"
#include "System/BufferManager.h"
#include "System/SimulatePipeline.h"

class VFXWorld:public IWorld
{
public:
	// コンストラクタ。
	VFXWorld();
	// 更新
	void Update();
	// 描画
	void Draw();
private:
	BufferManager bufferManager;
	SimulatePipeline simulatePipeline;
};