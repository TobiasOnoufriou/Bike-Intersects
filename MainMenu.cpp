#include <MainMenu.hpp>
MainMenu::MainMenu(){
	txmgr.loadTexture("Left","LeftArrow.PNG");
	txmgr.loadTexture("Right","RightArrow.PNG");
	txmgr.loadTexture("Play","PlayButton.PNG");
	txmgr.loadTexture("Two", "Two.png");
	txmgr.loadTexture("Three", "Three.png");
	txmgr.loadTexture("Four", "Four.png");
	SetupSprites();
	
}
MainMenu::~MainMenu(){
	
}
void MainMenu::DeleteSprites(bool MainMenuOpen){
	if(MainMenuOpen == true){
		for(std::vector<sf::Sprite*>::iterator it = Arrows.begin(); it != Arrows.end();){
			it = Arrows.erase(it);
			MainMenuOpen = false;
		}
	}

}
sf::Vector2f MainMenu::MousePosition(sf::RenderWindow *window){
	sf::Vector2f MousePosition(sf::Mouse::getPosition(*window));
	return MousePosition;
}
bool MainMenu::intersects(sf::FloatRect other_box, sf::Vector2f m_pos){
			sf::FloatRect mouse_box;
			
			mouse_box.left = m_pos.x;
			mouse_box.top = m_pos.y;
			mouse_box.width = 16;
			mouse_box.height = 16;
		
		return mouse_box.intersects(other_box);
	}
sf::FloatRect MainMenu::GetRect(sf::Sprite *sprite){
	sf::FloatRect RectangleBox;
	RectangleBox.width = sprite->getLocalBounds().width;
	RectangleBox.height = sprite->getLocalBounds().height;
	RectangleBox.left = sprite->getPosition().x;
	RectangleBox.top = sprite->getPosition().y;
	return RectangleBox;
}
void MainMenu::SetTextureNumber(int Amount){
	if(Amount == 2){
		Number.setTexture(txmgr.getRef("Two"));
	}else if(Amount == 3){
		Number.setTexture(txmgr.getRef("Three"));
	}else if(Amount == 4){
		Number.setTexture(txmgr.getRef("Four"));
	}
}
int MainMenu::SetUpGame(sf::Vector2f MousePosition){
	
	bool IntersectsLeft;
	bool IntersectsRight;

	sf::FloatRect LeftRect;
	sf::FloatRect RightRect;
	LeftRect = GetRect(Arrows[0]); 
	RightRect = GetRect(Arrows[1]);
	
	IntersectsLeft = intersects(LeftRect, MousePosition);
	IntersectsRight = intersects(RightRect, MousePosition);
	if(IntersectsLeft && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(Amount > 2){
			Amount--;
			std::cout << Amount;
		}else if(Amount == 2){
			Amount = 4;
			std::cout << Amount;
		}
	}
	else if(IntersectsRight && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(Amount >= 4){
			Amount = 2;
			std::cout << Amount;
		}else if(Amount >= 2){
			Amount++;
			std::cout<< Amount;
		}
	}
	SetTextureNumber(Amount);
	return Amount;
}
bool MainMenu::draw(sf::RenderWindow *window,sf::Vector2f MousePosition, sf::Event &event){
		bool ExitMenu;
		int Amount = 2;
		Arrows.resize(3);
		window->clear();
		sf::FloatRect PlayButton;
		PlayButton = GetRect(&Play);
		
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && intersects(PlayButton,MousePosition)){
			DeleteSprites(false);
			ExitMenu = true;
			return false;
		}
		for(int i = 0; i < 2; i++){
			window->draw(*Arrows[i]);
		}
		window->draw(Number);
		window->draw(Play);
	return true;
}
void MainMenu::SetupSprites(){
	//Arrows[0] is the Left Arrow
	//Arrows[1] is the Right Arrow
	Arrows.push_back(&Left);
	Arrows.push_back(&Right);
	Amount = 2;
	Arrows[0]->setPosition(350, 400);
	Arrows[1]->setPosition(450,400);
	Play.setPosition(10,10);
	Arrows[0]->setTexture(this->txmgr.getRef("Left"));
	Arrows[1]->setTexture(this->txmgr.getRef("Right"));
	Play.setTexture(this->txmgr.getRef("Play"));
	Number.setTexture(this->txmgr.getRef("Two"));
	Number.setPosition(400,400);

}
