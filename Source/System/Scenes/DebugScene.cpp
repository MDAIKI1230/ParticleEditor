#include "ServiceLocator.h"

#include "RendererComponent.h"
#include "RendererComponentStorage.h"

#include "TransformComponent.h"

#include "VFXComponent.h"
#include "VFXComponentStorage.h"
#include "VFXSimulateSystem.h"
#include "VFXRenderingSystem.h"

#include "DebugScene.h"

// コンストラクタ
DebugScene::DebugScene()
{

}
// 初期化
void DebugScene::Initialize()
{
	Camera camera{ Vector3{0,0,-100},Vector3{0,0,0} };
	ServiceLocator::GetRenderer()->SetCamera(camera);

	RendererComponent renderer{ ServiceLocator::GetRenderer()->LoadModel(std::string{"Res/Model/M_001_player_073_01.mv1"}) };
	
	GetStorage<RendererComponent>()->Add(0,renderer);

	TransformComponent trans{};

	GetStorage<TransformComponent>()->Add(0, trans);

	state = SceneState::UPDATE;

	// VFXシミュレートシステム追加
	AddSystem(std::make_unique<VFXSimulateSystem>());
	// VFXレンダリングシステム追加
	AddSystem(std::make_unique<VFXRenderingSystem>());
	// レンダラーストレージ追加
	AddStorage<VFXComponent>(std::make_unique<VFXComponentStorage>());

	VFXComponent vfx{ VFXAsset{} };
	GetStorage<VFXComponent>()->Add(0, vfx);
}
// 終了
void DebugScene::Terminate()
{

}