#pragma once

#include "StorageBase.h"
#include "SparseSet.h"

template<typename T>
class ComponentStorage :public StorageBase
{
protected:
	SparseSet<T> sparseSet;
};