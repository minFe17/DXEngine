#pragma once
#include "DXEngineResource.h"
#include "DXEngineVertexBuffer.h"
#include "DXEngineIndexBuffer.h"

namespace DXEngine
{
	class Mesh : public Resource
	{
	public:
		struct Data
		{
			Data();
			~Data();

			D3D11_PRIMITIVE_TOPOLOGY topology;
			std::vector<Graphics::Vertex> vertices;
			std::vector<UINT> indices;
		};

		Mesh();
		~Mesh();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;


		bool CreateVertexBuffer(const std::vector<Graphics::Vertex>& vertices);
		bool CreateIndexBuffer(const std::vector<UINT>& indices);
		void Bind();

	private:
		Graphics::VertexBuffer vertexBuffer;
		Graphics::IndexBuffer indexBuffer;

		Data data;
	};
}