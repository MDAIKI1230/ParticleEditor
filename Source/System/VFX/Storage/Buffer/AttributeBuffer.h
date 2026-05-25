#pragma once

#include "IAttributeBuffer.h"

class AttributeBuffer:public IAttributeBuffer
{
public:
	// タイプ取得
	AttributeType GetType()override;
	// GPUにデータを送る？
	void Upload();
	// サイズ分生成
	void Resize(size_t _size);
private:

};