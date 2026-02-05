#include "DXEngineGraphicDevice_DX11.h"
#include "DXEngineApplication.h"
#include "DXEngineRenderer.h"
#include "DXEngineShader.h"
#include "DXEngineResources.h"

extern DXEngine::Application application;

namespace DXEngine::Graphics
{
	GraphicDevice_DX11::GraphicDevice_DX11()
	{
		DXEngine::Graphics::GetDevice() = this;

		if (!(CreateDevice()))
			assert(NULL && "Create Device Failed!");
	}

	GraphicDevice_DX11::~GraphicDevice_DX11()
	{

	}

	bool GraphicDevice_DX11::CreateDevice()
	{
		D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
		UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if defined(DEBUG) || defined(_DEBUG)
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		HRESULT hResult = D3D11CreateDevice(0, D3D_DRIVER_TYPE_HARDWARE, 0, creationFlags, featureLevels, ARRAYSIZE(featureLevels), D3D11_SDK_VERSION, device.GetAddressOf(), 0, deviceContext.GetAddressOf());
		return true;
	}

	bool GraphicDevice_DX11::CreateSwapchain(DXGI_SWAP_CHAIN_DESC desc)
	{
		Microsoft::WRL::ComPtr<IDXGIDevice>     dxGIDevice = nullptr;
		Microsoft::WRL::ComPtr<IDXGIAdapter>    adapter = nullptr;
		Microsoft::WRL::ComPtr<IDXGIFactory>    factory = nullptr;

		if (FAILED(device->QueryInterface(__uuidof(IDXGIDevice), (void**)dxGIDevice.GetAddressOf())))
			return false;

		if (FAILED(dxGIDevice->GetParent(__uuidof(IDXGIAdapter), (void**)adapter.GetAddressOf())))
			return false;

		if (FAILED(adapter->GetParent(__uuidof(IDXGIFactory), (void**)factory.GetAddressOf())))
			return false;

		if (FAILED(factory->CreateSwapChain(device.Get(), &desc, swapChain.GetAddressOf())))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::GetBuffer(UINT buffer, REFIID riid, void** surface)
	{
		if (FAILED(swapChain->GetBuffer(buffer, riid, surface)))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::CreateRenderTargetView(ID3D11Resource* resource, const D3D11_RENDER_TARGET_VIEW_DESC* desc, ID3D11RenderTargetView** renderTargetView)
	{
		if (FAILED(device->CreateRenderTargetView(resource, desc, renderTargetView)))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::CreateDepthStencilView(ID3D11Resource* resource, const D3D11_DEPTH_STENCIL_VIEW_DESC* desc, ID3D11DepthStencilView** depthStencilView)
	{
		if (FAILED(device->CreateDepthStencilView(resource, desc, depthStencilView)))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::CreateTexture2D(const D3D11_TEXTURE2D_DESC* desc, const D3D11_SUBRESOURCE_DATA* initData, ID3D11Texture2D** texture2D)
	{
		if (FAILED(device->CreateTexture2D(desc, initData, texture2D)))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::CreateVertexShader(const std::wstring& fileName, ID3DBlob** code, ID3D11VertexShader** vertexShader)
	{
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
		shaderFlags |= D3DCOMPILE_DEBUG;
		shaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;

		ID3DBlob* errorBlob = nullptr;
		const std::wstring shaderFilePath = L"..\\Shaders_SOURCE\\";
		D3DCompileFromFile((shaderFilePath + fileName + L"VS.hlsl").c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "vs_5_0", shaderFlags, 0, code, &errorBlob);

		if (errorBlob)
		{
			OutputDebugStringA((char*)errorBlob->GetBufferPointer());
			errorBlob->Release();
			assert(NULL && "hlsl file have problem check message!");
			return false;
		}

		if (FAILED(device->CreateVertexShader((*code)->GetBufferPointer(), (*code)->GetBufferSize(), nullptr, vertexShader)))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::CreatePixelShader(const std::wstring& fileName, ID3DBlob** code, ID3D11PixelShader** pixelShader)
	{
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
		shaderFlags |= D3DCOMPILE_DEBUG;
		shaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;

		ID3DBlob* errorBlob = nullptr;
		const std::wstring shaderFilePath = L"..\\Shaders_SOURCE\\";
		D3DCompileFromFile((shaderFilePath + fileName + L"PS.hlsl").c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", shaderFlags, 0, code, &errorBlob);

		if (errorBlob)
		{
			OutputDebugStringA((char*)errorBlob->GetBufferPointer());
			errorBlob->Release();
			assert(NULL && "hlsl file have problem check message!");
			return false;
		}

		if (FAILED(device->CreatePixelShader((*code)->GetBufferPointer(), (*code)->GetBufferSize(), nullptr, pixelShader)))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* inputElementDescs, UINT numElements, const void* shaderBytecodeWithInputSignature, SIZE_T bytecodeLength, ID3D11InputLayout** inputLayout)
	{
		if (FAILED(device->CreateInputLayout(inputElementDescs, numElements, shaderBytecodeWithInputSignature, bytecodeLength, inputLayout)))
			return false;

		return true;
	}

	bool GraphicDevice_DX11::CreateBuffer(const D3D11_BUFFER_DESC* desc, const D3D11_SUBRESOURCE_DATA* initData, ID3D11Buffer** buffer)
	{
		if (FAILED(device->CreateBuffer(desc, initData, buffer)))
			return false;

		return true;
	}

	void GraphicDevice_DX11::SetDataBuffer(ID3D11Buffer* buffer, void* data, UINT size)
	{
		D3D11_MAPPED_SUBRESOURCE sub = {};
		deviceContext->Map(buffer, 0, D3D11_MAP::D3D11_MAP_WRITE_DISCARD, 0, &sub);
		memcpy(sub.pData, data, size);
		deviceContext->Unmap(buffer, 0);
	}

	void GraphicDevice_DX11::BindVertexShader(ID3D11VertexShader* vertexShader)
	{
		deviceContext->VSSetShader(vertexShader, 0, 0);
	}

	void GraphicDevice_DX11::BindPixelShader(ID3D11PixelShader* pixelShader)
	{
		deviceContext->PSSetShader(pixelShader, 0, 0);
	}

	void GraphicDevice_DX11::BindVertexBuffer(UINT startSlot, UINT numBuffers, ID3D11Buffer* const* vertexBuffers, const UINT* strides, const UINT* offsets)
	{
		deviceContext->IASetVertexBuffers(startSlot, numBuffers, vertexBuffers, strides, offsets);
	}

	void GraphicDevice_DX11::BindIndexBuffer(ID3D11Buffer* indexBuffer, DXGI_FORMAT format, UINT offset)
	{
		deviceContext->IASetIndexBuffer(indexBuffer, format, offset);
	}

	void GraphicDevice_DX11::BindConstantBuffer(EShaderStage stage, ECBType type, ID3D11Buffer* buffer)
	{
		UINT slot = (UINT)type;
		switch (stage)
		{
		case DXEngine::Graphics::EShaderStage::VS:
			deviceContext->VSSetConstantBuffers(slot, 1, &buffer);
			break;
		case DXEngine::Graphics::EShaderStage::HS:
			deviceContext->HSSetConstantBuffers(slot, 1, &buffer);
			break;
		case DXEngine::Graphics::EShaderStage::DS:
			deviceContext->DSSetConstantBuffers(slot, 1, &buffer);
			break;
		case DXEngine::Graphics::EShaderStage::GS:
			deviceContext->GSSetConstantBuffers(slot, 1, &buffer);
			break;
		case DXEngine::Graphics::EShaderStage::PS:
			deviceContext->PSSetConstantBuffers(slot, 1, &buffer);
			break;
		case DXEngine::Graphics::EShaderStage::CS:
			deviceContext->CSSetConstantBuffers(slot, 1, &buffer);
			break;
		case DXEngine::Graphics::EShaderStage::All:
			deviceContext->VSSetConstantBuffers(slot, 1, &buffer);
			deviceContext->HSSetConstantBuffers(slot, 1, &buffer);
			deviceContext->DSSetConstantBuffers(slot, 1, &buffer);
			deviceContext->GSSetConstantBuffers(slot, 1, &buffer);
			deviceContext->PSSetConstantBuffers(slot, 1, &buffer);
			deviceContext->CSSetConstantBuffers(slot, 1, &buffer);
			break;
		default:
			break;
		}
	}

	void GraphicDevice_DX11::Init()
	{
#pragma region swapchain desc
		DXGI_SWAP_CHAIN_DESC swapChainDesc = {};

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

#pragma region 4X MSAA surported check
		UINT quility = 0;
		device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &quility);

#pragma endregion

		swapChainDesc.SampleDesc.Count = 1; // how many multisamples
		swapChainDesc.SampleDesc.Quality = 0;
#pragma endregion
		if (!(CreateSwapchain(swapChainDesc)))
			assert(NULL && "Create Swapchain Failed!");

		if (!(GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)renderTarget.GetAddressOf())))
			assert(NULL && "Couldn't bring rendertarget!");

		if (!(CreateRenderTargetView(renderTarget.Get(), nullptr, renderTargetView.GetAddressOf())))
			assert(NULL && "Create RenderTargetView Failed!");

#pragma region depthstencil desc
		D3D11_TEXTURE2D_DESC depthStencilDesc = {};
		depthStencilDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
		depthStencilDesc.Format = DXGI_FORMAT::DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		depthStencilDesc.Width = application.GetWidth();
		depthStencilDesc.Height = application.GetHeight();
		depthStencilDesc.ArraySize = 1;
		depthStencilDesc.SampleDesc.Count = 1;
		depthStencilDesc.SampleDesc.Quality = 0;
#pragma endregion
		if (!(CreateTexture2D(&depthStencilDesc, nullptr, depthStencil.GetAddressOf())))
			assert(NULL && "Create depthstencil texture failed!");

		if (!(CreateDepthStencilView(depthStencil.Get(), nullptr, depthStencilView.GetAddressOf())))
			assert(NULL && "Create depthstencilview failed!");

#pragma region inputLayout Desc
		D3D11_INPUT_ELEMENT_DESC inputLayoutDesces[2] = {};

		inputLayoutDesces[0].AlignedByteOffset = 0;
		inputLayoutDesces[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		inputLayoutDesces[0].InputSlot = 0;
		inputLayoutDesces[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		inputLayoutDesces[0].SemanticName = "POSITION";
		inputLayoutDesces[0].SemanticIndex = 0;

		inputLayoutDesces[1].AlignedByteOffset = 12;
		inputLayoutDesces[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		inputLayoutDesces[1].InputSlot = 0;
		inputLayoutDesces[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		inputLayoutDesces[1].SemanticName = "COLOR";
		inputLayoutDesces[1].SemanticIndex = 0;
#pragma endregion

		Graphics::Shader* triangle = Resources::Find<Graphics::Shader>(L"TriangleShader");
		if (!(CreateInputLayout(inputLayoutDesces, 2, triangle->GetVSBlob()->GetBufferPointer(), triangle->GetVSBlob()->GetBufferSize(), &Renderer::inputLayouts)))
			assert(NULL && "Create input layout failed!");

		Renderer::vertexBuffer.Create(Renderer::vertexes);
		Renderer::indexBuffer.Create(Renderer::indices);
	}

	void GraphicDevice_DX11::Draw()
	{
		FLOAT backgroundColor[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
		deviceContext->ClearRenderTargetView(renderTargetView.Get(), backgroundColor);
		deviceContext->ClearDepthStencilView(depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0);

		D3D11_VIEWPORT viewPort =
		{
			0, 0, application.GetWidth(), application.GetHeight(),
			0.0f, 1.0f
		};
		deviceContext->RSSetViewports(1, &viewPort);
		deviceContext->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), depthStencilView.Get());

		BindConstantBuffer(EShaderStage::VS, ECBType::Transform, Renderer::constantBuffer);

		deviceContext->IASetInputLayout(Renderer::inputLayouts);
		deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		Renderer::vertexBuffer.Bind();
		Renderer::indexBuffer.Bind();

		Vector4 pos(0.5f, 0.0f, 0.0f, 1.0f);
		Renderer::constantBuffers[(UINT)ECBType::Transform].SetData(&pos);
		Renderer::constantBuffers[(UINT)ECBType::Transform].Bind(EShaderStage::VS);

		Graphics::Shader* triangle = Resources::Find<Graphics::Shader>(L"TriangleShader");
		triangle->Bind();

		deviceContext->Draw(3, 0);

		swapChain->Present(1, 0);
	}
}