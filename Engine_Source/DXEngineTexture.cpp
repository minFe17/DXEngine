#include "DXEngineTexture.h"
#include "DXEngineApplication.h"

extern DXEngine::Application application;

namespace DXEngine
{
    DXEngine::Graphcis::Texture::Texture() : Resource(Enum::EResourceType::Texture)
    {
    }

    DXEngine::Graphcis::Texture::~Texture()
    {
    }

    HRESULT DXEngine::Graphcis::Texture::Load(const std::wstring& path)
    {
        std::wstring ext = path.substr(path.find_last_of(L".") + 1);

        if (ext == L"bmp")
        {
            textureType = ETextureType::Bmp;
            bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

            if (bitmap == nullptr)
                return S_FALSE;

            BITMAP info = {};
            GetObject(bitmap, sizeof(BITMAP), &info);
            width = info.bmWidth;
            height = info.bmHeight;

            HDC mainDC = application.GetHDC();
            hdc = CreateCompatibleDC(mainDC);

            HBITMAP oldBitmap = (HBITMAP)SelectObject(hdc, bitmap);
            DeleteObject(oldBitmap);
        }
        else if (ext == L"png")
        {
            textureType = ETextureType::Png;
            image = Gdiplus::Image::FromFile(path.c_str());

            if (image == nullptr)
                return S_FALSE;

            width = image->GetWidth();
            height = image->GetHeight();

            return S_OK;
        }
    }
}