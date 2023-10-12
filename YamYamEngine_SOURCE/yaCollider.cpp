#include "yaCollider.h"
#include "yaResources.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaRenderer.h"
#include "yaColliderManager.h"

namespace ya
{
	Collider::Collider()
		: Component(COMPONENTTYPE::COLLIDER)
		, mPos(math::Vector2::Zero)
		, mOffset(math::Vector2::Zero)
		, mSize(math::Vector2::One)
		, isCollision(false)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
		mPos = GetOwner()->GetComponent<Transform>()->GetPosition() + mOffset;

		mMesh = Resources::Find<Mesh>(L"LineMesh");
		mShader = Resources::Find<graphics::Shader>(L"LineShader");
	}
	void Collider::Update()
	{
		mPos = GetOwner()->GetComponent<Transform>()->GetPosition() + mOffset;
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render()
	{
		if(ColliderManager::GetRender())
		{
			ConstantBuffer* cb = renderer::constantBuffers[(UINT)graphics::eCBType::Transform];

			renderer::TransformCB data = {};
			data.pos = mPos;
			data.scale = (Vector3)mSize;
			cb->SetData(&data);

			cb->Bind(graphics::eShaderStage::VS);

			mShader->Update();
			mMesh->Render();
		}
	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		GetOwner()->OnCollisionEnter(other);
		isCollision = true;
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionStay(other);
	}
	void Collider::OnCollisionExit(Collider* other)
	{
		GetOwner()->OnCollisionExit(other);
		isCollision = false;
	}
	void Collider::OnClick()
	{
		GetOwner()->OnClick();
	}
}