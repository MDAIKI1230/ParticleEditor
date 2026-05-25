#pragma once

#include <memory>

#include "IAttributeBuffer.h"

#include "SparseSet.h"
#include "LinearAllocator.h"
#include "GPUBuffer.h"

template<typename T> 
class AttributeBuffer:public IAttributeBuffer
{
public:
	// コンストラクタ
	AttributeBuffer(size_t _size);
	// GPUにデータを送る？
	void Upload() override;
	// サイズ分生成
	void Resize(size_t _size) override;
	// GPUメモリからCPUメモリにキャッシュ
	void ReadBack() override;
private:
	// アロケータ
	LinearAllocator allocator;
	// GPUBufferクラス
	GPUBuffer gpuBuffer;
	// 値
	SparseSet<T> cpuData;
};