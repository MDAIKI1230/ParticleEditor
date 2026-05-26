#pragma once

#include "Allocation.h"
#include "../../System/BufferManager.h"

class Module
{
public:
	/// <summary>
	/// モジュール更新
	/// </summary>
	/// <param name="_bm">バッファマネージャー</param>
	/// <param name="_allocation">アロケーション</param>
	virtual void Update(BufferManager& _bm, Allocation _allocation) = 0;
};