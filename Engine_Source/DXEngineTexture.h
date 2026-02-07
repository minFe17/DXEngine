#pragma once
#include <DirectXTex.h>
#include <DirectXTex.inl>
#include <DirectXTexEXR.h>

#include "DXEngineResource.h"
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine::Graphics
{
	class Texture : public Resource 
	{
	public:
		
		Texture();
		~Texture();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		void Bind(EShaderStage stage, UINT startSlot);
	
	private:
		ScratchImage image;

		D3D11_TEXTURE2D_DESC desc;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> texture;

		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> shaderResourceView;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;
	};
}