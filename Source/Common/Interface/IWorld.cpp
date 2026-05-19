#include "IWorld.h"

/// <summary>
/// ストレージ取得
/// </summary>
/// <typeparam name="T">取得したいストレージ</typeparam>
/// <returns></returns>
template<typename T>
const ComponentStorage<T>* IWorld::GetStorage()
{
	// ストレージのインデックス
	size_t index{ storageMap.at(typeid(T)) };
	// ストレージを渡す
	return static_cast<ComponentStorage<T>>(storages[index]);
}

/// <summary>
/// システムの追加(moveされる)
/// </summary>
/// <param name="system">入れたいシステム</param>
void IWorld::AddSystem(std::unique_ptr<SystemBase> system)
{
	// システムを追加
	systems.push_back(std::move(system));
}

/// <summary>
/// ストレージの追加(moveされる)
/// </summary>
/// <param name="storage">入れたいストレージ</param>
void IWorld::AddStorage(std::unique_ptr<StorageBase> storage)
{
	// ストレージを追加
	storages.push_back(std::move(storage));
}

// システムのコンテナ取得
const std::vector<std::unique_ptr<SystemBase>>* IWorld::GetSystems()
{
	return &systems;
}