#include "SceneManager.h"

SceneManager::SceneManager()
{

}

void SceneManager::Execute()
{
	currentScene->Execute();
}

void SceneManager::Draw()
{
	SceneManager::Draw();
}