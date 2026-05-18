#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

template<typename T>
class SparseSet
{
public:
	SparseSet() = default;

	// 追加
	T* Add();
	/// <summary>
	/// 取得
	/// </summary>
	/// <param name="entity">エンティティID</param>
	/// <returns></returns>
	T* Get(int entity);
	// 除外
	void Remove();
	// サイズ生成
	void Reserve();
	// 全削除
	void Clear();
	/// <summary>
	/// 取得できるか
	/// </summary>
	/// <param name="output">取得したコンポーネント</param>
	/// <returns>取得できたか</returns>
	bool TryGet(T* output);
	/// <summary>
	/// 持っているか
	/// </summary>
	/// <param name="target">対象</param>
	/// <returns>持っているか</returns>
	bool Has(const T* target);
	// サイズ
	size_t GetSize();
	// 実データコンテナ取得
	std::vector* GetDense();
	// エンティティコンテナ取得
	std::vector* GetEntities();

	~SparseSet();
public:
	// 実データ
	std::vector<T> dense;
	// エンティティ
	std::vector<int> entities;
	// 対応マップ
	std::unordered_map<int,T> sparse;
};