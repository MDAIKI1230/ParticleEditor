#pragma once

#include "IWorld.h"

#include "TransformComponent.h"

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
	/// <summary>
	/// VFXインスタンス作成
	/// </summary>
	/// <param name="asset">アセット</param>
	/// <returns>ハンドル</returns>
	int CreateInstance(const VFXAsset& _asset, TransformComponent* _transformComponent);
private:
	BufferManager bufferManager;
	SimulatePipeline simulatePipeline;
	RenderingPipeline renderingPipeline;
};