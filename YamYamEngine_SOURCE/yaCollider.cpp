#include "yaCollider.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaApplication.h"
#include <wingdi.h>

extern ya::Application application;

namespace ya
{
	Collider::Collider()
		: Component(COMPONENTTYPE::COLLIDER)
		, mPos(math::Vector2::Zero)
		, mOffset(math::Vector2::Zero)
		, mSize(math::Vector2::One * 10)
		, isCollision(false)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
		mPos = GetOwner()->GetComponent<Transform>()->GetPosition() + mOffset;
	}
	void Collider::Update()
	{
		mPos = GetOwner()->GetComponent<Transform>()->GetPosition() + mOffset;
		mPos = Camera::CalculatePositionApi(mPos);
		Vector3 pos = GetOwner()->GetComponent<Transform>()->GetPosition() + mOffset;

		//pos.x *= 400.0f;
		//pos.y *= 225.0f;
		//mPos.x += pos.x;
		//mPos.y -= pos.y;

	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render()
	{
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HPEN pen;
		if (GetCollision())
			pen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
		else
			pen = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));

		HBRUSH oldB = (HBRUSH)SelectObject(application.GetDC(), brush);
		HPEN oldP = (HPEN)SelectObject(application.GetDC(), pen);

		Rectangle(application.GetDC()
			, mPos.x - mSize.x / 2
			, mPos.y + mSize.y / 2
			, mPos.x + mSize.x / 2
			, mPos.y - mSize.y / 2);

		SelectObject(application.GetDC(), oldB);
		SelectObject(application.GetDC(), oldP);

		DeleteObject(brush);
		DeleteObject(pen);

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
}