#pragma once
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine::Graphics
{
	class VertexBuffer : public GpuBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		bool Create(const std::vector<Vertex>& vertexes);
		void Bind();

	private:
	};
}