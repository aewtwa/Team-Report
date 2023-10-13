#include "yaText.h"
#include "yaTextManager.h"
#include "yaCamera.h"
#include "yaGameObject.h"
#include "yaTransform.h"


namespace ya
{
	Text::Text() : Component(TEXT)
		, text(L"")
		, mPosition(Vector2::Zero)
		, mScale(Vector2::One)
		, mOffset(Vector2::Zero)
		, mColor(DirectX::Colors::White)
		, mbRender(false)
	{
		TextManager::AddText(this);
	}
	Text::~Text()
	{
	}
	void Text::Initialize()
	{
	}
	void Text::Update()
	{
		mPosition = GetOwner()->GetComponent<Transform>()->GetPosition() + mOffset;
		mPosition.x -= mScale.x / 2;
		mPosition.y += mScale.y / 2;
		mPosition *= 50;
		mPosition.y *= -1;
		mbRender = true;
	}
	void Text::LateUpdate()
	{
	}
	void Text::Render()
	{
	}
	void Text::SetColor(std::wstring name)
	{
		if (name == L"White")
			mColor = DirectX::Colors::White;
		else if (name == L"Black")
			mColor = DirectX::Colors::Black;
	}
}