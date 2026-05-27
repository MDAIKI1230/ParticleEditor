#pragma once

#include "Asset/VFXAsset.h"

struct VFXComponent
{
public:
	VFXComponent(VFXAsset _vfxAsset);

	// VFXPlay関数
	void Play() { isPlay = true; }
	// ハンドルセット
	void SetHandle(int _handle) { vfxHandle = _handle; }
	// 初期化フラグ取得
	bool GetIsPlay() { return isPlay; }
	// アセット取得
	VFXAsset& GetAsset() { return vfxAsset; }
private:
	// インスタンスハンドル
	int vfxHandle;
	// アセット
	VFXAsset vfxAsset;
	// 初期化フラグ
	bool isPlay{ false };
};