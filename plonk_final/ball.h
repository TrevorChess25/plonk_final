#pragma once
#include "paddle_player.h"
#include "score.h"
#include<cstdlib>

class ball : public Entity {
public:
	//prototypes for ball funcs
	ball(Score* score1, Score* score2,
		paddle_player* player1, paddle_player* player2,
		sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);

private:
	Score* score1;
	Score* score2;
	//paddle refs are needed to check collision
	paddle_player* player1;
	paddle_player* player2;
	bool p1_collide, p2_collide;
	float ball_x_pos, ball_y_pos;
	int scrn_left_bnd, scrn_right_bnd;
	int ball_w, ball_h;
	int p1_h, p2_w, p2_h;
	int window_w, window_h;
};