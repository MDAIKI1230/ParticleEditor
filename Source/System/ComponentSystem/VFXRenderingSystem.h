#pragma once

#include "UpdateSystem.h"

class VFXRenderingSystem :public UpdateSystem
{
	void Update(IWorld* world) override;
};