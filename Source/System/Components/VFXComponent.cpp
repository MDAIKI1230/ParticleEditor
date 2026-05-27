#include "ServiceLocator.h"

#include "VFXComponent.h"

VFXComponent::VFXComponent(VFXAsset _vfxAsset) :
	vfxAsset{ _vfxAsset },
	vfxHandle{ ServiceLocator::GetVFXWorld()->CreateInstance(_vfxAsset) }
{
}