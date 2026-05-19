#include "IWorld.h"

template<typename T>
const ComponentStorage<T>* IWorld::GetStorage()
{
	// ストレージのインデックス
	size_t index{ storageMap.at(typeid(T)) };
	// ストレージを渡す
	return static_cast<ComponentStorage<T>>(storages[index]);
}