#include <Bikes.hpp>
#include <math.h>

#include <Constants.hpp>
#include <iostream>
Bikes::Bikes(){
	txmgr.loadTexture("Bike","Player1Bike.PNG");
	
	Amount = 0;
}
Bikes::~Bikes(){

}
void Bikes::PlayerInput(){
		switch(Amount){
			case 2:
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ 
				BikeArray[0].rotate(-90);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				BikeArray[0].rotate(90);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				DrawLine(BikeArray[0].getPosition());
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				BikeArray[1].rotate(-90);
				
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				BikeArray[1].rotate(90);
			}
			
			break;
		case 3:
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ 
				BikeArray[0].rotate(-90);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				BikeArray[0].rotate(90);
			}
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				BikeArray[1].rotate(-90);
				
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				BikeArray[1].rotate(90);
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
				BikeArray[2].rotate(-90);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
				BikeArray[2].rotate(90);
			}
			break;
		case 4:
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ 
				BikeArray[0].rotate(-90);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				BikeArray[0].rotate(90);
			}
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				BikeArray[1].rotate(-90);
				
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				BikeArray[1].rotate(90);
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
				BikeArray[2].rotate(-90);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
				BikeArray[2].rotate(90);
			}
			
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				BikeArray[3].rotate(90);
			}else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				BikeArray[3].rotate(-90);
			}
			
			break;
		default:
			break;
		}
	
}
void Bikes::DrawLine(sf::Vector2f SpritePosition){
	 
}
void Bikes::PlayerMovement(  ){
	
	for(int i = 0; i <= Amount; i++){
		//cos is x and sin is y.
		BikeArray[i].move(cos(3.14159265* BikeArray[i].getRotation()/ 180.f)*1.5f, sin(3.14159265*BikeArray[i].getRotation()/180.f)*1.5f);
		
		OutOfBounds();	
	}
	
}
void Bikes::draw(sf::RenderWindow *window){
	 
	for(int i = 0; i < Amount; i++){
		window->draw(BikeArray[i]);
	}
	PlayerMovement();
	CheckHit();
	window->setKeyRepeatEnabled(true);
}
 void Bikes::BikeSetup(){
	BikeArray.resize(Amount);
	//Intersected->resize(Amount);
	BikeRect.resize(Amount);
	
	 for(int i = 0; i < Amount ; i++){
		 BikeArray[i].setTexture(this->txmgr.getRef("Bike"));
		 BikeArray[i].setPosition(RandomSpawn());
		 BikeArray[i].setOrigin(21,10);
		 BikeArray[i].setRotation(0);
		 BikeArray.push_back(bike);
	}
 }
 void Bikes::OutOfBounds(){
	 sf::Vector2f window(WINDOW_WIDTH,WINDOW_HEIGHT);
	 for(int i = 0; i <= Amount; i++){
		 if(BikeArray[i].getPosition().x <= window.x - window.x){
			 BikeArray[i].setPosition(window.x,BikeArray[i].getPosition().y);
		 } else if(BikeArray[i].getPosition().x >= window.x){
			 BikeArray[i].setPosition(window.x - window.x, BikeArray[i].getPosition().y);
		 } else if(BikeArray[i].getPosition().y >= window.y){
			 BikeArray[i].setPosition(BikeArray[i].getPosition().x,window.y - window.y);
		 } else if(BikeArray[i].getPosition().y <= window.y - window.y){
			 BikeArray[i].setPosition(BikeArray[i].getPosition().x, window.y);
		 }
	 }
 }
 void Bikes::GetBikeRectangle(){
	 sf::FloatRect Rect;
	 for(int i = 0 ; i <= Amount; i++){
	Rect.width = BikeArray[i].getLocalBounds().width;
	Rect.height = BikeArray[i].getLocalBounds().height;
	Rect.left = BikeArray[i].getPosition().x;
	Rect.top = BikeArray[i].getPosition().y;
	BikeRect.insert(BikeRect.begin(),Rect);
	} 
 }
 sf::Vector2f Bikes::RandomSpawn(){
	sf::Vector2f Position;
	std::srand(std::rand());
	std::mt19937 rng(std::rand());
	std::uniform_int_distribution<int> genX(0, 750);
	std::uniform_int_distribution<int> genY(0, 550);
	Position.x = genX(rng);
	Position.y = genY(rng);
	std::cout << "Y: " << Position.y << std::endl;
	std::cout << "X: " << Position.x << std::endl;

 	return Position;
}
void Bikes::CheckHit(){
	
	bool Hit;
	int HitBike;
	for(int c = 0; c <= Amount; c++){
		GetBikeRectangle();
		 for(int j = 0 ; j <= Amount ; j++){
			if(j == c){
				j++;			
			}
			GetBikeRectangle();
			Hit = BikeRect[c].intersects(BikeRect[j]);
			if(Hit){
				HitBike = j;
				Hit = false;
				std::cout << HitBike;
			}else{
				HitBike = NULL;
			}
			
		}
		 if(HitBike != NULL){
			 BikeArray[c].setPosition(RandomSpawn());
		 }
	}
 }