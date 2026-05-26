#include "BufferManager.h"

// バッファ取得関数
template<typename T>
AttributeBuffer<T>& BufferManager::GetBuffer(AttributeType _type)
{
	return buffers[_type];
}

// バッファ作成
template<typename T>
void BufferManager::CreateBuffer(AttributeType _type, size_t _size)
{
	buffers[_type] = std::make_unique<AttributeBuffer<T>>( _size );
}

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