#pragma once

#include "IWorld.h"

class SystemBase
{
public:
	virtual void Update(const IWorld* world) = 0;
	// 優先度取得
	int GetPriority() { return priority; }
protected:
	// 優先度
	int priority{ 0 };
};