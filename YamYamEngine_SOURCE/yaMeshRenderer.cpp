#include "yaMeshRenderer.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaGraphicsDevice_DX11.h"
#include "yaRenderer.h"

namespace ya
{
	MeshRenderer::MeshRenderer()
		: Component(COMPONENTTYPE::MESH)
		, mColor(Vector4(0.f, 0.f, 0.f, 100))
		, affectCamera(true)
	{
		SetMesh(Resources::Find<Mesh>(L"SquareMesh"));
		SetShader(Resources::Find<Shader>(L"SquareShader"));
	}

	MeshRenderer::~MeshRenderer()
	{
	}

	void MeshRenderer::Initialize()
	{
	}

	void MeshRenderer::Update()
	{
	}

	void MeshRenderer::LateUpdate()
	{
	}

	void MeshRenderer::Render()
	{
		GetOwner()->GetComponent<Transform>()->SetConstantBuffer(affectCamera);

		ConstantBuffer* cb = renderer::constantBuffers[(UINT)graphics::eCBType::Color];

		renderer::ColorCB data = {};
		data.col.x = mColor.x / 255;
		data.col.y = mColor.y / 255;
		data.col.z = mColor.z / 255;
		data.col.w = mColor.w / 100;
		cb->SetData(&data);

		cb->Bind(graphics::eShaderStage::PS);

		mShader->Update();
		mMesh->Render();
	}
}

