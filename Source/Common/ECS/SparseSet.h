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
	T* Get(int entity)
	{
		int id{ sparse[entity] };
		return &dense[id];
	}
	/// <summary>
	/// 追加
	/// </summary>
	/// <param name="entity">エンティティID</param>
	/// <param name="component">追加コンポーネント</param>
	void Add(int entity, const T& component)
	{
		// コンポーネント追加
		dense.push_back(component);
		// エンティティ追加
		entities.push_back(entity);
		// 対応付け
		sparse[entity] = dense.size() - 1;
	}
	/// <summary>
	/// 除外
	/// </summary>
	/// <param name="entity">エンティティID</param>
	void Remove(int entity)
	{
		// 除外コンポーネントインデックス
		int denseIndex{ sparse[entity] };
		// コンポーネントを除外
		dense[denseIndex] = std::move(dense.back());
		dense.pop_back();
		// ID削除
		entities[denseIndex] = std::move(entities.back());
		entities.pop_back();
		// MAPから除外
		sparse.erase(entity);
	}
	// サイズ生成
	void Reserve(size_t size)
	{
		// コンテナのreserve関数を呼ぶ
		dense.reserve(size);
		entities.reserve(size);
	}
	// 全削除
	void Clear()
	{
		// 全部クリア
		dense.clear();
		entities.clear();
		sparse.clear();
	}
	/// <summary>
	/// 取得できるか
	/// </summary>
	/// <param name="output">取得したコンポーネント</param>
	/// <returns>取得できたか</returns>
	bool TryGet(int entity, T& output)
	{
		// 空チェック
		if (sparse.empty())
		{
			return false;
		}

		// エンティティがあるかチェック
		if (sparse.contains(entity))
		{
			// ある場合はアウトプットに入れてtrueを返す
			output = dense[sparse[entity]];
			return true;
		}

		// ここまで来たらfalseを返す
		return false;
	}
	/// <summary>
	/// 持っているか
	/// </summary>
	/// <param name="target">対象</param>
	/// <returns>持っているか</returns>
	bool Has(int entity)
	{
		// 空チェック
		if (sparse.empty())
		{
			return false;
		}

		// エンティティがあるかチェック
		if (sparse.contains(entity))
		{
			// ある場合はtrueを返す
			return true;
		}

		// ここまで来たらfalseを返す
		return false;
	}
	// サイズ
	size_t GetSize()
	{
		// 代表してdenseのサイズを返す(すべて同じ値になっている)
		return dense.size();
	}
	// 実データコンテナ取得
	std::vector<T>* GetDense()
	{
		return &dense;
	}
	// エンティティコンテナ取得
	std::vector<int>* GetEntities()
	{
		return &entities;
	}

	~SparseSet() = default;
private:
	// 実データ
	std::vector<T> dense{};
	// エンティティ
	std::vector<int> entities{};
	// 対応マップ
	std::unordered_map<int, int> sparse{};
};