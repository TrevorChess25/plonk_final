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
	int init_paddle_pos, final_paddle_pos;
	bool paddle_near_top, paddle_near_btm;
	bool paddle_at_top, paddle_at_btm;
};