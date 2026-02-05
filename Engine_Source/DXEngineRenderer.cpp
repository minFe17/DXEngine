#include "DXEngineRenderer.h"
#include "DXEngineResources.h"
#include "DXEngineShader.h"

namespace DXEngine::Renderer
{
	Camera* mainCamera = nullptr;

	Vertex vertexes[3] = {};
	std::vector<UINT> indices;

	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11Buffer* indexBuffer = nullptr;
	ID3D11Buffer* constantBuffer = nullptr;

	ID3D11InputLayout* inputLayouts = nullptr;

	void LoadTriangleMesh()
	{
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
	}

	void LoadMeshes()
	{
		LoadTriangleMesh();
	}

	void LoadShaders()
	{
		Resources::Load<Graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");
	}

	void Init()
	{
		LoadMeshes();
		LoadShaders();
	}

	void Release()
	{
		vertexBuffer->Release();
		inputLayouts->Release();
		indexBuffer->Release();
		constantBuffer->Release();
	}
}