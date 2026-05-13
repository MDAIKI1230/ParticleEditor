#pragma once

#include "SceneConstants.h"
#include "SystemBase.h"

class SceneBase
{
public:
	SceneBase() = default;
	void Execute();
	void Draw();
	virtual ~SceneBase();
protected:
	void FadeIn();
	void FadeOut();
	virtual void Initialize() = 0;
	void Update();
	void Terminate();
protected:
	SceneState state{ SceneState::FADEIN };
};