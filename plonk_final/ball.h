#pragma once
#include "paddle_player.h"
#include "score.h"

class ball : public Entity {
public:
	//prototypes for ball funcs
	ball(Score* score1, Score* score2, paddle_player* player1, paddle_player* player2);
	void Update(sf::RenderWindow* window);
private:
	Score* score1;
	Score* score2;
	//paddle refs are needed to check collision
	paddle_player* player1;
	paddle_player* player2;
	bool p1_collide, p2_collide;
	float ball_y_pos, ball_top_edge;
};