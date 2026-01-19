#pragma once
#include "CommonInclude.h"

namespace DXEngine 
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { this->name = name; }
		std::wstring& GetName() { return name; }

	private:
		std::wstring name;
	};
}