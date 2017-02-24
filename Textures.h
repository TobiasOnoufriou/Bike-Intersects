#pragma once
#include <sfml/Graphics.hpp>
#include <map>
class Texture {
public:
	void loadTexture(const std::string& name, const std::string &filename);
	sf::Texture& getRef(const std::string& texture);
	Texture(){}
private:
	std::map<std::string, sf::Texture> textures;

};