#pragma once
#include<SFML/Graphics.hpp>

class tiny_state {
	virtual void Init(sf::RenderWindow &window) {

	}
	virtual void Update(sf::RenderWindow &window) {

	}
	virtual void Render(sf::RenderWindow& window) {

	}
};

class game_state {
public:
	game_state() {}
	void set_state(tiny_state *state) {
		if (this->state != NULL) {
			this->state->Destroy(this->window);
		}
		//this->state is used bc we want to update the state in private
		//not the state used as the argument of the set func
		this->state = state;
	}
private:
	sf::RenderWindow window;
	tiny_state *state;

};

