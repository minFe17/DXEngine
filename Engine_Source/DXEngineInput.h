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
		LButton, WheelButton, RButton,
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

		__forceinline static bool GetKeyDown(EKeyCode code) { return keys[(UINT)code].state == EKeyState::Down; }
		__forceinline static bool GetKeyUp(EKeyCode code) { return keys[(UINT)code].state == EKeyState::Up; }
		__forceinline static bool GetKey(EKeyCode code) { return keys[(UINT)code].state == EKeyState::Pressed; }
		__forceinline static Math::Vector2 GetmousePosition() { return mousePosition; }

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Key& key);
		static bool IsKeyDown(EKeyCode code);
		static void UpdateKeyDown(Key& key);
		static void UpdateKeyUp(Key& key);
		static void GetMousePositionByWindow();
		static void ClearKeys();
		
	private:
		static std::vector<Key> keys;
		static Math::Vector2 mousePosition;
	};
}