#pragma once
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine::Graphics
{
	class IndexBuffer : public GpuBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();

		bool Create(const std::vector<UINT>& indices);
		void Bind() const;

		UINT GetIndexCount() const { return indexCount; }

	private:
		UINT indexCount;
	};
}