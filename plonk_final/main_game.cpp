#include "main_game.h"
#include "main_menu.h"

void main_game::Init(sf::RenderWindow* window) {
	
};
void main_game::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		core_state.set_state(new main_menu());
	}
};
void main_game::Render(sf::RenderWindow* window) {
	
};
void main_game::Destroy(sf::RenderWindow* window) {
	
};