#pragma once

#include <typeindex>
#include <memory>

#include "ComponentStorageBase.h"

class IWorld
{
public:
	/// <summary>
	/// ストレージ取得
	/// </summary>
	/// <typeparam name="T">取得したいストレージ</typeparam>
	/// <returns></returns>
	template<typename T>
	ComponentStorageBase<T>* GetStorage()
	{
		auto it{ storageMap.find(std::type_index(typeid(T))) };

		if (it == storageMap.end())
		{
			return nullptr;
		}

		return static_cast<ComponentStorageBase<T>*>(storages[it->second].get());
	}

	// 仮想デストラクタ
	virtual ~IWorld() = default;
protected:
	// ストレージ
	std::vector<std::unique_ptr<StorageBase>> storages;
	// ストレージと型の対応マップ
	std::unordered_map<std::type_index, size_t> storageMap;
};