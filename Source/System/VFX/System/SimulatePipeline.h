#pragma once

#include "../Storage/VFXInstanceStorage.h"

// ComputeShaderについて先生に聞く
class SimulatePipeline
{
public:
	/// <summary>
	/// モジュール更新
	/// </summary>
	/// <param name="_vfxIS">VFXInstanceStorage</param>
	/// <param name="_bm">BufferManager</param>
	void Execute(VFXInstanceStorage& _vfxIS, BufferManager& _bm);
	
};