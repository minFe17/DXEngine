#pragma once
#include "DXEngineResources.h"
#include "DXEngineTexture.h"
#include "DXEngineShader.h"

namespace DXEngine
{
	class Material : public Resource
	{
	public:
		struct Data
		{
			std::wstring albedo;
		};

		Material();
		virtual ~Material();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		void Bind();
		void BindShader();
		void BindTextures();

		void SetRenderingMode(const Graphics::ERenderingMode renderingMode);

		void SetShader(Graphics::Shader* shader) { this->shader = shader; }
		void SetAlbedoTexture(Graphics::Texture* texture)
		{
			albedoTexture = texture;
			data.albedo = texture->GetName();
		}
		Graphics::ERenderingMode GetRenderingMode() const { return mode; }

	private:
		Graphics::ERenderingMode mode;
		Material::Data data;

		Graphics::Texture* albedoTexture;
		Graphics::Shader* shader;
	};
}