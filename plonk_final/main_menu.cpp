#include "main_menu.h"
#include "main_game.h"
using namespace std;
void main_menu::Init(sf::RenderWindow* window) {
	//play is selected by default
	this->selected = 0;
	//allocates memory for font
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/font.ttf");

	this->title = new sf::Text("Plonk", *this->font,192U);
	//store center of title text in x&y vars
	int title_origin_x = this->title->getGlobalBounds().width / 2;
	int title_origin_y = this->title->getGlobalBounds().height / 2;
	//set origin of title
	this->title->setOrigin(title_origin_x,title_origin_y);
	//store window's center in x & y vars
	int title_x = window->getSize().x / 2;
	//y/4 is top-center of window
	int title_y = window->getSize().y / 4;
	//set position of title to window's center
	this->title->setPosition(title_x, title_y);

	this->play = new sf::Text("Play", *this->font, 64U);
	int play_origin_x = this->play->getGlobalBounds().width / 2;
	int play_origin_y = this->play->getGlobalBounds().height / 2;
	this->play->setOrigin(play_origin_x, play_origin_y);
	int play_x = window->getSize().x / 2;
	int play_y = window->getSize().y / 1.8;
	this->play->setPosition(play_x, play_y);

	this->quit = new sf::Text("Quit", *this->font, 64U);
	int quit_origin_x = this->quit->getGlobalBounds().width / 2;
	int quit_origin_y = this->quit->getGlobalBounds().height / 2;
	this->quit->setOrigin(quit_origin_x, quit_origin_y);
	int quit_x = window->getSize().x / 2;
	float quit_y = window->getSize().y / 1.5; 
	this->quit->setPosition(quit_x, quit_y);
};
void main_menu::Update(sf::RenderWindow* window) {
	//If Up is pressed and it wasn't on the last iteration 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey) {
		//if quit selected, now play is
		this->selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey) {
		//if play selected, now quit is
		this->selected += 1;
	}
	//if down is pressed when quit is selected, wrap around to play
	if (this->selected > 1) {
		this->selected = 0;
	}
	//if up is pressed when play is selected, wrap around to quit
	if (this->selected < 0) {
		this->selected = 1;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		switch (this->selected) {
		case 0:
			//if enter is pressed, when play is selected begin game
			core_state.set_state(new main_game());
			break;
		//if quit is selected when enter is pressed, quit game 
		case 1:
			quit_game = true;
			break;
		}
	}
	//creates shorter alias to check for key presses
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
};
void main_menu::Render(sf::RenderWindow* window) {
	//sets default color to white
	this->play->setFillColor(sf::Color::White);
	this->quit->setFillColor(sf::Color::White);
	switch(this->selected) {
	case 0:
		this->play->setFillColor(sf::Color::Green);
		break;
	case 1:
		this->quit->setFillColor(sf::Color::Red);
		break;
	}
	//draws menu text
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);
};
void main_menu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->quit;
};