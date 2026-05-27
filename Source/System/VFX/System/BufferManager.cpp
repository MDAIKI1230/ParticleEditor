#include "BufferManager.h"

// メモリ確保
void BufferManager::Allocate(size_t _count)
{
	for (auto& buffer : buffers)
	{
		buffer.second->Allocate(_count);
	}
}

// GPUに渡す。
void BufferManager::UploadAll()
{

}