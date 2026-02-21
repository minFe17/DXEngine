#pragma once
#include "..\\Engine_Source\\CommonInclude.h"

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include "ImGuizmo.h"
#include "ImSequencer.h"
#include "ImZoomSlider.h"
#include "ImCurveEdit.h"
#include "GraphEditor.h"

namespace Gui
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::string& name) { this->name = name; }
		std::string& GetName() { return name; }

	private:
		std::string name;
	};
}