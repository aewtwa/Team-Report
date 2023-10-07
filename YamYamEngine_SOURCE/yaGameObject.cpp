#include "yaGameObject.h"


namespace ya
{
	GameObject::GameObject()
		: mState(eState::Active)
		, mTag(enums::TAG::None)
	{
		mComponents.resize(COMPONENTTYPE::END);
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr || !comp->GetActivate())
				continue;

			comp->Initialize();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr || !script->GetActivate())
				continue;

			script->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr || !comp->GetActivate())
				continue;

			comp->Update();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr || !script->GetActivate())
				continue;

			script->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr || !comp->GetActivate())
				continue;

			comp->LateUpdate();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr || !script->GetActivate())
				continue;

			script->LateUpdate();
		}
	}

	void GameObject::Render()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr || !comp->GetActivate())
				continue;

			comp->Render();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr || !script->GetActivate())
				continue;

			script->Render();
		}
	}
	void GameObject::OnCollisionEnter(Collider* other)
	{
		for (Script* script : mScripts)
		{
			if (script == nullptr || !script->GetActivate())
				continue;

			script->OnCollisionEnter(other);
		}
	}
	void GameObject::OnCollisionStay(Collider* other)
	{
		for (Script* script : mScripts)
		{
			if (script == nullptr || !script->GetActivate())
				continue;

			script->OnCollisionStay(other);
		}
	}
	void GameObject::OnCollisionExit(Collider* other)
	{
		for (Script* script : mScripts)
		{
			if (script == nullptr || !script->GetActivate())
				continue;

			script->OnCollisionExit(other);
		}
	}
}
