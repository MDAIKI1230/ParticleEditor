#pragma once

#include <memory>

#include "SceneBase.h"

class SceneManager
{
public:
	SceneManager();
	void Update();
private:
	std::unique_ptr<SceneBase> currentScene;
	std::unique_ptr<SceneBase> nextScene;
};