#pragma once
#include "entity.h"
class paddle_player:public Entity {
public:
	paddle_player(int player_number) {
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
	}
	
	//calculates vertical velocity and updates via Entity's method
	void Update() {
		//creates shorter aliases for up/down key press
		p1_upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
		p1_downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
		p2_upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		p2_downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
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
	}
private:
	int player_num;
	bool p1_upKey, p1_downKey, p2_upKey, p2_downKey;
};