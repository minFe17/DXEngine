#pragma once
#include "DXEngineResource.h"
#include "DXEngineInputLayout.h"
#include "DXEngineVertexBuffer.h"
#include "DXEngineIndexBuffer.h"

namespace DXEngine
{
	class Mesh : public Resource
	{
	public:
		struct MeshData
		{
			MeshData();
			~MeshData();

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
		void SetVertexBufferParams(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout, const void* shaderBytecodeWithInputSignature, SIZE_T bytecodeLength);
		void Bind();

		UINT GetIndexCount() const { return indexBuffer.GetIndexCount(); }

	private:
		Graphics::InputLayout inputLayout;
		Graphics::VertexBuffer vertexBuffer;
		Graphics::IndexBuffer indexBuffer;

		MeshData data;
	};
}