#pragma once

namespace DXEngine::Enum
{
	enum class EComponentType
	{
		Transform,
		SpriteRenderer,
		Aniimator,
		Script,
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
		AudioClip,
		Animation,
		Prefab,
		Max,
	};
}