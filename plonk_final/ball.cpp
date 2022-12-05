#include "ball.h"
ball::ball(Score* score1, Score* score2, paddle_player* player1, paddle_player* player2) {

	//load ball graphic
	this->Load("ball.png");
	this->score1 = score1;
	this->score2 = score2;
	//declare player vars for collision checks
	this->player1 = player1;
	this->player2 = player2;


	//set ball's init velocity
	this->velocity.x = 1.0f;
	this->velocity.y = 1.0f;
}

void ball::Update(sf::RenderWindow* window) 
{
	//short aliases for paddle collision
	p1_collide = this->check_collision(this->player1);
	p2_collide = this->check_collision(this->player2);

	if (p1_collide || p2_collide )
	{
		this->velocity.x *= -1;
	}

	//shorter alias for paddle collision checks
	ball_y_pos = this->getPosition().y;
	ball_top_edge = this->getGlobalBounds().height;

	//screen top & bottom collision
	if (ball_y_pos < 0 || (ball_y_pos + ball_top_edge) > window->getSize().y)
	{
		this->velocity.y *= -1;
	}

	if (this->getPosition().x < this->player1->getGlobalBounds().width)
	{
		this->score1->increment_score();
		this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	}
	if (this->getPosition().x > window->getSize().x  - this ->player2->getGlobalBounds().width)
	{
		this->score2->increment_score();
		this->setPosition(window->getSize().x / 2, window->getSize().y /2);
	}
	Entity::Update();
}