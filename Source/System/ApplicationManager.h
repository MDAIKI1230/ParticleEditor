#pragma once

#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"

class ApplicationManager
{
public:
	ApplicationManager();
	int ApplicationMain();
private:
	std::unique_ptr<InputManager> inputManager;
	std::unique_ptr<SceneManager> sceneManager;
	std::unique_ptr<TimeManager> timeManager;
};