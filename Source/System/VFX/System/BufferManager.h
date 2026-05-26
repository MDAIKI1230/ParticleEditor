#pragma once

#include <unordered_map>
#include <memory>

#include "../Storage/Buffer/AttributeBuffer.h"

class BufferManager
{
public:
	// バッファ取得関数
	template<typename T>
	AttributeBuffer<T>& GetBuffer(AttributeType _type);
	// バッファ作成
	template<typename T>
	void CreateBuffer(AttributeType _type, size_t _size);
	// メモリ確保
	void Allocate(size_t _count);

	// GPUに渡す。
	void UploadAll();
private:
	// タイプと属性コンテナの対応マップ
	std::unordered_map<AttributeType, std::unique_ptr<IAttributeBuffer>> buffers;
};