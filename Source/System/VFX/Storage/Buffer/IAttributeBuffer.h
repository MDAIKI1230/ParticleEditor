#pragma once

#include "VFXConstants.h"

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
	// サイズ分生成
	virtual void Resize(size_t _size) = 0;
	// GPUメモリからCPUメモリにキャッシュ
	virtual void ReadBack() =0;
	// 仮想デストラクタ
	virtual ~IAttributeBuffer() = default;

protected:
	// 種類
	AttributeType type;
};