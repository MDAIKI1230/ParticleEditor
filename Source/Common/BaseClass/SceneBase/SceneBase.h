#pragma once


#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "SceneConstants.h"

#include "IWorld.h"

#include "SystemBase.h"
#include "StorageBase.h"

class SceneBase:public IWorld
{
public:
	SceneBase() = default;
	void Execute();
	virtual ~SceneBase();
protected:
	/// <summary>
	/// システムの追加(moveされる)
	/// </summary>
	/// <param name="system">入れたいシステム</param>
	void AddSystem(std::unique_ptr<SystemBase> system);
	/// <summary>
	/// ストレージの追加(moveされる)
	/// </summary>
	/// <param name="storage">入れたいストレージ</param>
	void AddStorage(std::unique_ptr<StorageBase> storage);
	void FadeIn();
	void FadeOut();
	virtual void Initialize() = 0;
	virtual void Update();
	virtual void Terminate() = 0;
protected:
	// シーンの状態
	SceneState state{ SceneState::FADEIN };
	// システム
	std::vector<std::unique_ptr<SystemBase>> systems;
};