#include "SimulatePipeline.h"

/// <summary>
/// モジュール更新
/// </summary>
/// <param name="_vfxIS">VFXInstanceStorage</param>
void SimulatePipeline::Execute(VFXInstanceStorage* _vfxIS, BufferManager& _bm)
{
	std::vector<VFXInstance>* dense{ _vfxIS->GetDense() };
	for (auto& vfx : *dense)
	{
		for (auto module : vfx.GetModules())
		{
			for (auto& emitter : vfx.GetEmitters())
				module->Update(_bm, emitter.GetAllocation());
		}
	}
}