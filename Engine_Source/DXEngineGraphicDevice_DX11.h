#pragma once
#include "DXEngineGraphics.h"

namespace DXEngine::Graphics
{
	class GraphicDevice_DX11
	{
	public:
		GraphicDevice_DX11();
		~GraphicDevice_DX11();

		bool CreateDevice();
		bool CreateSwapchain(DXGI_SWAP_CHAIN_DESC desc);
		bool GetBuffer(UINT buffer, REFIID riid, void** surface);
		bool CreateRenderTargetView(ID3D11Resource* resource, const D3D11_RENDER_TARGET_VIEW_DESC* desc, ID3D11RenderTargetView** renderTargetView);
		bool CreateDepthStencilView(ID3D11Resource* resource, const D3D11_DEPTH_STENCIL_VIEW_DESC* desc, ID3D11DepthStencilView** depthStencilView);
		bool CreateTexture2D(const D3D11_TEXTURE2D_DESC* desc, const D3D11_SUBRESOURCE_DATA* initialData, ID3D11Texture2D** texture2D);
		bool CreateSamplerState(const D3D11_SAMPLER_DESC* samplerDesc, ID3D11SamplerState** samplerState);
		bool CreateVertexShader(const std::wstring& fileName, ID3DBlob** code, ID3D11VertexShader** vertexShader);
		bool CreatePixelShader(const std::wstring& fileName, ID3DBlob** code, ID3D11PixelShader** pixelShader);
		bool CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* inputElementDescs, UINT numElements, const void* shaderBytecodeWithInputSignature, SIZE_T bytecodeLength, ID3D11InputLayout** inputLayout);
		bool CreateBuffer(const D3D11_BUFFER_DESC* desc, const D3D11_SUBRESOURCE_DATA* initData, ID3D11Buffer** buffer);
		bool CreateShaderResourceView(ID3D11Resource* resource, const D3D11_SHADER_RESOURCE_VIEW_DESC* desc, ID3D11ShaderResourceView** shaderResourceView);
		bool CreateRasterizerState(const D3D11_RASTERIZER_DESC* rasterizerDesc, ID3D11RasterizerState** rasterizerState);
		bool CreateBlendState(const D3D11_BLEND_DESC* blendDesc, ID3D11BlendState** blendState);
		bool CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC* depthStencilDesc, ID3D11DepthStencilState** depthStencilState);
		bool Resize(D3D11_VIEWPORT viewport);

		void SetDataGpuBuffer(ID3D11Buffer* buffer, void* data, UINT size);
		void SetShaderResource(EShaderStage stage, UINT startSlot, ID3D11ShaderResourceView** shaderResourceView);

		void BindInputLayout(ID3D11InputLayout* inputLayout);
		void BindVertexShader(ID3D11VertexShader* vertexShader);
		void BindPixelShader(ID3D11PixelShader* pixelShader);
		void BindPrimitiveTopology(const D3D11_PRIMITIVE_TOPOLOGY topology);
		void BindVertexBuffer(UINT startSlot, UINT numSamplers, ID3D11Buffer* const* vertexBuffers, const UINT* strides, const UINT* offset);
		void BindIndexBuffer(ID3D11Buffer* indexBuffer, DXGI_FORMAT format, UINT offset);
		void BindConstantBuffer(EShaderStage stage, ECBType type, ID3D11Buffer* buffer);
		void BindSampler(EShaderStage stage, UINT startSlot, UINT numSamplers, ID3D11SamplerState* const* samplers);
		void BindSamplers(UINT startSlot, UINT numSamplers, ID3D11SamplerState* const* samplers);
		void BindRasterizerState(ID3D11RasterizerState* rasterizerState);
		void BindBlendState(ID3D11BlendState* blendState, const FLOAT blendFactor[4], UINT sampleMask);
		void BindDepthStencilState(ID3D11DepthStencilState* depthStencilState, UINT stencilRef);
		void BindViewPort();
		void BindRenderTargets(UINT numViews = 1, ID3D11RenderTargetView* const* renderTargetViews = nullptr, ID3D11DepthStencilView* depthStencilView = nullptr);
		void BindDefaultRenderTarget();

		void ClearRenderTargetView();
		void ClearDepthStencilView();

		void Init();
		void Draw(UINT vertexCount, UINT startVertexLocation);
		void DrawIndexed(UINT indexCount, UINT startIndexLocation, INT baseVertexLocation);
		void Present();

	public:
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3D11Device> GetID3D11Device() { return device; }
		[[nodiscard]] Microsoft::WRL::ComPtr<ID3D11DeviceContext> GetID3D11DeviceContext() { return deviceContext; }

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> device;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> renderTarget;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	renderTargetView;
		Microsoft::WRL::ComPtr<ID3D11Texture2D>			depthStencil;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>	depthStencilView;

		Microsoft::WRL::ComPtr<IDXGISwapChain>	swapChain;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> samplers;
	};

	// This is a helper to get access to a global device instance
	//	- The engine uses this, but it is not necessary to use a single global device object
	//	- This is not a lifetime managing object, just a way to globally expose a reference to an object by pointer
	inline GraphicDevice_DX11*& GetDevice()
	{
		static GraphicDevice_DX11* device = nullptr;
		return device;
	}
}