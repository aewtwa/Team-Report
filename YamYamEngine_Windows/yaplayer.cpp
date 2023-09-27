#include "yaplayer.h"
#include "..\YamYamEngine_SOURCE\yaResources.h"
#include "yaPlayerScript.h"
#include "yaControllerScript.h"
#include "..\YamYamEngine_SOURCE\yaTransform.h"
#include "..\YamYamEngine_SOURCE\yaCollider.h"
#include "..\YamYamEngine_SOURCE\yaMeshRenderer.h"

namespace ya
{
	player::player()
	{
	}
	player::~player()
	{
	}
	void player::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		MeshRenderer* meshRenderer = AddComponent<MeshRenderer>();
		meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
		meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));

		AddComponent<PlayerScript>();
		AddComponent<ControllerScript>();

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
	}
	void player::OnCollisionStay(Collider* other)
	{
	}
	void player::OnCollisionExit(Collider* other)
	{
	}
}