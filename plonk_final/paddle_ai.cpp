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
	//shorter aliases for paddle & ball
	ball_y_pos = this->ball_obj->getPosition().y;
	paddle_center = this->getPosition().y + paddle_h / 2;

	//if we didn't have this paddle would move
	//before ball was created
	if (this->ball_obj != NULL) {
		
		//if paddle is below ball, move up
		if (paddle_center < ball_y_pos) {
				this->move(0, 7.2f);
		}

		//if paddle is above ball, move down
		if (paddle_center > ball_y_pos) {
			this->move(0, -7.2f);
		}
	}

	//calculates vertical velocity and updates via Entity's method
	Entity::Update();

	//screen bottom collision
	if (this->getPosition().y < 0) {
		this->move(0, 7.5f);
	}
	//screen top collision
	if (this->getPosition().y + paddle_h > 600) {
		this->move(0, -7.5f);
	}
}