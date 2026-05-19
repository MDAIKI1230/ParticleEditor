#pragma once

#include "ComponentStorage.h"

class IWorld
{
public:
	/// <summary>
	/// ストレージ取得
	/// </summary>
	/// <typeparam name="T">取得したいストレージ</typeparam>
	/// <returns></returns>
	template<typename T>
	const ComponentStorage<T>* GetStorage()
	{
		return static_cast<ComponentStorage<T>>(storageMap.at(typeid(T)));
	}
protected:
	// システムのコンテナ取得
	const std::vector<std::unique_ptr<StorageBase>>* GetSystems()
	{
		return &storages;
	}
private:
	// ストレージ
	std::vector < std::unique_ptr<StorageBase>> storages;
	// ストレージと型の対応マップ
	std::unordered_map<std::type_index, size_t> storageMap;
};