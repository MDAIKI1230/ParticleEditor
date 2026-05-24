#include "ServiceLocator.h"

#include "RendererComponent.h"
#include "RendererComponentStorage.h"

#include "TransformComponent.h"

#include "DebugScene.h"

// コンストラクタ
DebugScene::DebugScene()
{

}
// 初期化
void DebugScene::Initialize()
{
	/*SetCameraPositionAndTarget_UpVecY(Vector3{ 0,0,-100.0f }, Vector3{ 0,0,0 });

	RendererComponent renderer{ ServiceLocator::GetRenderer()->LoadModel(L"Res/Model/M_001_player_073_01.mv1") };
	
	GetStorage<RendererComponent>()->Add(0,renderer);

	TransformComponent trans{};

	GetStorage<TransformComponent>()->Add(0, trans);

	state = SceneState::UPDATE;*/
}
// 終了
void DebugScene::Terminate()
{

}