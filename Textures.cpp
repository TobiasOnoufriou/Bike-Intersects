
#include "Textures.h"
#include <map>

void Texture::loadTexture(const std::string& name, const std::string& filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);

	this->textures[name] = tex;
	return;
}

sf::Texture& Texture::getRef(const std::string& texture)
{
	return this->textures.at(texture);
}
