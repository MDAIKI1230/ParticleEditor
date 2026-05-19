#pragma once

class InputManager
{
public:
	InputManager() = default;
	void Update();
	// キーが押されたとき
	bool GetKeyPush(int keyCode);
	// キーが話されたとき
	bool GetKeyRelease(int keyCode);
	// キーが押されている間
	bool GetKeyPress(int keyCode);
private:
	char pastKeyState[256];
	char currentKeyState[256];
};