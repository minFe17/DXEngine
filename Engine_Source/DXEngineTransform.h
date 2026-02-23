#pragma once
#include "CommonInclude.h"
#include "DXEngineComponent.h"

namespace DXEngine
{
	using namespace Math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;

		void Bind();

		Transform* GetParent() { return parent; }
		const Matrix GetWorldMatrix() { return worldMatrix; }

		const Vector3 GetPosition() { return position; }
		const Vector3 GetRotation() { return rotation; }
		const Vector3 GetScale() { return scale; }

		void SetPosition(Vector3 value) { position = value; }
		void SetPosition(float x, float y, float z) { position = Vector3(x, y, z); }
		void SetRotation(Vector3 value) { rotation = value; }
		void SetRotation(float x, float y, float z) { rotation = Vector3(x, y, z); }
		void SetScale(Vector3 value) { scale = value; }
		void SetScale(float x, float y, float z) { scale = Vector3(x, y, z); }

		const Vector3 Foward() { return forward; };
		const Vector3 Right() { return right; };
		const Vector3 Up() { return up; };

	private:
		Transform* parent;
		Matrix worldMatrix;

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		Vector3 forward;
		Vector3 right;
		Vector3 up;
	};
}