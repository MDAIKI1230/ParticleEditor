#include "Instance/Module/TestModule.h"

#include "SimulatePipeline.h"

SimulatePipeline::SimulatePipeline()
{
	modules.push_back(std::make_unique<TestModule>());
	moduleMap[typeid(TestModule)] = modules.size() - 1;
}

/// <summary>
/// モジュール更新
/// </summary>
/// <param name="_vfxIS">VFXInstanceStorage</param>
void SimulatePipeline::Execute(VFXInstanceStorage& _vfxIS, BufferManager& _bm)
{
	std::vector<VFXInstance>* dense{ _vfxIS.GetDense() };
	for (auto& vfx : *dense)
	{
		for (auto moduleHandle : vfx.GetModules())
		{
			for (auto& emitter : vfx.GetEmitters())
			{
				modules[moduleHandle]->Update(_bm, emitter.GetAllocation());
			}
		}
	}
}