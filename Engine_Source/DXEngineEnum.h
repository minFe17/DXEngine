#pragma once

namespace DXEngine::Enum
{
	enum class EComponentType
	{
		Transform,
		Collider,
		Rigidbody,
		Script,
		SpriteRenderer,
		Aniimator,
		Camera,
		Max,
	};

	enum class ELayerType
	{
		None,
		Background,
		Player,
		Particle,
		Max,
	};

	enum class EResourceType
	{
		Texture,
		Animation,
		AudioClip,
		Shader,
		Prefab,
		Max,
	};

	enum class EColliderType
	{
		Circle2D,
		Rect2D,
		Max,
	};

	enum class EUIType
	{
		Button,
		Max,
	};
}