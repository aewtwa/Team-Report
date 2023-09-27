#include "yaPlayScene.h"
#include "yaResources.h"

#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaRigidbody.h"
#include "yaPlayerScript.h"
#include "..\\YamYamEngine_SOURCE\\yaCamera.h"
#include "..\\YamYamEngine_SOURCE\yaobject.h"
#include "yaControllerScript.h"
namespace ya
{
	PlayScene::PlayScene()
	{
	}


	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		{
			GameObject* object = new GameObject;
			Transform* tr = object->AddComponent<Transform>();
			tr->SetPosition(Vector3(0.5f, 0.2f, 0.0f));
			tr->SetScale(Vector3(0.5f, 0.5f, 1.0f));

			MeshRenderer* meshRenderer = object->AddComponent<MeshRenderer>();
			meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));

			object->AddComponent<PlayerScript>();
			object->AddComponent<ControllerScript>();
			object->AddComponent<Collider>();
			object->AddComponent<Rigidbody>();

			AddGameObject(object, LAYER::Monster);
			Camera::SetTarget(object);
			//object->AddComponent<PlayerScript2>();
	
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
		Camera::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}
}
