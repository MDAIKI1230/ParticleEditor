#pragma once

#include <typeindex>

#include "Instance/Module/Module.h"

#include "../Storage/VFXInstanceStorage.h"

class SimulatePipeline
{
public:
	SimulatePipeline();
	/// <summary>
	/// モジュール更新
	/// </summary>
	/// <param name="_vfxIS">VFXInstanceStorage</param>
	/// <param name="_bm">BufferManager</param>
	void Execute(VFXInstanceStorage& _vfxIS, BufferManager& _bm);
	/// <summary>
	/// モジュールハンドル取得
	/// </summary>
	/// <typeparam name="T">ほしいモジュールの型</typeparam>
	/// <returns>ハンドル</returns>
	template<typename T>
	int GetModule()
	{
		auto it{ moduleMap.find(std::type_index(typeid(T))) };

		if (it == moduleMap.end())
		{
			return nullptr;
		}

		return static_cast<SparseSetStorageBase<T>*>(modules[it->second].get());
	}
private:
	std::vector<std::unique_ptr<Module>> modules;
	// モジュールと型の対応マップ
	std::unordered_map<std::type_index, size_t> moduleMap;
};