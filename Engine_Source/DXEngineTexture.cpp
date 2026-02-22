#include "DXEngineTexture.h"
#include "DXEngineApplication.h"
#include <DXEngineResources.h>

extern DXEngine::Application application;

namespace DXEngine::Graphics
{
	Texture::Texture() : Resource(Enum::EResourceType::Texture), desc{}
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L".dds" || ext == L".DDS")
		{
			if (FAILED(LoadFromDDSFile(path.c_str(), DDS_FLAGS::DDS_FLAGS_NONE, nullptr, image)))
				return S_FALSE;
		}
		else if (ext == L".tga" || ext == L".TGA")
		{
			if (FAILED(LoadFromTGAFile(path.c_str(), nullptr, image)))
				return S_FALSE;
		}
		else // WIC (png, jpg, jpeg, bmp )
		{
			if (FAILED(LoadFromWICFile(path.c_str(), WIC_FLAGS::WIC_FLAGS_NONE, nullptr, image)))
				return S_FALSE;
		}

		HRESULT hResult = DirectX::CreateShaderResourceView(GetDevice()->GetID3D11Device().Get(), image.GetImages(), image.GetImageCount(), image.GetMetadata(), shaderResourceView.GetAddressOf());

		if (hResult == S_FALSE)
			assert(false);

		shaderResourceView->GetResource((ID3D11Resource**)texture.GetAddressOf());

		return S_OK;
	}

	bool Texture::Create(UINT width, UINT height, DXGI_FORMAT format, UINT bindFlag)
	{
		desc.BindFlags = bindFlag;
		desc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		desc.CPUAccessFlags = 0;
		desc.Format = format;
		desc.Width = width;
		desc.Height = height;
		desc.ArraySize = 1;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.MipLevels = 1;
		desc.MiscFlags = 0;

		if (!GetDevice()->CreateTexture2D(&desc, nullptr, texture.GetAddressOf()))
			return false;

		if (!CreateGpuView(desc.BindFlags))
			return false;

		return true;
	}

	bool Texture::CreateSRV()
	{
		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
		srvDesc.Format = desc.Format;
		srvDesc.Texture2D.MipLevels = 1;
		srvDesc.Texture2D.MostDetailedMip = 0;
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION::D3D11_SRV_DIMENSION_TEXTURE2D;

		if (!GetDevice()->CreateShaderResourceView(texture.Get(), &srvDesc, shaderResourceView.GetAddressOf()))
			return false;

		return true;
	}

	bool Texture::CreateUnorderedAccessView()
	{
		D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
		uavDesc.Format = desc.Format;
		uavDesc.Texture2D.MipSlice = 0;
		uavDesc.ViewDimension = D3D11_UAV_DIMENSION::D3D11_UAV_DIMENSION_TEXTURE2D;

		if (!GetDevice()->CreateUnorderedAccessView(texture.Get(), &uavDesc, unorderedAccessView.GetAddressOf()))
			return false;

		return true;
	}

	bool Texture::CreateRenderTargetView()
	{
		D3D11_RENDER_TARGET_VIEW_DESC rtvDesc = {};
		rtvDesc.Format = desc.Format;
		rtvDesc.Texture2D.MipSlice = 0;
		rtvDesc.ViewDimension = D3D11_RTV_DIMENSION::D3D11_RTV_DIMENSION_TEXTURE2D;


		if (!GetDevice()->CreateRenderTargetView(texture.Get(), &rtvDesc, renderTargetView.GetAddressOf()))
			return false;

		return true;
	}

	bool Texture::CreateDepthStencilView()
	{
		if (!GetDevice()->CreateDepthStencilView(texture.Get(), nullptr, depthStencilView.GetAddressOf()))
			return false;

		return true;
	}

	bool Texture::CreateGpuView(UINT flag)
	{
		if (flag & D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET)
		{
			if (!CreateRenderTargetView())
				return false;
		}
		if (flag & (UINT)D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL)
		{
			if (!CreateDepthStencilView())
				return false;
		}
		if (flag & D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE)
		{
			if (!CreateSRV())
				return false;
		}
		if (flag & D3D11_BIND_FLAG::D3D11_BIND_UNORDERED_ACCESS)
		{
			if (!CreateUnorderedAccessView())
				return false;
		}

		return true;
	}

	void Texture::Bind(EShaderStage stage, UINT startSlot)
	{
		GetDevice()->SetShaderResource(stage, startSlot, shaderResourceView.GetAddressOf());
	}
}