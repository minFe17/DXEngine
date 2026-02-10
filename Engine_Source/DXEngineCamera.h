#pragma once
#include "DXEngineComponent.h"

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
		void Render() override;

		void CreateViewMatrix();
		void CreateProjectionMatrix(EProjectionType type);

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