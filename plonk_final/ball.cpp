#include "ball.h"
//ref to window is need to calc width and height
ball::ball(Score* score1, Score* score2,
	paddle_player* player1, paddle_player* player2,
	sf::RenderWindow* window) {

	//load ball graphic
	this->Load("ball.png");
	this->score1 = score1;
	this->score2 = score2;

	//declare player vars for collision checks
	this->player1 = player1;
	this->player2 = player2;

	//create alias that don't need to be updated:
	//alias for ball properties
	ball_h = 32;
	ball_w = 32;
	
	//alias for player's heights
	p1_h = this->player1->getGlobalBounds().height;
	p2_w = this->player2->getGlobalBounds().width;
	p2_h = this->player2->getGlobalBounds().height;
	
	//alias for window properties
	window_h = window->getSize().y;
	window_w = window->getSize().x;
	scrn_left_bnd = this->player1->getGlobalBounds().width - 5.0f;
	scrn_right_bnd = this->player2->getGlobalBounds().width + 5.0f;
}

void ball::Update(sf::RenderWindow* window)
{
	//short aliases for paddle collision
	p1_collide = this->check_collision(this->player1);
	p2_collide = this->check_collision(this->player2);

	if (p1_collide || p2_collide)
	{
		this->velocity.x *= -1;
	}

	//shorter alias for ball position
	ball_x_pos = this->getPosition().x;
	ball_y_pos = this->getPosition().y;

	//screen top and bottom collision, respectively
	if (ball_y_pos < 0 || (ball_y_pos + ball_h) > window_h)
	{
		this->velocity.y *= -1;
	}

	//If ball gets past p1's paddle, p2 gets a point
	if (ball_x_pos < scrn_left_bnd)
	{
		this->score2->increment_score();
		this->Reset(window);
	}

	//If ball gets past p2's paddle, p1 gets a point
	if (ball_x_pos > window_w - scrn_right_bnd)
	{
		this->score1->increment_score();
		this->Reset(window);
	}
	Entity::Update();
}

void ball::Reset(sf::RenderWindow* window)
{
	//seed RNG for ball starting velocity
	srand((unsigned)time(NULL));
	//generate random number from 0-3
	int v_rand = rand() % 4;

	//make ball go 1 of 4 diagonals
	//based on random output
	switch (v_rand) {
	case 0:
	default:
		this->velocity.x = -4.75f;
		this->velocity.y = -4.75f;
		break;
	case 1:
		this->velocity.x = -4.75f;
		this->velocity.y = 4.75f;
		break;
	case 2:
		this->velocity.x = 4.75f;
		this->velocity.y = -4.75f;
		break;
	case 3:
		this->velocity.x = 4.75f;
		this->velocity.y = 4.75f;
		break;
	}

	//set ball position to window's center
	this->setPosition(window_w / 2, window_h / 2);
	
	//short alias for player's heights
	p1_h = this->player1->getGlobalBounds().height;
	p2_w = this->player2->getGlobalBounds().width;
	p2_h = this->player2->getGlobalBounds().height;

	//reset paddle postions
	this->player1->setPosition(0, window_h / 2 + p1_h / 4);
	this->player2->setPosition(window_w - p2_w, window_h / 2 + p2_h / 4);
}