#pragma once
#include "DXEngineResource.h"
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine::Graphics
{
	class Shader : public Resource
	{
	public:
		Shader();
		virtual ~Shader();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		bool Create(const EShaderStage stage, const std::wstring& fileName);
		bool CreateVertexShader(const std::wstring& fileName);
		bool CreatePixelShader(const std::wstring& fileName);

		void Bind();

		Microsoft::WRL::ComPtr<ID3DBlob> GetVertexShaderBlob() { return vertexShaderBlob; }

	private:
		Microsoft::WRL::ComPtr<ID3DBlob> vertexShaderBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> hullShaderBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> domainShaderBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> geometryShaderBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> pixelShaderBlob;

		Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
		Microsoft::WRL::ComPtr<ID3D11HullShader> hullShader;
		Microsoft::WRL::ComPtr<ID3D11DomainShader> domainShader;
		Microsoft::WRL::ComPtr<ID3D11GeometryShader> geometryShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	};
}