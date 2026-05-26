#pragma once

#include "VFXConstants.h"

#include "../../System/AttributeLayout.h"
#include "Allocation.h"
#include "../Module/Module.h"

class Emitter
{
	// 使う属性種類リスト
	AttributeLayout attributes;

	// 使うモジュール群
	std::vector<Module*> module;

	// メモリ範囲
	Allocation allocation;
};