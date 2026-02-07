#include "DXEngineShader.h"

namespace DXEngine::Graphics
{
	Shader::Shader() : Resource(Enum::EResourceType::Shader)
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
		if(!GetDevice()->CreateVertexShader(fileName, vertexShaderBlob.GetAddressOf(), vertexShader.GetAddressOf()))
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
		if (vertexShader)
			GetDevice()->BindVertexShader(vertexShader.Get());
		if (pixelShader)
			GetDevice()->BindPixelShader(pixelShader.Get());
	}
}