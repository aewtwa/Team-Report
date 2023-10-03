#pragma once
#include "yaEnums.h"
#include "CommonInclude.h"
#include "YamYamEngine.h"
#include "yaMath.h"
#include "yaGraphicsDevice_DX11.h"

#include "yaMesh.h"
#include "yaShader.h"
#include "yaConstantBuffer.h"

using namespace ya::graphics;
using namespace ya::enums;
using namespace ya::math;

namespace ya::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Vector3 pos;
		int padd1;

		Vector3 scale;
		int padd2;

		Vector3 color;
		int padd3;
	};

	CBUFFER(ColliderCB, CBSLOT_COLLIDER)
	{
		Vector3 pos;
		int padd1;

		Vector3 scale;
		int padd2;

		Vector3 color;
		int padd3;
	};

	CBUFFER(ColorCB, CBSLOT_COLOR)
	{
		Vector4 col;
	};

	extern Mesh* triangleMesh;
	extern Mesh* lineMesh;
	extern Shader* triangleShader;
	extern Shader* lineShader;
	extern ConstantBuffer* constantBuffers[];

	// Initialize the renderer
	void Initialize();
	void Release();
}
