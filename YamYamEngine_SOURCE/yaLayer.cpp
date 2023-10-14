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
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i]->GetState() == GameObject::eState::Paused)
				continue;

			mGameObjects[i]->Update();
		}

		/*for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject->GetState() == GameObject::eState::Paused)
				continue;

			gameObject->Update();
		}*/
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject->GetState() == GameObject::eState::Paused)
				continue;

			gameObject->LateUpdate();
		}
	}

	void Layer::Render()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject->GetState() == GameObject::eState::Paused)
				continue;

			gameObject->Render();
		}
	}

	void Layer::Destroy()
	{
		for (std::vector<GameObject*>::iterator iter = mGameObjects.begin(); iter != mGameObjects.end();)
		{
			if ((*iter)->GetState() == GameObject::eState::Dead)
			{
				delete (*iter);
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