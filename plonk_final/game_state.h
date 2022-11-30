#pragma once
#include<SFML/Graphics.hpp>

class tiny_state {
public:
	virtual void Init(sf::RenderWindow *window) {
	}
	virtual void Update(sf::RenderWindow *window) {
	}
	virtual void Render(sf::RenderWindow *window) {
	}
	virtual void Destroy(sf::RenderWindow *window)
	{
	}
};

class game_state {
public:
	//constructor ensures state is NULL upon construction
	game_state() {
		this->state = NULL; 
	}
	void set_window(sf::RenderWindow* window) {
		this->window = window;
	}
	void set_state(tiny_state* state) {
		if (this->state != NULL) {
			this->state->Destroy(this->window);
		}
		//this->state is used bc we want to update the state in private
		//not the state used as the argument of the set func
		this->state = state;
		if (this->state != NULL) {
			this->state->Init(this->window);
		}
	}
	//calls the state's update method (from tiny)
	void Update() {
		if (this->state != NULL) {
			this->state->Update(this->window);
		}
	}
	void Render() {
		if (this->state != NULL) {
			this->state->Render(this->window);
		}
	}
	//destructor destroys game state after it has been rendered
	~game_state() {
		if (this->state != NULL) {
			this->state->Destroy(this->window);
		}
	}
private:
	sf::RenderWindow *window;
	tiny_state *state;

};
extern game_state core_state;

