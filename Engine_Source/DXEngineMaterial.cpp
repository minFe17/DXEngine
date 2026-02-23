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

	void Material::BindShader()
	{
		if (shader)
			shader->Bind();
	}

	void Material::BindTextures()
	{
		if (albedoTexture)
			albedoTexture->Bind(Graphics::EShaderStage::PS, (UINT)Graphics::ETextureType::Albedo);
	}

	void Material::SetRenderingMode(const Graphics::ERenderingMode renderingMode)
	{
		mode = renderingMode;

		switch (mode)
		{
		case Graphics::ERenderingMode::Opaque:
			shader->SetRasterizerState(Graphics::ERasterizerState::SolidNone);
			shader->SetBlendState(Graphics::EBlendState::Opaque);
			shader->SetDepthStencilState(Graphics::EDepthStencilState::LessEqual);
			break;

		case Graphics::ERenderingMode::CutOut:
			shader->SetRasterizerState(Graphics::ERasterizerState::SolidNone);
			shader->SetBlendState(Graphics::EBlendState::Cutout);
			shader->SetDepthStencilState(Graphics::EDepthStencilState::LessEqual);
			break;

		case Graphics::ERenderingMode::Transparent:
			shader->SetRasterizerState(Graphics::ERasterizerState::SolidNone);
			shader->SetBlendState(Graphics::EBlendState::Transparent);
			shader->SetDepthStencilState(Graphics::EDepthStencilState::Always);
			break;

		default:
			break;
		}
	}
}