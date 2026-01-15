#pragma once
#include "CommonInclude.h"

namespace DXEngine
{
	enum class EKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class EKeyCode
	{
		Q , W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up,
		Max,
	};

	class Input
	{
	public:
		struct Key
		{
				EKeyCode keyCode;
				EKeyState state;
				bool isPressed;
		};

		static void Init();
		static void Update();

		static bool GetKeyDown(EKeyCode code) { return keys[(UINT)code].state == EKeyState::Down; }
		static bool GetKeyUp(EKeyCode code) { return keys[(UINT)code].state == EKeyState::Up; }
		static bool GetKey(EKeyCode code) { return keys[(UINT)code].state == EKeyState::Pressed; }
		
	private:
		static std::vector<Input::Key> keys;
	};
}