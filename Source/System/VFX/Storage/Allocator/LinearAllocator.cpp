#include "LinearAllocator.h"

// メモリ取得
Allocation LinearAllocator::Allocate(size_t _count)
{
	// 次の先頭
	size_t nextHead{ head + _count };
	// 最大サイズを超えないか。
	if (maxSize >= nextHead)
	{
		return{};
	}

	// 先頭保存
	size_t start{ head };
	// 先頭を更新
	head = nextHead;

	return { start,_count };
}

// メモリ解放
void LinearAllocator::Reset()
{
	head = 0;
}

// 使ってる量取得
size_t LinearAllocator::GetSize()
{
	return head;
}