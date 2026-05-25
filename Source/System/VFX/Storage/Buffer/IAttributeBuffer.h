#pragma once

#include "VFXConstants.h"

class IAttributeBuffer
{
public:
	// タイプ取得
	virtual AttributeType GetType() = 0;
	// GPUにデータを送る？
	virtual void Upload() = 0;
	// サイズ分生成
	virtual void Resize(size_t _size) = 0;
	// 仮想デストラクタ
	virtual ~IAttributeBuffer() = default;
};