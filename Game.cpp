#include <Game.hpp>
#include <Constants.hpp>
#include <Bikes.hpp>
#include <MainMenu.hpp>
Game::Game(){
	
}
Game::~Game(){
}
void Game::WindowSetup(){
	
	MainMenu Main;
	sf::Vector2f MousePosition;
	bool Game1 = false;
	bool SetUp = false; 
	bool MainMenuOpen = true;
	int amount = 0;
	
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Tron");
	Bikes *bike = new Bikes();
	while(window.isOpen()){
		sf::Event event;
		MousePosition = Main.MousePosition(&window);
		window.setKeyRepeatEnabled(false);
		
		if(MainMenuOpen == true){
			MainMenuOpen = Main.draw(&window,MousePosition, event);
		}else{
			window.clear(sf::Color(1.f,82.f,111.0f));
			if(!SetUp){
				bike->BikeSetup();
				SetUp = true;
			}
			bike->draw(&window);
		}
		
		
		while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed){
					window.close();
				}
				if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && SetUp == false){
					amount = Main.SetUpGame(MousePosition);
					if(Game1 = true){
						Bikes *bike = new Bikes();
					}
					bike->Amount = amount;
				}
				if(event.type == sf::Event::KeyPressed && SetUp == true){
					bike->PlayerInput();
				}
				if(event.type == sf::Event::MouseButtonPressed && SetUp == true){
					bike->PlayerInput();
				}
				if(event.key.code == sf::Keyboard::B && event.type == sf::Event::KeyPressed){
					delete bike;
					MainMenuOpen = true;
					Game1 = true;
				}
		}
		
		window.setFramerateLimit(60);
		window.setKeyRepeatEnabled(false);
		window.display();
		
	}
}