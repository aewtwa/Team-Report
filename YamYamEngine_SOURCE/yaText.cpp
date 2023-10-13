#include "yaText.h"
#include "yaTextManager.h"
#include "yaGameObject.h"
#include "yaTransform.h"


namespace ya
{
	Text::Text() : Component(TEXT)
		, mPosition(Vector2::Zero)
		, mScale(Vector2::One)
		, mOffset(Vector2::Zero)
		, mColor(DirectX::Colors::White)
		, render(false)
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
		render = true;
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