#pragma once

#include <memory>

#include "Scenes/SceneBase.h"

class SceneManager
{
public:
	SceneManager();
	void Execute();
private:
	std::unique_ptr<SceneBase> currentScene;
	std::unique_ptr<SceneBase> nextScene;
};