#pragma once

#include "../Storage/VFXInstanceStorage.h"
#include "BufferManager.h"

class RenderingPipeline
{
public:
	void Draw(VFXInstanceStorage& _vfxIS, BufferManager& _bm);
};