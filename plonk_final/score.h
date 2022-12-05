#pragma once
#include <SFML/graphics.hpp>

class Score : public sf::Text
{
public:
	Score(sf::Font &font, unsigned int size);
	void increment_score();
	void Update();
private:
	int value;
};

