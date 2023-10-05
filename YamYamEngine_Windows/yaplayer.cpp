#include "yaplayer.h"
#include "yaResources.h"
#include "yaPlayerScript.h"
#include "yaControllerScript.h"
#include "yaPlayerColorChangeScript.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"

namespace ya
{
	player::player()
	{
		SetTag(enums::TAG::Player);
	}
	player::~player()
	{
	}
	void player::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		AddComponent<MeshRenderer>();

		AddComponent<PlayerScript>();
		AddComponent<ControllerScript>();
		AddComponent<PlayerColorChangeScript>();

		GameObject::Initialize();
	}
	void player::Update()
	{
		GameObject::Update();
	}
	void player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void player::Render()
	{
		GameObject::Render();
	}
	void player::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);
	}
	void player::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void player::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
}