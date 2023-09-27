#include "yaRenderer.h"
#include "yaApplication.h"
#include "yaResources.h"

extern ya::Application application;



namespace ya::renderer
{

	D3D11_INPUT_ELEMENT_DESC InputLayouts[2];
	Mesh* triangleMesh = nullptr;
	Mesh* lineMesh = nullptr;
	Shader* triangleShader = nullptr;
	Shader* lineShader = nullptr;
	ConstantBuffer* constantBuffers[(UINT)graphics::eCBType::End];

	void SetUpStates()
	{

	}

	void LoadBuffer()
	{
		{
			std::vector<Vertex> vertexes;
			vertexes.resize(4);
			vertexes[0].pos = Vector3(-0.5f, -0.5f, 0.0f);			//0
			vertexes[0].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			vertexes[1].pos = Vector3(-0.5f, +0.5f, 0.0f);			// 1
			vertexes[1].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			vertexes[2].pos = Vector3(+0.5f, -0.5f, 0.0f);			// 2
			vertexes[2].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			vertexes[3].pos = Vector3(+0.5f, +0.5f, 0.0f);			// 3
			vertexes[3].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			std::vector<UINT> indexes;
			indexes.push_back(0);
			indexes.push_back(1);
			indexes.push_back(2);

			indexes.push_back(2);
			indexes.push_back(1);
			indexes.push_back(3);

			// Triangle Vertex Buffer
			triangleMesh->CreateVertexBuffer(vertexes.data(), 4);
			triangleMesh->CreateIndexBuffer(indexes.data(), indexes.size());
			Resources::Insert(L"TriangleMesh", triangleMesh);
		}

		{
			std::vector<Vertex> vertexes;
			vertexes.resize(4);
			vertexes[0].pos = Vector3(-0.5f, -0.5f, 0.0f);			//0
			vertexes[0].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			vertexes[1].pos = Vector3(-0.5f, +0.5f, 0.0f);			// 1
			vertexes[1].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			vertexes[2].pos = Vector3(+0.5f, -0.5f, 0.0f);			// 2
			vertexes[2].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			vertexes[3].pos = Vector3(+0.5f, +0.5f, 0.0f);			// 3
			vertexes[3].color = Vector4(0.8f, 0.8f, 0.8f, 1.0f);

			std::vector<UINT> indexes;
			indexes.push_back(0);
			indexes.push_back(1);

			indexes.push_back(1);
			indexes.push_back(3);

			indexes.push_back(3);
			indexes.push_back(2);

			indexes.push_back(2);
			indexes.push_back(0);

			// Triangle Vertex Buffer
			lineMesh->CreateVertexBuffer(vertexes.data(), 4);
			lineMesh->CreateIndexBuffer(indexes.data(), indexes.size());
			Resources::Insert(L"LineMesh", lineMesh);
		}

		constantBuffers[(UINT)graphics::eCBType::Transform] = new ConstantBuffer();
		constantBuffers[(UINT)graphics::eCBType::Transform]->Create(sizeof(TransformCB));

		constantBuffers[(UINT)graphics::eCBType::Collider] = new ConstantBuffer();
		constantBuffers[(UINT)graphics::eCBType::Collider]->Create(sizeof(ColliderCB));
		//mesh->CreateConstantBuffer(nullptr, sizeof(Vector4));
	}

	void LoadShader()
	{
		triangleShader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "VS_Test");
		triangleShader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "PS_Test");

		lineShader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "VS_Test");
		lineShader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "PS_Test");
		lineShader->SetTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

		Resources::Insert(L"TriangleShader", triangleShader);
		Resources::Insert(L"LineShader", lineShader);
		//GetDevice()->CreateShader(eShaderStage::NONE);
		//GetDevice()->CreateVertexShader();`
		// Input layout 정점 구조 정보
		InputLayouts[0].AlignedByteOffset = 0;
		InputLayouts[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		InputLayouts[0].InputSlot = 0;
		InputLayouts[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		InputLayouts[0].SemanticName = "POSITION";
		InputLayouts[0].SemanticIndex = 0;

		InputLayouts[1].AlignedByteOffset = 12;
		InputLayouts[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		InputLayouts[1].InputSlot = 0;
		InputLayouts[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		InputLayouts[1].SemanticName = "COLOR";
		InputLayouts[1].SemanticIndex = 0;

		GetDevice()->CreateInputLayout(InputLayouts, 2,
			triangleShader->GetVSCode()->GetBufferPointer()
			, triangleShader->GetVSCode()->GetBufferSize()
			, triangleShader->GetInputLayoutAddressOf());
	}

	void Initialize()
	{
		triangleMesh = new Mesh();
		lineMesh = new Mesh();
		triangleShader = new Shader();
		lineShader = new Shader();

		LoadShader();
		SetUpStates();
		LoadBuffer();
	}

	void Release()
	{
		delete triangleMesh;
		delete lineMesh;
		delete triangleShader;
		delete lineShader;

		delete constantBuffers[(UINT)graphics::eCBType::Transform];
		//triangleVertexBuffer->Release();
		//errorBlob->Release();
		//triangleVSBlob->Release();
		//triangleVSShader->Release();
		//trianglePSBlob->Release();
		//trianglePSShader->Release();
		//triangleLayout->Release();
	}
}