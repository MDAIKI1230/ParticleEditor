#pragma once


#include <vector>
#include <memory>

#include "SceneConstants.h"

#include "IWorld.h"

#include "SystemBase.h"
#include "StorageBase.h"
#include "ComponentStorageBase.h"

class SceneBase:public IWorld
{
public:
	SceneBase();
	void Execute();
	// 仮想デストラクタ
	virtual ~SceneBase() = default;
protected:
	/// <summary>
	/// システムの追加(moveされる)
	/// </summary>
	/// <param name="system">入れたいシステム</param>
	void AddSystem(std::unique_ptr<SystemBase> _system);
	/// <summary>
	/// ストレージの追加(moveされる)
	/// </summary>
	/// <param name="storage">入れたいストレージ</param>
	template<typename T>
	void AddStorage(std::unique_ptr<ComponentStorageBase<T>> _storage);
	void FadeIn();
	void FadeOut();
	virtual void Initialize() = 0;
	virtual void Update();
	virtual void Terminate() = 0;
protected:
	// シーンの状態
	SceneState state{ SceneState::INITIALIZE };
	// システム
	std::vector<std::unique_ptr<SystemBase>> systems;
};