#include "DXEngineGraphicDevice_DX11.h"
#include "DXEngineApplication.h"

extern DXEngine::Application application;

namespace DXEngine::Graphics
{
	GraphicDevice_DX11::GraphicDevice_DX11()
	{

	}

	GraphicDevice_DX11::~GraphicDevice_DX11()
	{

	}

	void GraphicDevice_DX11::Init()
	{
		D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
		UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if defined(DEBUG) || defined(_DEBUG)
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		D3D11CreateDevice(0, D3D_DRIVER_TYPE_HARDWARE, 0, creationFlags, featureLevels, ARRAYSIZE(featureLevels), D3D11_SDK_VERSION, device.GetAddressOf(), 0, deviceContext.GetAddressOf());

		DXGI_SWAP_CHAIN_DESC  swapChainDesc = {};
		swapChainDesc.OutputWindow = application.GetHwnd();
		swapChainDesc.Windowed = true;
		swapChainDesc.BufferCount = 2;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferDesc.Width = application.GetWidth();
		swapChainDesc.BufferDesc.Height = application.GetHeight();
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 144;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;

		UINT quility = 0;
		device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &quility);

		swapChainDesc.SampleDesc.Count = 1; 
		swapChainDesc.SampleDesc.Quality = 0;

		Microsoft::WRL::ComPtr<IDXGIDevice> dxGIDevice = nullptr;
		Microsoft::WRL::ComPtr<IDXGIAdapter> adapter = nullptr;
		Microsoft::WRL::ComPtr<IDXGIFactory> factory = nullptr;

		if (FAILED(device->QueryInterface(__uuidof(IDXGIDevice), (void**)dxGIDevice.GetAddressOf())))
			return;

		if (FAILED(dxGIDevice->GetParent(__uuidof(IDXGIAdapter), (void**)adapter.GetAddressOf())))
			return;

		if (FAILED(adapter->GetParent(__uuidof(IDXGIFactory), (void**)factory.GetAddressOf())))
			return;

		if (FAILED(factory->CreateSwapChain(device.Get(), &swapChainDesc, swapChain.GetAddressOf())))
			return;

		swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)renderTarget.GetAddressOf());
		device->CreateRenderTargetView(renderTarget.Get(), nullptr, renderTargetView.GetAddressOf());

		D3D11_TEXTURE2D_DESC depthStencilDesc = {};
		depthStencilDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
		depthStencilDesc.Format = DXGI_FORMAT::DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		depthStencilDesc.Width = application.GetWidth();
		depthStencilDesc.Height = application.GetHeight();
		depthStencilDesc.ArraySize = 1;
		depthStencilDesc.SampleDesc.Count = 1;
		depthStencilDesc.SampleDesc.Quality = 0;

		if (FAILED(device->CreateTexture2D(&depthStencilDesc, nullptr, depthStencil.GetAddressOf())))
			return;

		if (FAILED(device->CreateDepthStencilView(depthStencil.Get(), nullptr, depthStencilView.GetAddressOf())))
			return;
	}

	void GraphicDevice_DX11::Draw()
	{
		FLOAT backgroundColor[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
		deviceContext->ClearRenderTargetView(renderTargetView.Get(), backgroundColor);
		swapChain->Present(1, 0);
	}
}