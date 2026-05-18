#pragma once

#include <vector>
#include <unordered_map>

template<typename T>
class SparseSet
{
public:
	SparseSet() = default;

	/// <summary>
	/// 取得
	/// </summary>
	/// <param name="entity">エンティティID</param>
	/// <returns></returns>
	T* Get(int entity);
	/// <summary>
	/// 追加
	/// </summary>
	/// <param name="entity">エンティティID</param>
	/// <param name="component">追加コンポーネント</param>
	void Add(int entity, T* component);
	/// <summary>
	/// 除外
	/// </summary>
	/// <param name="entity">エンティティID</param>
	void Remove(int entity);
	// サイズ生成
	void Reserve(size_t size);
	// 全削除
	void Clear();
	/// <summary>
	/// 取得できるか
	/// </summary>
	/// <param name="output">取得したコンポーネント</param>
	/// <returns>取得できたか</returns>
	bool TryGet(int entity, T* output);
	/// <summary>
	/// 持っているか
	/// </summary>
	/// <param name="target">対象</param>
	/// <returns>持っているか</returns>
	bool Has(int entity);
	// サイズ
	size_t GetSize();
	// 実データコンテナ取得
	std::vector<T>* GetDense();
	// エンティティコンテナ取得
	std::vector<int>* GetEntities();

	~SparseSet();
public:
	// 実データ
	std::vector<T> dense;
	// エンティティ
	std::vector<int> entities;
	// 対応マップ
	std::unordered_map<int,int> sparse;
};