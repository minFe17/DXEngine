#include "DXEngineRenderTarget.h"

namespace DXEngine::Graphics
{
	RenderTarget::RenderTarget(const RenderTargetSpecification& spec)
		: specification(spec)
		, depthAttachmentSpecification(ERenderTragetFormat::None)
		, depthAttachment(nullptr)
	{
		for (auto spec : specification.Attachments.Attachments)
		{
			if (spec.TextureFormat == ERenderTragetFormat::DEPTH24STENCIL8)
				depthAttachmentSpecification = spec;
			else
				specifications.emplace_back(spec);
		}

		// Create render target
		Invalidate();
	}

	RenderTarget::~RenderTarget()
	{
		for (Texture* texture : attachments)
		{
			delete texture;
			texture = nullptr;
		}
		attachments.clear();

		delete depthAttachment;
		depthAttachment = nullptr;
	}

	RenderTarget* RenderTarget::Create(const RenderTargetSpecification& spec)
	{
		RenderTarget* renderTarget = new RenderTarget(spec);

		return renderTarget;
	}

	void RenderTarget::Invalidate()
	{
		// delete prev attachments
		if (attachments.size() > 0)
		{
			for (Texture* texture : attachments)
			{
				delete texture;
				texture = nullptr;
			}

			attachments.clear();

			delete depthAttachment;
			depthAttachment = nullptr;
		}

		// Create render target attachments
		if (specifications.size() <= 0)
			assert(false && "Render target specification is empty!");

		for (auto spec : specifications)
		{
			Texture* texture = new Texture();
			switch (spec.TextureFormat)
			{
			case ERenderTragetFormat::RGBA8:
				texture->Create(specification.Width, specification.Height, DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM
					, D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET | D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE);
				break;
			case ERenderTragetFormat::RED_INTEGER:
				texture->Create(specification.Width, specification.Height, DXGI_FORMAT::DXGI_FORMAT_R32_UINT
					, D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET | D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE);
				break;
			case ERenderTragetFormat::SHADER_RESOURCE:
				texture->Create(specification.Width, specification.Height, DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM
					, D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE);
				break;

			default:
				break;
			}

			attachments.emplace_back(texture);
		}

		// Create depth attachment
		if (depthAttachmentSpecification.TextureFormat != ERenderTragetFormat::None)
		{
			depthAttachment = new Texture();
			depthAttachment->Create(specification.Width, specification.Height, DXGI_FORMAT::DXGI_FORMAT_D24_UNORM_S8_UINT
				, D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL);
		}
	}

	void RenderTarget::Bind()
	{
	}

	void RenderTarget::Unbind()
	{
	}

	void RenderTarget::Resize(UINT width, UINT height)
	{
		static const uint32_t MaxFramebufferSize = 8192;
		if (width == 0 || height == 0 || width > MaxFramebufferSize || height > MaxFramebufferSize)
		{
			assert(false && "Attempted to rezize framebuffer");
			return;
		}

		specification.Width = width;
		specification.Height = height;

		Invalidate();
	}

	int RenderTarget::ReadPixel(uint32_t attachmentIndex, int x, int y)
	{
		return 0;
	}

	void RenderTarget::ClearAttachment(UINT index, const void* value)
	{

	}
}