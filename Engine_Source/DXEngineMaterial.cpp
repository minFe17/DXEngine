#include "DXEngineMaterial.h"

namespace DXEngine
{
	Material::Material() : Resource(Enum::EResourceType::Material), mode(Graphics::ERenderingMode::Opaque), albedoTexture(nullptr), shader(nullptr)
	{

	}

	Material::~Material()
	{
	}

	HRESULT Material::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	HRESULT Material::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Material::Bind()
	{
		if (shader)
			shader->Bind();
		if (albedoTexture)
			albedoTexture->Bind(Graphics::EShaderStage::PS, (UINT)Graphics::ETextureType::Albedo);
	}
}