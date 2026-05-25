#pragma once

#include "Allocator.h"

class LinearAllocator : public Allocator
{
public:
	// 最大サイズを決めるコンストラクタのみ
	LinearAllocator(size_t _size) :
		Allocator(_size)
	{
	}
	// メモリ取得
	Allocation Allocate(size_t _count) override;
	// メモリ解放
	void Reset() override;
	// 使ってる量取得
	size_t GetSize() override;
private:
	// 先頭
	size_t head{ 0 };
};