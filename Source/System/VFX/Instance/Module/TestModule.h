#pragma once

#include "Module.h"

#include "MDMath.h"

class TestModule:public Module
{
public:
	/// <summary>
	/// モジュール更新
	/// </summary>
	/// <param name="_bm">バッファマネージャー</param>
	/// <param name="_allocation">アロケーション</param>
	void Update(BufferManager& _bm, Allocation& _allocation) override
	{
		// バッファ取得
		AttributeBuffer<Vector3>* postionBuffer{ _bm.GetBuffer<Vector3>(AttributeType::POSITION) };
		AttributeBuffer<Vector3>* velocityBuffer{ _bm.GetBuffer<Vector3>(AttributeType::VELOCITY) };

		// CPUデータ取得
		auto* positions{ postionBuffer->GetCPUData() };
		auto* velocities{ velocityBuffer->GetCPUData() };

		// 終了地点
		size_t end{ _allocation.start + _allocation.count };

		// 範囲内を更新
		for (size_t i{ _allocation.start }; i < end; i++)
		{
			*positions->Get(i) += *velocities->Get(i);
		}
	}
private:

};