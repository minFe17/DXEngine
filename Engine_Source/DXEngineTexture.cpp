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

		HRESULT hResult = CreateShaderResourceView(Graphics::GetDevice()->GetID3D11Device().Get(), image.GetImages(), image.GetImageCount(), image.GetMetadata(), shaderResourceView.GetAddressOf());

		if (hResult == S_FALSE)
			assert(false);

		shaderResourceView->GetResource((ID3D11Resource**)texture.GetAddressOf());

		return S_OK;
	}

	void Texture::Bind(EShaderStage stage, UINT startSlot)
	{
		GetDevice()->SetShaderResource(stage, startSlot, shaderResourceView.GetAddressOf());
	}
}