#pragma once
#include "..//Engine_Source/DXEngineScript.h"
#include "..//Engine_Source/DXEngineTexture.h"

namespace DXEngine
{
	class ProjectTileScript : public Script
	{
	public:
		ProjectTileScript();
		virtual ~ProjectTileScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
	};
}