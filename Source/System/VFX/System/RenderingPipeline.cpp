#include "ServiceLocator.h"

#include "RenderingPipeline.h"

void RenderingPipeline::Draw(VFXInstanceStorage* _vfxIS, BufferManager& _bm)
{
	std::vector<VFXInstance>* dense{ _vfxIS->GetDense() };
	for (auto& vfx : *dense)
	{
		for (auto& emitter : vfx.GetEmitters())
		{
			// アロケーション取得
			Allocation allocation{ emitter.GetAllocation() };

			// 位置のバッファ
			AttributeBuffer<Vector3> positions{ _bm.GetBuffer<Vector3>(AttributeType::POSITION) };
			// データ取得
			std::vector<Vector3>* dense{ positions.GetCPUData()->GetDense() };

			// 描画
			for (Vector3 pos : *dense)
			{
				
			}
		}
	}
}