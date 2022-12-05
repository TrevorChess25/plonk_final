#include "main_game.h"
#include "main_menu.h"

void main_game::Init(sf::RenderWindow* window) {
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/font.ttf");
	this->score1 = new Score(*font, 64U);
	this->score2 = new Score(*font, 64U);

	this->score2->setPosition(window->getSize().x - this->score2->getGlobalBounds().width, 0);

	//alias for window width & height
	//NOTE: vars not in header bc win can be resized
	int window_w = window->getSize().x;
	int window_h = window->getSize().y;

	//init for player's paddle objects
	this->player1 = new paddle_player(0);


	this->player2 = new paddle_player(1);

	this->ball_obj = new ball(this->score1, this->score2, this->player1, this->player2);

	this->ball_obj->Reset(window);
	//this->ball_obj->setPosition(window_w/ 2, window_h/ 2);


	//alias for width of p2's paddle
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
	this->ball_obj->Update(window);
	this->player1->Update();
	this->player2->Update();
	this->score1->Update();
	this->score2->Update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		core_state.set_state(new main_menu());
	}
};
void main_game::Render(sf::RenderWindow* window) {
	window->draw(*this->player1);
	window->draw(*this->player2);
	window->draw(*this->ball_obj);
	window->draw(*this->score1);
	window->draw(*this->score2);
};
void main_game::Destroy(sf::RenderWindow* window) {
	delete this->player1;
	delete this->player2;
	delete this->ball_obj;
	delete this->score1;
	delete this->score2;
};