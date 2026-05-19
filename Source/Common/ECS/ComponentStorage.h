#pragma once

#include "StorageBase.h"
#include "SparseSet.h"

template<typename T>
class ComponentStorage :public StorageBase
{
public:
	// 仮想デストラクタ
	virtual ~ComponentStorage();
protected:
	SparseSet<T> sparseSet;
};