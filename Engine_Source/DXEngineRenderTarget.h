#pragma once
#include "DXEngineTexture.h"

namespace DXEngine::Graphics
{
	enum class ERenderTragetFormat
	{
		None = 0,
		RGBA8,						// Color
		RED_INTEGER,				// RED 채널에 정수형 데이터 저장 (정수형 데이터 저장을 용도로 사용)
		DEPTH24STENCIL8,			// Depth/stencil
		SHADER_RESOURCE,			// Shader resource
		Depth = DEPTH24STENCIL8		// Defaults
	};

	// 렌더타겟의 사용 목적을 지정하는 구조체
	struct RenderTargetTextureSpecification
	{
		RenderTargetTextureSpecification() = default;
		RenderTargetTextureSpecification(ERenderTragetFormat format) : TextureFormat(format) {}

		ERenderTragetFormat TextureFormat = ERenderTragetFormat::None;
	};

	// 렌더타겟들(여러개)의 사용목적을 지정하는 구조체
	struct RenderTargetAttachmentSpecification
	{
		RenderTargetAttachmentSpecification() = default;
		RenderTargetAttachmentSpecification(std::initializer_list<RenderTargetTextureSpecification> attachments) : Attachments(attachments) {}

		std::vector<RenderTargetTextureSpecification> Attachments;
	};

	struct RenderTargetSpecification
	{
		UINT Width = 0, Height = 0;
		RenderTargetAttachmentSpecification Attachments;
		UINT Samples = 1;

		bool SwapChainTarget = false;
	};

	class RenderTarget
	{
	public:
		RenderTarget(const RenderTargetSpecification& spec);
		virtual ~RenderTarget();

		static RenderTarget* Create(const RenderTargetSpecification& spec);

		void Invalidate();
		void Bind();
		void Unbind();

		void Resize(UINT width, UINT height);
		int ReadPixel(uint32_t attachmentIndex, int x, int y);

		void ClearAttachment(UINT index, const void* value);

		Texture* GetAttachmentTexture(UINT index) 
		{ 
			if (index >= attachments.size()) assert(NULL && "Rendertarget is not exist"); 
				return attachments[index]; 
		}
		RenderTargetSpecification& GetSpecification() { return specification; }

	private:
		RenderTargetSpecification specification;

		std::vector<RenderTargetTextureSpecification> specifications;
		RenderTargetTextureSpecification depthAttachmentSpecification;

		std::vector<Texture*> attachments;
		Texture* depthAttachment;
	};
}