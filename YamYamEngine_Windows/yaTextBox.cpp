#include "yaTextBox.h"
#include "yaTransform.h"
#include "yaText.h"

namespace ya
{
	TextBox::TextBox()
		: mText(nullptr)
	{
		SetTag(TAG::Ui);
	}
	TextBox::~TextBox()
	{
	}
	void TextBox::Initialize()
	{
		AddComponent<Transform>();
		mText = AddComponent<Text>();

		GameObject::Initialize();
	}
	void TextBox::Update()
	{
		GameObject::Update();
	}
	void TextBox::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void TextBox::Render()
	{
		GameObject::Render();
	}
}