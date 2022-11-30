#include "main_menu.h"
using namespace std;
void main_menu::Init(sf::RenderWindow* window) {
	//allocates memory for font
	this->font = new sf::Font();
	this->font->loadFromFile("font.ttf");
	this->title = new sf::Text("Plonk", *this->font,192U);
};
void main_menu::Update(sf::RenderWindow* window) {
};
void main_menu::Render(sf::RenderWindow* window) {
	window->draw(*this->title);
};
void main_menu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
};