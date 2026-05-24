#pragma once

#include "IInput.h"

class DxlibInput:public IInput
{
public:
	// 更新
	void Update();
	// キーが押されたとき
	bool GetKeyPush(int keyCode);
	// キーが話されたとき
	bool GetKeyRelease(int keyCode);
	// キーが押されている間
	bool GetKeyPress(int keyCode);
};