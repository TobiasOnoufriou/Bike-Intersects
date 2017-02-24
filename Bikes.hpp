#include <sfml/Graphics.hpp>
#include <Constants.hpp>
#include <vector>
#include <random>
#include <Textures.h>

class Bikes{
public:
	Bikes();
	~Bikes();
	void PlayerInput( );
	void draw( sf::RenderWindow *window);
	void BikeSetup(  );
	sf::Sprite bike;
	sf::FloatRect *rect;
	std::vector<sf::FloatRect> BikeRect;
	std::vector<sf::Sprite> BikeArray;
	int Amount;
private:
	
	//std::vector<bool> *Intersected;
	Texture txmgr;
	sf::Vector2f RandomSpawn();
	void CheckHit();
	void CheckEdge( );
	void PlayerMovement(  );
	void OutOfBounds();
	void GetBikeRectangle();
	void DrawLine(sf::Vector2f SpritePosition);
	
};
