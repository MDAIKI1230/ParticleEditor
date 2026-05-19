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
	const ComponentStorage<T>* GetStorage();
};