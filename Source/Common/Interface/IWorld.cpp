#include "IWorld.h"

template<typename T>
const ComponentStorage<T>* IWorld::GetStorage()
{
	return storageMap[T];
}