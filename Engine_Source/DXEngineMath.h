#pragma once
#include <math.h>

namespace DXEngine::Math
{
#define PI 3.141592f;

	struct Vector2
	{
		static Vector2 Rotate(Vector2& vector, float degree)
		{
			float radian = (degree / 180.0f) * PI;
			vector.Normalize();
			float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
			float y = sinf(radian) * vector.x + cosf(radian) * vector.y;

			return Vector2(x, y);
		}

		static float Dot(Vector2& vector1, Vector2& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y;
		}

		static float Cross(Vector2& vector1, Vector2& vector2)
		{
			return vector1.x * vector2.y - vector1.y * vector2.x;
		}

		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2() : x(0.0f), y(0.0f)
		{

		}

		Vector2(float xValue, float yValue) : x(xValue), y(yValue)
		{

		}

		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}

		void operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}

		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator*(Vector2 other)
		{
			return Vector2(x * other.x, y * other.y);
		}

		Vector2 operator*(float value)
		{
			return Vector2(x * value, y * value);
		}

		Vector2 operator/(float value)
		{
			return Vector2(x / value, y / value);
		}

		void Clear()
		{
			x = 0.0f; 
			y = 0.0f;
		}

		float Length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2 Normalize()
		{
			float length = Length();
			x /= length;
			y /= length;
			return *this;
		}
	};
};