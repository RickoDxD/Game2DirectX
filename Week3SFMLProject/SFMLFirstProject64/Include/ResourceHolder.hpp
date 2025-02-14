#ifndef BOOK_RESOURCEHOLDER_HPP
#define BOOK_RESOURCEHOLDER_HPP

#pragma region Step1

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <SFML\Graphics.hpp>
//namespace Textures
//{
//	enum ID
//	{
//		Landscape,
//		Airplane,
//	};
//}

//class TextureHolder
template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	//void						load(Textures::ID id, const std::string& filename);
	void						load(Identifier id, const std::string& filename);

	template <typename Parameter>
	void						load(Identifier id, const std::string& filename, const Parameter& secondParam);


	//sf::Texture&					get(Textures::ID id);
	//const sf::Texture&			get(Textures::ID id) const;
	Resource&					get(Identifier id);
	const Resource&				get(Identifier id) const;

private:
	void						insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
	//std::map<Textures::ID, std::unique_ptr<sf::Texture>>	mTextureMap;
	std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;

};

#include "ResourceHolder.inl"
#endif