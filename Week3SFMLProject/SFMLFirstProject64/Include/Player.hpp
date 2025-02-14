#pragma once
#pragma region step 1

#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML\Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "Entity.hpp"


class Player : public Entity
{

public:
	enum class Type
	{
		Eagle,
		Raptor,
	};


public:
	Player();


	sf::Sprite& getSprite();

	virtual	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Time);

private:

	sf::Sprite mSprite;
	sf::Texture texture2;
	TextureHolder textures;
};

