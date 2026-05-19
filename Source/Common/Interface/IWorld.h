#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "SystemBase.h"
#include "StorageBase.h"
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
	const ComponentStorage<T>* GetStorage();
protected:
	// システム
	std::vector<std::unique_ptr<SystemBase>> systems;
	// ストレージ
	std::vector < std::unique_ptr<StorageBase>> storages;
	// ストレージと型の対応マップ
	std::unordered_map<std::type_index, size_t> storageMap;
};