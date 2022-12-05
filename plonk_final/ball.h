#pragma once
#include<SFML/Audio.hpp>
#include "paddle_player.h"
#include "score.h"
#include<cstdlib>


class ball : public Entity {
public:
	//prototypes for ball funcs
	ball(Score* score1, Score* score2,
		paddle* player1, paddle* player2,
		sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);
	~ball();
private:
	Score* score1;
	Score* score2;
	//paddle refs are needed to check collision
	paddle* player1;
	paddle* player2;
	sf::SoundBuffer* buffer;
	sf::Sound* sound;

	bool p1_collide, p2_collide;
	float ball_x_pos, ball_y_pos, ball_spd;
	int scrn_left_bnd, scrn_right_bnd;
	int ball_w, ball_h;
	int p1_h, p2_w, p2_h;
	int window_w, window_h;
};