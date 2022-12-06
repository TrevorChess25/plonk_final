#include "paddle_ai.h"
#include "ball.h"

paddle_ai::paddle_ai(int player_num) {
	this->player_num = player_num;
	this->ball_obj = ball_obj;

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
	//init aliases that don't need to be updated
	paddle_h = this->getGlobalBounds().height;
}

void paddle_ai::set_ball(ball* ball_obj) {
	this->ball_obj = ball_obj;
}

void paddle_ai::Update() {
	final_paddle_pos = this->getPosition().y;
	//shorter aliases for paddle & ball
	ball_y_pos = this->ball_obj->getPosition().y;
	paddle_center = this->getPosition().y + paddle_h / 2;

	//alias for checking if paddle goes off-screen next update
	paddle_near_top = this->getPosition().y + paddle_h + 7.2f > 600;
	paddle_near_btm = this->getPosition().y - paddle_h - 7.2f < 0;
	paddle_at_top = this->getPosition().y + paddle_h > 600;
	paddle_at_btm = this->getPosition().y - paddle_h < 0;

	//if we didn't have this paddle would move
	//before ball was created
	if (this->ball_obj != NULL) {
		
		/*
		//Only check if paddle approaches edges when it's moving
		if (final_paddle_pos - init_paddle_pos != 0) {
			//when paddle is close to window's top
			//move slowly towards top
			if (paddle_near_top) {
				while (!paddle_at_top) {
					this->move(0, 1.0f);
				}
			}
			//when paddle is close to window's btm
			//move slowly towards bottom
			if (!paddle_near_btm) {
				while (!paddle_at_btm) {
					this->move(0, -1.0f);
				}
			}

		}
		*/
		
		//if paddle is below ball, move up
		if (paddle_center < ball_y_pos) {
				this->move(0, 7.2f);
		}

		//if paddle is above ball, move down
		if (paddle_center > ball_y_pos) {
			this->move(0, -7.2f);
		}
		init_paddle_pos = this->getPosition().y;
	}

	//calculates vertical velocity and updates via Entity's method
	Entity::Update();

	//screen bottom collision
	if (this->getPosition().y < 0) {
		this->move(0, 20.0f);
	}
	//screen top collision
	if (this->getPosition().y + paddle_h > 600) {
		this->move(0, -20.0f);
	}
}