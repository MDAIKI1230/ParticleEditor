#include "VFXSimulateSystem.h"

void VFXSimulateSystem::Update(IWorld* world)
{
	sp.Execute(&vfxIS, bm);
}