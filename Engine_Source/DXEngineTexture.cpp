#include "DXEngineTexture.h"
#include "DXEngineApplication.h"
#include <DXEngineResources.h>

extern DXEngine::Application application;

namespace DXEngine::Graphcis
{
	Texture::Texture() : Resource(Enum::EResourceType::Texture), isAlpha(false)
	{
	}

	Texture::~Texture()
	{
	}

	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image)
			return image;

		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		Resources::Insert(name + L"Image", image);
		return image;
	}

	HRESULT DXEngine::Graphcis::Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		return S_OK;
	}
}