#include "main_game.h"
#include "main_menu.h"

void main_game::Init(sf::RenderWindow* window) {
	this->paddle = new paddle_player(0);
	//Load method included from entity class (inherited from main_game.h)
	this->paddle->Load("paddle1.png");
};
void main_game::Update(sf::RenderWindow* window) {
	this->paddle->Update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		core_state.set_state(new main_menu());
	}
};
void main_game::Render(sf::RenderWindow* window) {
	window->draw(*this->paddle);
};
void main_game::Destroy(sf::RenderWindow* window) {
	delete this->paddle;
};