#include "yaWall.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	Wall::Wall()
		: isVertical(false)
	{
		SetTag(TAG::Wall);
	}
	Wall::~Wall()
	{
	}
	void Wall::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		AddComponent<MeshRenderer>();

		GameObject::Initialize();
	}
	void Wall::Update()
	{
		GameObject::Update();
	}
	void Wall::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Wall::Render()
	{
		GameObject::Render();
	}
	void Wall::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::Player)
		{
			Vector3 MyPos = GetComponent<Transform>()->GetPosition();
			Vector3 otherPos = other->GetOwner()->GetComponent<Transform>()->GetPosition();

			float x = MyPos.x - otherPos.x;
			float y = MyPos.y - otherPos.y;

			if (isVertical)
			{
				if (x > 0)
				{
					//right
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x - (abs(x) * 0.1f), otherPos.y, otherPos.z));
				}
				else
				{
					//left
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x + (abs(x) * 0.1f), otherPos.y, otherPos.z));
				}
			}
			else
			{
				if (y > 0)
				{
					//top
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x, otherPos.y - (abs(y) * 0.1f), otherPos.z));
				}
				else
				{
					//bottom
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x, otherPos.y + (abs(y) * 0.1f), otherPos.z));
				}
			}
		}
	}
	void Wall::OnCollisionStay(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::Player)
		{
			Vector3 MyPos = GetComponent<Transform>()->GetPosition();
			Vector3 otherPos = other->GetOwner()->GetComponent<Transform>()->GetPosition();

			float x = MyPos.x - otherPos.x;
			float y = MyPos.y - otherPos.y;

			if (abs(x) > abs(y))
			{
				if (x > 0)
				{
					//right
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x - (abs(x) * 0.1f), otherPos.y, otherPos.z));
				}
				else
				{
					//left
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x + (abs(x) * 0.1f), otherPos.y, otherPos.z));
				}
			}
			else
			{
				if (y > 0)
				{
					//top
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x, otherPos.y - (abs(x) * 0.1f), otherPos.z));
				}
				else
				{
					//bottom
					other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x, otherPos.y + (abs(x) * 0.1f), otherPos.z));
				}
			}
		}
	}
	void Wall::OnCollisionExit(Collider* other)
	{
	}
}