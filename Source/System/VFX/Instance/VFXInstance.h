#pragma once

#include "Emitter/Emitter.h"
#include "Module/Module.h"
#include "TransformComponent.h"

#include "System/SimulatePipeline.h"
#include "System/BufferManager.h"

#include "../Asset/VFXAsset.h"

class VFXInstance
{
public:
	// コンストラクタ
	VFXInstance(const VFXAsset& _asset, TransformComponent* _transformComponent, SimulatePipeline& _sp, BufferManager& _bm) :
		asset{ _asset },
		transform{ _transformComponent }
	{
	}

	// エミッター取得
	std::vector<Emitter>& GetEmitters() { return emitters; }
	// モジュール取得
	std::vector<int>& GetModules() { return modules; }
	// Transform参照取得
	const TransformComponent* GetTransform() { return transform; }
private:
	// エミッタ―リスト
	std::vector<Emitter> emitters;
	// 使うモジュール群
	std::vector<int> modules;
	// アセット
	const VFXAsset& asset;

	// Transofrm参照
	TransformComponent* transform;
};