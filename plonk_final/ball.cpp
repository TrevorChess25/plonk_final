#include "ball.h"
ball::ball(paddle_player* player1, paddle_player* player2) {
	//load ball graphic
	this->Load("ball.png");
	//declare player vars for collision checks
	this->player1 = player1;
	this->player2 = player2;
	//set ball's init velocity
	this->velocity.x = 0.75f;
}

void ball::Update() {
	//shorter alias for paddle collision checks
	p1_collide = this->check_collision(this->player1);
	p2_collide = this->check_collision(this->player2);
	ball_y_pos = this->getPosition().y;
	ball_top_edge = this->getGlobalBounds().height;

	//paddle collision
	if (p1_collide || p2_collide) {
		this->velocity.x *= -1;
	}

	//screen top & bottom collision
	if (ball_y_pos < 0 || ball_y_pos + ball_top_edge > 600) {
		this->velocity.y *= -1;
	}
	Entity::Update();
}