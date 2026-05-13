#include <DxLib.h>
#include "InputManager.h"

void InputManager::Update()
{
	for (int i = 0; i < 256; i++)
	{
		pastKeyState[i] = currentKeyState[i];
	}
	GetHitKeyStateAll(currentKeyState);
}

bool InputManager::GetKeyPush(int keyCode)
{
	return (currentKeyState[keyCode] == 1) && (pastKeyState[keyCode] == 0);
}

bool InputManager::GetKeyRelease(int keyCode)
{
	return (currentKeyState[keyCode] == 0) && (pastKeyState[keyCode] == 1);
}

bool InputManager::GetKeyPress(int keyCode)
{
	return (currentKeyState[keyCode] == 1);
}