#pragma once

#include "SystemBase.h"

class RenderingSystem:public SystemBase
{
public:
	void Update(const IWorld* world) override;
};