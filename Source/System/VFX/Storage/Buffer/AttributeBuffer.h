#pragma once

#include <memory>
#include <vector>

#include "IAttributeBuffer.h"

#include "Allocator.h"
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
	// アロケータ(抽象化済み)
	std::unique_ptr<Allocator> allocator;
	// GPUBufferクラス
	std::unique_ptr<GPUBuffer> gpuBuffer;
	// 値
	std::vector<T> cpuData;
};