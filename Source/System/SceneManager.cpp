#include "SceneManager.h"

SceneManager::SceneManager()
{

}

void SceneManager::Execute()
{
	currentScene->Execute();
}