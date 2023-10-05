#include "yaTransform.h"
#include "yaGraphicsDevice_DX11.h"
#include "yaRenderer.h"
#include "yaCamera.h"

namespace ya
{

	Transform::Transform()
		: Component(COMPONENTTYPE::TRANSFORM)
		,mScale(math::Vector3::One)
		,mPosition(math::Vector3::Zero)
	{

	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render()
	{
	}

	void Transform::SetConstantBuffer(bool AffectCamera)
	{
		ConstantBuffer* cb = renderer::constantBuffers[(UINT)graphics::eCBType::Transform];

		Vector3 pos = mPosition;

		if (AffectCamera)
			pos = Camera::CalculatePosition(pos);
			

		renderer::TransformCB data = {};
		data.pos = pos * (Vector3(1.0f,1.0f,1.0f) / mScale);
		data.scale = mScale;
		cb->SetData(&data);

		cb->Bind(graphics::eShaderStage::VS);
	}
}