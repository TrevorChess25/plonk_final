#pragma once
#include "paddle.h"
#include "ball.h"

class paddle_ai :public paddle {
public:
	//prototypes for paddle funcs
	paddle_ai(int player_num);
	void set_ball(ball* ball_obj);
	void Update();
private:
	ball* ball_obj;
	int player_num, ball_y_pos;
	int paddle_h, paddle_center;
	float ai_spd;
};