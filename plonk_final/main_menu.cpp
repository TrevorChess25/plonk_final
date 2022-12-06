#include "main_menu.h"
#include "one_p_game.h"
#include "two_p_game.h"
using namespace std;

void main_menu::Init(sf::RenderWindow* window) {
	//1P is selected by default
	this->selected = 0;
	//allocates memory for font
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/font.ttf");

	this->title = new sf::Text("Plonk", *this->font, 192U);
	//store center of title text in x&y vars
	int title_origin_x = this->title->getGlobalBounds().width / 2;
	int title_origin_y = this->title->getGlobalBounds().height / 2;
	//set origin of title
	this->title->setOrigin(title_origin_x, title_origin_y);
	//store window's center in x & y vars
	int title_x = window->getSize().x / 2;
	//y/4 is top-center of window
	int title_y = window->getSize().y / 4;
	//set position of title to window's center
	this->title->setPosition(title_x, title_y);

	this->one_p = new sf::Text("1 Player", *this->font,80U);
	int one_origin_x = this->one_p->getGlobalBounds().width / 2;
	int one_origin_y = this->one_p->getGlobalBounds().height / 2;
	this->one_p->setOrigin(one_origin_x, one_origin_y);
	int one_x = window->getSize().x / 2;
	int one_y = window->getSize().y / 1.8;
	this->one_p->setPosition(one_x, one_y);

	this->two_p = new sf::Text("2 Player", *this->font, 80U);
	int two_origin_x = this->two_p->getGlobalBounds().width / 2;
	int two_origin_y = this->two_p->getGlobalBounds().height / 2;
	this->two_p->setOrigin(two_origin_x, two_origin_y);
	int two_x = window->getSize().x / 2;
	int two_y = window->getSize().y / 1.47;
	this->two_p->setPosition(two_x, two_y);

	this->quit = new sf::Text("Quit", *this->font, 64U);
	int quit_origin_x = this->quit->getGlobalBounds().width / 2;
	int quit_origin_y = this->quit->getGlobalBounds().height / 2;
	this->quit->setOrigin(quit_origin_x, quit_origin_y);
	int quit_x = window->getSize().x / 2;
	float quit_y = window->getSize().y / 1.225; 
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
	//if down is pressed when quit is selected, wrap around to 1p
	if (this->selected > 2) {
		this->selected = 0;
	}
	//if up is pressed when 1p is selected, wrap around to quit
	if (this->selected < 0) {
		this->selected = 2;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		switch (this->selected) {
		//1p's case
		case 0:
			core_state.set_state(new one_p_game());
			break;
		//2p's case
		case 1:
			core_state.set_state(new two_p_game());
			break;
		//quit's case
		case 2:
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
	this->one_p->setFillColor(sf::Color::White);
	this->two_p->setFillColor(sf::Color::White);
	this->quit->setFillColor(sf::Color::White);
	
	switch(this->selected) {
	case 0:
		this->one_p->setFillColor(sf::Color::Blue);
		break;
	case 1:
		this->two_p->setFillColor(sf::Color::Green);
		break;
	case 2:
		this->quit->setFillColor(sf::Color::Red);
		break;
	}
	//draws menu text
	window->draw(*this->title);
	window->draw(*this->one_p);
	window->draw(*this->two_p);
	window->draw(*this->quit);
};
void main_menu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->one_p;
	delete this->two_p;
	delete this->quit;
};