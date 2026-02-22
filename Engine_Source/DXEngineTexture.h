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

		bool Create(UINT width, UINT height, DXGI_FORMAT format, UINT bindFlag);
		bool CreateSRV();
		bool CreateUnorderedAccessView();
		bool CreateRenderTargetView();
		bool CreateDepthStencilView();
		bool CreateGpuView(UINT flag);

		void Bind(EShaderStage stage, UINT startSlot);

		Microsoft::WRL::ComPtr<ID3D11Texture2D> GetTexture() { return texture; }
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>    GetRenderTargetView() { return  renderTargetView; }
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>    GetDepthStencilView() { return  depthStencilView; }
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>  GetShaderResourceView() { return  shaderResourceView; }
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> GetUnorderedAccessView() { return  unorderedAccessView; }
		void SetUnorderedAccessView(Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> value) { unorderedAccessView = value; }
		void SetRenderTargetView(Microsoft::WRL::ComPtr<ID3D11RenderTargetView> value) { renderTargetView = value; }
		void SetDepthStencilView(Microsoft::WRL::ComPtr<ID3D11DepthStencilView> value) { depthStencilView = value; }
		void SetShaderResourceView(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> value) { shaderResourceView = value; }
	
	private:
		ScratchImage image;

		D3D11_TEXTURE2D_DESC desc;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> texture;

		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>      renderTargetView;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>      depthStencilView;
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView>   unorderedAccessView;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	shaderResourceView;
	};
}