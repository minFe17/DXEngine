#include "DXEngineInputLayout.h"

namespace DXEngine::Graphics
{
	InputLayout::InputLayout() : inputLayout(nullptr)
	{

	}

	InputLayout::~InputLayout()
	{

	}

	void InputLayout::CreateInputLayout(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength)
	{
		if (!(GetDevice()->CreateInputLayout(layout, vertexCount, pShaderBytecodeWithInputSignature, BytecodeLength, inputLayout.GetAddressOf())))
			assert(NULL && "Create input layout failed!");
	}

	void InputLayout::Bind()
	{
		if (inputLayout)
			GetDevice()->BindInputLayout(inputLayout.Get());
	}
}