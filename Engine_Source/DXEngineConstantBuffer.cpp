#include "DXEngineConstantBuffer.h"

namespace DXEngine::Graphics
{
	ConstantBuffer::ConstantBuffer() : size(0), type(ECBType::Max)
	{
	}

	ConstantBuffer::~ConstantBuffer()
	{
	}

	bool ConstantBuffer::Create(ECBType type, UINT size, void* data)
	{
		this->type = type;
		this->size = size;
		desc.ByteWidth = size;
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		D3D11_SUBRESOURCE_DATA sub = {};
		sub.pSysMem = data;

		bool succes = false;
		if (data == NULL)
			succes = GetDevice()->CreateBuffer(&desc, nullptr, buffer.GetAddressOf());
		else
			succes = GetDevice()->CreateBuffer(&desc, &sub, buffer.GetAddressOf());

		if (!succes)
			assert(NULL);

		return true;
	}

	void ConstantBuffer::SetData(void* data) const
	{
		GetDevice()->SetDataGpuBuffer(buffer.Get(), data, size);
	}

	void ConstantBuffer::Bind(EShaderStage stage) const
	{
		GetDevice()->BindConstantBuffer(stage, type, buffer.Get());
	}
}