#pragma once
#include "yaScene.h"
#include "yaGameObject.h"
#include "yaSceneManager.h"
#include "yaTransform.h"

namespace ya::object
{
	template <typename T>
	static __forceinline T* Instantiate(enums::LAYER type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObject, type);

		return gameObject;
	}

	template <typename T>
	static __forceinline T* Instantiate(LAYER type, math::Vector3 position)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObject, gameObject);
		gameObject->Initialize();
		gameObject->GetComponent<Transform>()->SetPosition(position);

		return gameObject;
	}
}