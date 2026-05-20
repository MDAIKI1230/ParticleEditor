#pragma once

#include "StorageBase.h"
#include "SparseSet.h"

template<typename T>
class ComponentStorageBase :public StorageBase
{
public:
	/// <summary>
	/// 取得
	/// </summary>
	/// <param name="entity">エンティティID</param>
	/// <returns></returns>
	T* Get(int entity) { return sparseSet.Get(entity); }
	/// <summary>
	/// 追加
	/// </summary>
	/// <param name="entity">エンティティID</param>
	/// <param name="component">追加コンポーネント</param>
	void Add(int entity, const T& component) { sparseSet.Add(entity, component); }
	/// <summary>
	/// 除外
	/// </summary>
	/// <param name="entity">エンティティID</param>
	void Remove(int entity) { sparseSet.Remove(entity); }
	// サイズ生成
	void Reserve(size_t size) { sparseSet.Reserve(size); }
	// 全削除
	void Clear() { sparseSet.Clear(); }
	/// <summary>
	/// 取得できるか
	/// </summary>
	/// <param name="output">取得したコンポーネント</param>
	/// <returns>取得できたか</returns>
	bool TryGet(int entity, T& output) { return sparseSet.TryGet(entity, output); }
	/// <summary>
	/// 持っているか
	/// </summary>
	/// <param name="target">対象</param>
	/// <returns>持っているか</returns>
	bool Has(int entity) { return sparseSet.Has(entity); }
	// サイズ
	size_t GetSize() { return sparseSet.GetSize(); }
	// 実データコンテナ取得
	std::vector<T>* GetDense() { return sparseSet.GetDense(); }
	// エンティティコンテナ取得
	std::vector<int>* GetEntities() { return sparseSet.GetEntities(); }

	// 仮想デストラクタ
	virtual ~ComponentStorageBase() = default;
protected:
	SparseSet<T> sparseSet{};
};