#pragma once

#include "SystemBase.h"

class RenderingSystem:public SystemBase
{
public:
	void Update(IWorld* world) override;
};