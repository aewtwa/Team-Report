#include "yaTurretScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaCamera.h"
#include "yaInput.h"
#include "yaobject.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaBullet.h"
#include "yaMonster.h"

namespace ya
{
	TurretScript::TurretScript() :
		directions()
	{
		for (int i = 0; i < 12; i++)
		{
			directions[i] = 30.0f * i;
		}
	}
	TurretScript::~TurretScript()
	{
	}
	void TurretScript::Initialize()
	{
	}
	void TurretScript::Update()
	{
		object::Instantiate<ya::Monster>(LAYER::Monster, Vector3(10, 0, 0));
	}
	void TurretScript::LateUpdate()
	{
	}
	void TurretScript::Render()
	{
	}
}