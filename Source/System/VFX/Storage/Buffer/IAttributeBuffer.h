#pragma once

#include "VFXConstants.h"
#include "Allocation.h"

class IAttributeBuffer
{
public:
	// タイプ取得
	AttributeType GetType()
	{
		return type;
	}
	// GPUにデータを送る？
	virtual void Upload() = 0;
	// GPUメモリからCPUメモリにキャッシュ
	virtual void ReadBack() =0;
	// メモリ確保
	virtual Allocation Allocate(size_t _count) = 0;
	// 仮想デストラクタ
	virtual ~IAttributeBuffer() = default;

protected:
	// 種類
	AttributeType type;
};