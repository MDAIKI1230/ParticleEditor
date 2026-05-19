#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "SceneConstants.h"
#include "SystemBase.h"
#include "StorageBase.h"

class SceneBase
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
	// システム
	std::vector<std::unique_ptr<SystemBase>> systems;
	// ストレージ
	std::vector < std::unique_ptr<StorageBase>> storages;
	// ストレージと型の対応マップ
	std::unordered_map<std::type_index, size_t> storageMap;
};