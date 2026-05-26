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
	SparseSet<T>* GetCPUData()
	{
		return &cpuData;
	}

	// メモリ確保
	Allocation Allocate(size_t _count)
	{
		return allocator.Allocate(_count);
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
	// CPUデータ
	SparseSet<T> cpuData;
};