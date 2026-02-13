#include "DXEngineShader.h"
#include "DXEngineRenderer.h"
#include "DXEngineResources.h"

namespace DXEngine::Graphics
{
	bool Shader::isWireframe = false;

	Shader::Shader() : Resource(Enum::EResourceType::Shader), rasterizerState(ERasterizerState::SolidBack), blendState(EBlendState::AlphaBlend), depthStencilState(EDepthStencilState::LessEqual)
	{
	}

	Shader::~Shader()
	{
	}

	HRESULT Shader::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	HRESULT Shader::Load(const std::wstring& path)
	{
		size_t  fineNameBeginOffset = path.rfind(L"\\") + 1;
		size_t  fineNameEndOffset = path.length() - fineNameBeginOffset;
		const std::wstring fileName(path.substr(fineNameBeginOffset, fineNameEndOffset));

		if (!Create(EShaderStage::VS, fileName))
			return S_FALSE;
		if (!Create(EShaderStage::PS, fileName))
			return S_FALSE;

		return S_OK;
	}

	bool Shader::Create(const EShaderStage stage, const std::wstring& fileName)
	{
		if (stage == EShaderStage::VS)
			CreateVertexShader(fileName);
		if (stage == EShaderStage::PS)
			CreatePixelShader(fileName);

		return true;
	}

	bool Shader::CreateVertexShader(const std::wstring& fileName)
	{
		if (!GetDevice()->CreateVertexShader(fileName, vertexShaderBlob.GetAddressOf(), vertexShader.GetAddressOf()))
			return false;

		return true;
	}

	bool Shader::CreatePixelShader(const std::wstring& fileName)
	{
		if (!GetDevice()->CreatePixelShader(fileName, pixelShaderBlob.GetAddressOf(), pixelShader.GetAddressOf()))
			return false;

		return true;
	}

	void Shader::Bind()
	{
		if (isWireframe)
		{
			Shader* wireframeShader = Resources::Find<Shader>(L"WireframeShader");
			Microsoft::WRL::ComPtr<ID3D11VertexShader> wireframeShaderVS = wireframeShader->GetVertexShader();
			Microsoft::WRL::ComPtr<ID3D11PixelShader> wireframeShaderPS = wireframeShader->GetPixelShader();
			Microsoft::WRL::ComPtr<ID3D11RasterizerState> wireframeRasterizerState = Renderer::rasterizerStates[static_cast<UINT>(ERasterizerState::Wireframe)];

			GetDevice()->BindVertexShader(wireframeShaderVS.Get());
			GetDevice()->BindPixelShader(wireframeShaderPS.Get());
			GetDevice()->BindRasterizerState(wireframeRasterizerState.Get());
			GetDevice()->BindBlendState(Renderer::blendStates[static_cast<UINT>(blendState)].Get(), nullptr, 0xffffff);
			GetDevice()->BindDepthStencilState(Renderer::depthStencilStates[static_cast<UINT>(depthStencilState)].Get(), 0);

			return;
		}

		if (vertexShader)
			GetDevice()->BindVertexShader(vertexShader.Get());
		if (pixelShader)
			GetDevice()->BindPixelShader(pixelShader.Get());

		GetDevice()->BindRasterizerState(Renderer::rasterizerStates[(UINT)rasterizerState].Get());
		GetDevice()->BindBlendState(Renderer::blendStates[(UINT)blendState].Get(), nullptr, 0xffffff);
		GetDevice()->BindDepthStencilState(Renderer::depthStencilStates[static_cast<UINT>(depthStencilState)].Get(), 0);
	}
}