#include "SparseSet.h"

/// <summary>
/// 取得
/// </summary>
/// <param name="entity">エンティティID</param>
/// <returns></returns>
template<typename T>
T* SparseSet<T>::Get(int entity)
{
	return sparse[entity];
}

// 追加
template<typename T>
void SparseSet<T>::Add(int entity, T* component)
{
	// コンポーネント追加
	dense.push_back(component);
	// エンティティ追加
	entities.push_back(entity);
	// 対応付け
	sparse[entity] = dense.size() - 1;
}

// 除外
template<typename T>
void SparseSet<T>::Remove(int entity)
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
template<typename T>
void SparseSet<T>::Reserve(size_t size)
{
	// コンテナのreserve関数を呼ぶ
	dense.reserve(size);
	entities.reserve(size);
}

// 全削除
template<typename T>
void SparseSet<T>::Clear()
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
template<typename T>
bool SparseSet<T>::TryGet(int entity, T* output)
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
template<typename T>
bool SparseSet<T>::Has(int entity)
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
template<typename T>
size_t SparseSet<T>::GetSize()
{
	// 代表してdenseのサイズを返す(すべて同じ値になっている)
	return dense.size();
}

// 実データコンテナ取得
template<typename T>
std::vector<T>* SparseSet<T>::GetDense()
{
	return dense;
}

// エンティティコンテナ取得
template<typename T>
std::vector<int>* SparseSet<T>::GetEntities()
{
	return entities;
}