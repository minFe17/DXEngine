#pragma once

namespace DXEngine::Enum
{
	enum class EComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		Max,
	};

	enum class ELayerType
	{
		None,
		Background,
		Player,
		Max,
	};

	enum class EResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		Max,
	};
}