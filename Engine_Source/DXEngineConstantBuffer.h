#pragma once
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine::Graphics
{
	class ConstantBuffer : public GpuBuffer
	{
	public:
		ConstantBuffer();
		~ConstantBuffer();

		bool Create(ECBType type, UINT size, void* data = NULL);

		void SetData(void* data);
		void Bind(EShaderStage stage);

	private:
		UINT size;
		ECBType type;
	};
}