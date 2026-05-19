#pragma once

#include "IWorld.h"

#include "SceneConstants.h"

class SceneBase:public IWorld
{
public:
	SceneBase() = default;
	void Execute();
	virtual ~SceneBase();
protected:
	void FadeIn();
	void FadeOut();
	virtual void Initialize() = 0;
	virtual void Update();
	virtual void Terminate() = 0;
protected:
	// シーンの状態
	SceneState state{ SceneState::FADEIN };
};