#include "SceneManager.h"

SceneManager::SceneManager()
{

}

void SceneManager::Update()
{
	currentScene->Execute();
}