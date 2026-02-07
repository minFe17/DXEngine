#include "DXEngineMesh.h"

namespace DXEngine
{
	Mesh::Data::Data() : topology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST), vertices{}, indices{}
	{

	}

	Mesh::Data::~Data()
	{
	}

	Mesh::Mesh() : Resource(Enum::EResourceType::Mesh)
	{

	}

	Mesh::~Mesh()
	{

	}

	HRESULT Mesh::Save(const std::wstring& path)
	{
		return S_OK;
	}

	HRESULT Mesh::Load(const std::wstring& path)
	{

		return S_OK;
	}

	bool Mesh::CreateVertexBuffer(const std::vector<Graphics::Vertex>& vertices)
	{
		data.vertices = vertices;
		return vertexBuffer.Create(vertices);
	}

	bool Mesh::CreateIndexBuffer(const std::vector<UINT>& indices)
	{
		data.indices = indices;
		return indexBuffer.Create(indices);
	}

	void Mesh::Bind()
	{
		vertexBuffer.Bind();
		indexBuffer.Bind();

		Graphics::GetDevice()->BindPrimitiveTopology(data.topology);
	}
}