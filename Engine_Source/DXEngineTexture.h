#pragma once
#include "DXEngineResource.h"

namespace DXEngine::Graphcis
{
	class Texture : public Resource 
	{
	public:
		enum class ETextureType
		{
			Bmp,
			Png,
			Max,
		};

		Texture();
		~Texture();

		static Texture* Create(const std::wstring& name, UINT width, UINT height);

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() const { return width; }
		UINT GetHeight() const { return height; }
		ETextureType GetTextureType() const { return textureType; }
		bool IsAlpha() const { return isAlpha; }

		void SetWidth(UINT width) { this->width = width; }
		void SetHeight(UINT height) { this->height = height; }
	
	private:
		bool isAlpha;
		ETextureType textureType;

		UINT width;
		UINT height;
	};
}