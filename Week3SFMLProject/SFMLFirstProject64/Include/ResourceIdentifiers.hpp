#pragma once

namespace sf
{
	class Texture;
}


namespace sf
{
	class Font;
}

namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
		Eagle,
		Raptor,
		Desert,
	};
}

enum class TextureID
{
	Landscape,
	Airplane,
	Eagle,
	Raptor,
	Desert,
};

enum class FontID
{
	sansation,
	font2,
};


template <typename Resource, typename Identifier>
class ResourceHolder;


//typedef ResourceHolder<sf::Texture, TextureID> TextureHolder;
//typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
using TextureHolder = ResourceHolder<sf::Texture, TextureID>;
using FontHolder = ResourceHolder<sf::Font, FontID>;

//typedef ResourceHolder<sf::Font, FontID> FontHolder;
