#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include <Textures.h>


class MainMenu{

public:
	sf::Sprite Right;
	sf::Sprite Left;
	sf::Sprite Number;
	int Amount;
	std::vector<sf::Sprite*> Arrows;
	
	int SetUpGame(sf::Vector2f MosusePosition);
	bool draw(sf::RenderWindow *window ,sf::Vector2f MousePosition,sf::Event &event);
	bool intersects(sf::FloatRect other_box, sf::Vector2f m_pos);

	sf::Vector2f MousePosition(sf::RenderWindow *window);
	
	MainMenu();
	~MainMenu();
private:

	sf::Sprite Play;
	Texture txmgr;
	sf::FloatRect GetRect(sf::Sprite *sprite);
	void DeleteSprites(bool MainMenuOpen);
	void SetTextureNumber(int Amount);
	void SetupSprites();
};