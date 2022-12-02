#include "main_game.h"
#include "main_menu.h"

void main_game::Init(sf::RenderWindow* window) {
	//init for player's paddle objects
	this->player1 = new paddle_player(0);
	this->player2 = new paddle_player(1);

	//init window width and width of p2 paddle
	int window_w = window->getSize().x;
	int p2_w = this->player2->getGlobalBounds().width;
	//places player 2's paddle on right side of screen
	this->player2->setPosition(window_w - p2_w, 0);

	//NOTE: Load method included from entity class (inherited from main_game.h)
	this->player1->Load("paddle1.png");
	this->player2->Load("paddle2.png");
};
void main_game::Update(sf::RenderWindow* window) {
	//paddles are updated before menu is entered 
	//if paddle was updated after exiting to menu
	//they would continue to consume resources
	this->player1->Update();
	this->player2->Update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		core_state.set_state(new main_menu());
	}
};
void main_game::Render(sf::RenderWindow* window) {
	window->draw(*this->player1);
	window->draw(*this->player2);
};
void main_game::Destroy(sf::RenderWindow* window) {
	delete this->player1;
	delete this->player2;
};