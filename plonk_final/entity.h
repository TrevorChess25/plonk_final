#pragma once
#include<SFML/Graphics.hpp>
#include<string>
using namespace std;

class Entity: public sf::Sprite {
public:
	Entity() {
		//init texture
		this->texture = new sf::Texture();
	};

	void Load(string filename) {
		this->texture->loadFromFile("Graphics/sprites/"+filename);
		this->setTexture(*this->texture);
	}

	//moves object based on its velocity
	virtual void Update() { //Update is virtual so it can be overriden
		this->move(this->velocity);
	}

	//returns true if entities bounds intersect
	bool check_collision(Entity* entity) {
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	~Entity() {
		delete this->texture;
	}
protected:
	//protected so v can be used in entity subclasses
	sf::Vector2f velocity;

private:
	sf::Texture* texture;
};