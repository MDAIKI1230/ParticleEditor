#pragma once

#include "SceneConstants.h"

class SceneBase
{
public:
	SceneBase() = default;
	void Execute();
	void Draw();
	virtual ~SceneBase() = default;
protected:
	void FadeIn();
	void FadeOut();
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Terminate() = 0;
protected:
	SceneState state{ SceneState::FADEIN };
};