#pragma once

#include "InputManager.h"
#include "TimeManager.h"

class ServiceLocator
{
public:
	// 取得用関数
	// static JobSystem* GetJobSystem() { return jobSystem; }
	static InputManager* GetInputManager() { return inputManager; }
	static TimeManager* GetTimeManager() { return timeManager; }

	// セット用関数
	// static void SetJobSystem(JobSystem* _jobSystem) { jobSystem = _jobSystem; }
	static void SetInputManager(InputManager* _inputManager) { inputManager = _inputManager; }
	static void SetTimeManager(TimeManager* _timeManager) { timeManager = _timeManager; }
private:
	// static JobSystem* jobSystem;
	static InputManager* inputManager;
	static TimeManager* timeManager;
};