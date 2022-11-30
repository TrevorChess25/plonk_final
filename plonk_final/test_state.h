#pragma once
#include "game_state.h"
//inherits all game methods to conduct test
class test_state: public tiny_state {
public:
	//NOTE: windows are passed by ref
	//if we pass by val, we have to return the obj
	void Init(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	//bool paused;
};