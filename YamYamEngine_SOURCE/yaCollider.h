#pragma once
#include"yaComponent.h"
#include "yaApplication.h"

extern ya::Application app;

namespace ya
{
	class Collider : public Component
	{
	public:
		Collider();
		virtual ~Collider();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other);
		void OnCollisionStay(Collider* other);
		void OnCollisionExit(Collider* other);

		bool GetCollision() { return isCollision; }

		void SetPos(math::Vector3 pos) { mPos = pos; }
		void SetOffset(math::Vector3 offset) { mOffset = offset; }
		void SetSize(math::Vector2 size) { mSize = size; }
		math::Vector3& GetPos()
		{
			return mPos;
		}
		math::Vector3& GetOffset() { return mOffset; }
		math::Vector2& GetSize() { return mSize; }

	private:
		bool isCollision;

		math::Vector3 mPos;
		math::Vector3 mOffset;
		math::Vector2 mSize;

	};
}