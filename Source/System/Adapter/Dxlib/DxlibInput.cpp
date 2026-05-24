#include <DxLib.h>

#include "DxlibInput.h"

// 更新
void DxlibInput::Update()
{
	for (int i = 0; i < 256; i++)
	{
		pastKeyState[i] = currentKeyState[i];
	}
	GetHitKeyStateAll(currentKeyState);
}

// キーが押されたとき
bool DxlibInput::GetKeyPush(int keyCode)
{
	return (currentKeyState[keyCode] == 1) && (pastKeyState[keyCode] == 0);
}

// キーが話されたとき
bool DxlibInput::GetKeyRelease(int keyCode)
{
	return (currentKeyState[keyCode] == 0) && (pastKeyState[keyCode] == 1);
}

// キーが押されている間
bool DxlibInput::GetKeyPress(int keyCode)
{
	return (currentKeyState[keyCode] == 1);
}