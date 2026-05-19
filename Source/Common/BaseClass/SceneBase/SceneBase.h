#pragma once

#include <memory>

#include "IWorld.h"

#include "SceneConstants.h"
#include "SystemBase.h"
#include "StorageBase.h"

class SceneBase:public IWorld
{
public:
	SceneBase() = default;
	void Execute();
	virtual ~SceneBase();
protected:
	void AddSystem(std::unique_ptr<SystemBase> system);
	void AddStorage(std::unique_ptr<StorageBase> storage);
	void FadeIn();
	void FadeOut();
	virtual void Initialize() = 0;
	virtual void Update();
	virtual void Terminate() = 0;
protected:
	// シーンの状態
	SceneState state{ SceneState::FADEIN };
};