#include "yaLayer.h"


namespace ya
{
	Layer::Layer()
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			delete gameObject;
			gameObject = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->LateUpdate();
		}
	}

	void Layer::Render()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Render();
		}
	}

	void Layer::Destroy()
	{
		for (std::vector<GameObject*>::iterator iter = mGameObjects.begin(); iter != mGameObjects.end();)
		{
			if ((*iter)->GetState() == GameObject::eState::Dead)
			{
				iter = mGameObjects.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
		gameObject->Initialize();
	}
}