#pragma once

#include "../../System/AttributeLayout.h"
#include "Allocation.h"

class Emitter
{
public:
	// アロケーション取得
	Allocation& GetAllocation() { return allocation; }
private:
	// 使う属性種類リスト
	AttributeLayout attributes;

	// メモリ範囲
	Allocation allocation;
};