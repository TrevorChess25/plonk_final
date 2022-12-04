#pragma once
#include "paddle_player.h"
class ball : public Entity {
public:
	//prototypes for ball funcs
	ball(paddle_player* player1, paddle_player* player2);
	void Update();
private:
	//paddle refs are needed to check collision
	paddle_player* player1;
	paddle_player* player2;
	bool p1_collide, p2_collide;
	float ball_y_pos, ball_top_edge;
};