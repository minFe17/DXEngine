#pragma once
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine::Graphics
{
	class ConstantBuffer : public GpuBuffer
	{
	public:
		ConstantBuffer(ECBType typeValue);
		~ConstantBuffer();

		bool Create(UINT size, void* data = NULL);

		void SetData(void* data) const;
		void Bind(EShaderStage stage) const;

	private:
		UINT size;
		ECBType type;
	};
}