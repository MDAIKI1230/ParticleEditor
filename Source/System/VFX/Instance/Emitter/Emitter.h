#pragma once

#include <vector>

#include "VFXConstants.h"

#include "Allocation.h"
#include "../Module/Module.h"

class Emitter
{
	// 使う属性種類リスト
	std::vector<AttributeType> attributes;

	// 使うモジュール群
	std::vector<Module*> module;

	// メモリ範囲
	Allocation allocation;
};