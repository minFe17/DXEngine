#pragma once
#include "DxEngineEntity.h"

namespace DXEngine
{
	class Resource : public Entity
	{
	public:
		Resource(Enum::EResourceType type);
		virtual ~Resource();

		virtual HRESULT Save(const std::wstring& path) = 0;
		virtual HRESULT Load(const std::wstring& path) = 0;
		const std::wstring& GetPath() { return path; }
		void SetPath(const std::wstring& path) { this->path = path; }

	private:
		const Enum::EResourceType type;
		std::wstring path;
	};
}