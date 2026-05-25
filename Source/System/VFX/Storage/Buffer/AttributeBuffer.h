#pragma once

#include "IAttributeBuffer.h"

#include "SparseSet.h"
#include "LinearAllocator.h"
#include "GPUBuffer.h"

template<typename T> 
class AttributeBuffer:public IAttributeBuffer
{
public:
	// コンストラクタ
	AttributeBuffer(size_t _size) :
		allocator{ _size }
	{
		cpuData.Reserve(_size);
	}

	// CPUデータ取得
	T& operator[](size_t _index)
	{
		return cpuData.Get(_index);
	}

	// GPUにデータを送る？
	void Upload() override
	{

	}

	// GPUメモリからCPUメモリにキャッシュ
	void ReadBack() override
	{

	}
private:
	// アロケータ
	LinearAllocator allocator;
	// GPUBufferクラス
	GPUBuffer gpuBuffer;
	// 値
	SparseSet<T> cpuData;
};