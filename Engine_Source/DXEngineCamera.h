#pragma once
#include "DXEngineComponent.h"
#include "DXEngineEvent.h"
#include "DXEngineGameObject.h"

namespace DXEngine
{
	using namespace DXEngine::Math;


	class Camera : public Component
	{
	public:
		enum class EProjectionType
		{
			Perspective,
			Orthographic,
			Max,
		};

		static Matrix GetGpuViewMatrix() { return ViewMatrix; }
		static Matrix GetGpuProjectionMatrix() { return ProjectionMatrix; }
		static void SetGpuViewMatrix(Matrix matrix) { ViewMatrix = matrix; }
		static void SetGpuProjectionMatrix(Matrix matrix) { ProjectionMatrix = matrix; }

		Camera();
		~Camera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;

		void CreateViewMatrix();
		void CreateProjectionMatrix(EProjectionType type); 
		const Matrix& GetViewMatrix() { return viewMatrix; }
		const Matrix& GetProjectionMatrix() { return projectionMatrix; }

		void SetProjectionType(EProjectionType type) { projectionType = type; }
		void SetSize(float size) { this->size = size; }

	private:
		static Matrix ViewMatrix;
		static Matrix ProjectionMatrix;

		EProjectionType projectionType;

		Matrix viewMatrix;
		Matrix projectionMatrix;
		float aspectRatio;
		float nearValue;
		float farValue;
		float size;
	};
}