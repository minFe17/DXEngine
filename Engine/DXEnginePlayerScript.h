#pragma once
#include "..\\Engine_Source\DXEngineScript.h"

namespace DXEngine
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
	};
}