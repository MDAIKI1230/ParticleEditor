#pragma once

#include "IWorld.h"

#include "System/BufferManager.h"
#include "System/SimulatePipeline.h"
#include "System/RenderingPipeline.h"

class VFXWorld:public IWorld
{
public:
	// コンストラクタ
	VFXWorld();
	// 更新
	void Update();
	// 描画
	void Draw();
private:
	BufferManager bufferManager;
	SimulatePipeline simulatePipeline;
	RenderingPipeline renderingPipeline;
};