#pragma once
#include "DXEngineComponent.h"
#include "DXEngineCollider.h"

namespace DXEngine
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

	private:
	};
}