#pragma once

#include "Allocation.h"

class Allocator
{
public:
	// 最大サイズを決めるコンストラクタのみ
	Allocator(size_t _size) :
		maxSize{ _size }
	{
	}
	// メモリ取得
	virtual Allocation Allocate(size_t _count) = 0;
	// メモリ解放
	virtual void Reset() = 0;
	// 使ってる量取得
	virtual size_t GetSize() = 0;
	// サイズ取得
	size_t GetCapacity() { return maxSize; }
	// 仮想デストラクタ
	virtual ~Allocator() = default;
protected:
	// 最大数
	size_t maxSize;
};