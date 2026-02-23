#pragma once
#include "..//Engine_Source/DXEngineGameObject.h"

namespace DXEngine
{
	class ProjectTile : public GameObject
	{
	public:
		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
	};
}