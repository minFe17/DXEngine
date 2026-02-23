#pragma once
#include "DXEngineComponent.h"
#include "DXEngineTexture.h"
#include "DXEngineMaterial.h"
#include "DXEngineMesh.h"

namespace DXEngine
{
	class BaseRenderer : public Component
	{
	public:
		BaseRenderer(Enum::EComponentType type);
		virtual ~BaseRenderer();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;

		void Draw();

		const Material* GetMaterial() const { return material; }
		void SetMaterial(Material* material) { this->material = material; }

		const Mesh* GetMesh() const { return mesh; }
		void SetMesh(Mesh* mesh) { this->mesh = mesh; }

	private:
		Material* material;
		Mesh* mesh;
	};
}