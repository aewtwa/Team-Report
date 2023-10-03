#include "yaMeshRenderer.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaResources.h"

namespace ya
{
	MeshRenderer::MeshRenderer()
		: Component(COMPONENTTYPE::MESH)
		, mColor(Vector4(10, 123, 223, 1))
	{
	}

	MeshRenderer::~MeshRenderer()
	{
	}

	void MeshRenderer::Initialize()
	{
		SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
		SetShader(Resources::Find<Shader>(L"TriangleShader"));
	}

	void MeshRenderer::Update()
	{
		//fhwlr

		//
	}

	void MeshRenderer::LateUpdate()
	{

	}

	void MeshRenderer::Render()
	{
		GetOwner()->GetComponent<Transform>()->SetConstantBuffer();

		mShader->Update();
		mMesh->Render();
	}
}

