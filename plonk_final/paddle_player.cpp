#include "paddle_player.h"

paddle_player::paddle_player (int player_num) {
		this->player_num = player_num;
		//if player num is 0 load p1's sprite
		//otherwise load p2's sprite
		switch (this->player_num) {
		case 0:
			this->Load("paddle1.png");
			break;
		default:
			this->Load("paddle2.png");
			break;
		}
		//alias for paddle height
		paddle_h = this->getGlobalBounds().height;
	}

	//calculates vertical velocity and updates via Entity's method
void paddle_player::Update() {
	//creates shorter aliases for up/down key press
	this->p1_upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
	this->p1_downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
	this->p2_upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->p2_downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

	//adds vertical v based on player num's keybinds
	switch (this->player_num) {
	case 0:
		//subtracts positive y velocity from negative to get total displacement
		this->velocity.y = 20 * (p1_downKey - p1_upKey);
		break;
	default:
		this->velocity.y = 20 * (p2_downKey - p2_upKey);
		break;
	}
	Entity::Update();

	//screen bottom collision
	if (this->getPosition().y < 0) {
		this->move(0, 20.0f);
	}
	//screen top collision
	if (this->getPosition().y + paddle_h > 600) {
		this->move(0, -20.0f);
	}
}