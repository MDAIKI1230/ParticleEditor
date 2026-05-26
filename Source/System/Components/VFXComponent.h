#pragma once

#include "Asset/VFXAsset.h"

struct VFXComponent
{
public:
	VFXComponent(VFXAsset _vfxAsset) :
		vfxAsset{ _vfxAsset }
	{
	}

	// 初期化完了
	void CompleteInit() { isInit = true; }
	// ハンドルセット
	void SetHandle(int _handle) { vfxHandle = _handle; }
	// 初期化フラグ取得
	bool GetIsInit() { return isInit; }
	// アセット取得
	VFXAsset& GetAsset() { return vfxAsset; }
private:
	// インスタンスハンドル
	int vfxHandle;
	// アセット
	VFXAsset vfxAsset;
	// 初期化フラグ
	bool isInit{ false };
};