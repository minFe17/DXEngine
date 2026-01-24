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

		HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return width; }
		UINT GetHeight() { return height; }
		HDC GetHdc() { return hdc; }
		ETextureType GetTextureType() { return textureType; }
		Gdiplus::Image* GetImage() { return image; }

		void SetWidth(UINT width) { this->width = width; }
		void SetHeight(UINT height) { this->height = height; }
	
	private:
		bool isAlpha;
		ETextureType textureType;
		Gdiplus::Image* image;
		HBITMAP bitmap;
		HDC hdc;

		UINT width;
		UINT height;
	};
}