#pragma once

#include "StorageBase.h"
#include "SparseSet.h"

template<typename T>
class ComponentStorageBase :public StorageBase
{
public:
	// 仮想デストラクタ
	virtual ~ComponentStorageBase();
protected:
	SparseSet<T> sparseSet;
};