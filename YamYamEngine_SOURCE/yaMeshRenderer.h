#pragma once
#include "yaComponent.h"
#include "yaMesh.h"
#include "yaShader.h"


namespace ya
{
	using namespace graphics;

	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();
		
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetMesh(Mesh* mesh) { mMesh = mesh; }
		void SetShader(Shader* shader) { mShader = shader; }

		void SetColor(Vector4 colalpha) { mColor = colalpha; }
		void SetColor(Vector3 col) { mColor.x = col.x; mColor.y = col.y; mColor.z = col.z; }

	private:
		Mesh* mMesh;
		Shader* mShader;
		Vector4 mColor;
	};
}
