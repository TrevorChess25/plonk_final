#pragma once
#include "game_state.h"
#include "paddle_player.h"
#include "ball.h"
#include "score.h"

class main_game : public tiny_state {
public:
	//NOTE: windows are passed by ref
	//if we pass by val, we have to return the obj
	void Init(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	paddle_player* player1;
	paddle_player* player2;
	ball* ball_obj;
	Score* score1;
	Score* score2;


	sf::Font* font;
};
