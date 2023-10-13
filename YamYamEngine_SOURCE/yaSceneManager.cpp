#include "yaSceneManager.h"

#include "yaResources.h"
#include "yaCamera.h"

#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};

	void SceneManager::Initialize()
	{
		//mActiveScene = new Scene();

		//{
		//	GameObject* object = new GameObject();
		//	Transform* tr = new Transform();
		//	tr->SetPosition(Vector3(-0.5f, -0.2f, 0.0f));
		//	object->AddComponent(tr);

		//	MeshRenderer* meshRenderer = new MeshRenderer();
		//	meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
		//	meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
		//	object->AddComponent(meshRenderer);

		//	mActiveScene->AddGameObject(object, LAYER::NONE);
		//}
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render()
	{
		mActiveScene->Render();
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	Scene* SceneManager::LoadScene(const std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		Camera::Clear();

		mActiveScene = iter->second;
		mActiveScene->Setting();
		return iter->second;
	}
}
