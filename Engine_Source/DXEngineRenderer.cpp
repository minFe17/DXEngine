#include "DXEngineRenderer.h"
#include "DXEngineResources.h"
#include "DXEngineShader.h"

namespace DXEngine::Renderer
{
	Camera* mainCamera = nullptr;

	Mesh* mesh = nullptr;
	Graphics::ConstantBuffer constantBuffers[(UINT)ECBType::Max] = {};

	ID3D11Buffer* constantBuffer = nullptr;

	ID3D11InputLayout* inputLayouts = nullptr;

	void LoadTriangleMesh()
	{
		mesh = new Mesh();

		std::vector<Graphics::Vertex> vertexes = {};
		std::vector<UINT> indices = {};

		vertexes.resize(3);
		vertexes[0].position = Vector3(0.0f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[1].position = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[2].position = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		mesh->CreateVertexBuffer(vertexes);
		mesh->CreateIndexBuffer(indices);
	}

	void LoadRectMesh()
	{
		mesh = new Mesh();

		std::vector<Graphics::Vertex> vertexes = {};
		std::vector<UINT> indices = {};

		vertexes.resize(4);
		vertexes[0].position = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].position = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].position = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[2].position = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].position = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);

		indices.push_back(0);
		indices.push_back(2);
		indices.push_back(3);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		mesh->CreateVertexBuffer(vertexes);
		mesh->CreateIndexBuffer(indices);
	}

	void LoadMeshes()
	{
		LoadTriangleMesh();
		LoadRectMesh();
	}

	void LoadShaders()
	{
		Resources::Load<Graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");
		Resources::Load<Graphics::Shader>(L"SpriteShader", L"..\\Shaders_SOURCE\\Sprite");
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