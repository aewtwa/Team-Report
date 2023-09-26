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

		if (AffectCamera)
			mPosition = Camera::CalculatePosition(mPosition);

		renderer::TransformCB data = {};
		data.pos = mPosition;
		data.scale = mScale;
		cb->SetData(&data);

		cb->Bind(graphics::eShaderStage::VS);
	}
}