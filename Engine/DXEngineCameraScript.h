#pragma once
#include "..\\Engine_Source\DXEngineScript.h"
#include "..\\Engine_Source\\DXEngineTransform.h"

namespace DXEngine
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
	};
}