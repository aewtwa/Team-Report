#include "yaHPUI.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	HPUI::HPUI()
	{
	}
	
	HPUI::~HPUI()
	{
	}
	
	void HPUI::Initialize()
	{
		UIObject::Initialize();

		MeshRenderer* mr = GetComponent<MeshRenderer>();
		mr->SetColor(math::Vector3(255, 0, 0));
		mr->SetAffectCamera(false);
	}
	
	void HPUI::Update()
	{
		UIObject::Update();
	}
	
	void HPUI::LateUpdate()
	{
		UIObject::LateUpdate();
	}
	
	void HPUI::Render()
	{
		UIObject::Render();
	}
}
