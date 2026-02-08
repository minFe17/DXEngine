#pragma once
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine::Graphics
{
	class InputLayout
	{
	public:
		InputLayout();
		~InputLayout();

		void CreateInputLayout(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout, const void* shaderBytecodeWithInputSignature, SIZE_T bytecodeLength);
		void Bind();

	private:
		Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
	};
}