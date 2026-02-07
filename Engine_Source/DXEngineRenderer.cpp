#include "DXEngineRenderer.h"
#include "DXEngineResources.h"
#include "DXEngineShader.h"

namespace DXEngine::Renderer
{
	Camera* mainCamera = nullptr;

	std::vector<Graphics::Vertex> vertexes = {};
	std::vector<UINT> indices;

	Mesh* mesh = nullptr;
	Graphics::ConstantBuffer constantBuffers[(UINT)ECBType::Max] = {};

	ID3D11Buffer* constantBuffer = nullptr;

	ID3D11InputLayout* inputLayouts = nullptr;

	void LoadTriangleMesh()
	{
		mesh = new Mesh();

		Renderer::vertexes.resize(3);

		Renderer::vertexes[0].position = Vector3(0.f, 0.5f, 0.0f);
		Renderer::vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		Renderer::vertexes[1].position = Vector3(0.5f, -0.5f, 0.0f);
		Renderer::vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		Renderer::vertexes[2].position = Vector3(-0.5f, -0.5f, 0.0f);
		Renderer::vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//indices.push_back(0);
		//indices.push_back(2);
		//indices.push_back(3);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		mesh->CreateVertexBuffer(vertexes);
		mesh->CreateIndexBuffer(indices);
	}

	void LoadMeshes()
	{
		LoadTriangleMesh();
	}

	void LoadShaders()
	{
		Resources::Load<Graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");
	}

	void LoadConstantBuffers()
	{
		constantBuffers[(UINT)ECBType::Transform].Create(ECBType::Transform, sizeof(Vector4));
	}

	void Init()
	{
		LoadMeshes();
		LoadShaders();
		LoadConstantBuffers();
	}

	void Release()
	{
		inputLayouts->Release();
		delete mesh;
	}
}