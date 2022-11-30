#include <iostream>
#include "test_state.h"
using namespace std;
void test_state::Init(sf::RenderWindow* window) {
	cout << "Initialized" << endl;
	//this->paused = false;
};
void test_state::Update(sf::RenderWindow* window) {
	cout << "Updated" << endl;
	/*
	if (!paused) {
		//normal game here
	}
	else {
		//paused game here
	}
	*/
};
void test_state::Render(sf::RenderWindow* window) {
	cout << "Rendered" << endl;

};
void test_state::Destroy(sf::RenderWindow* window) {
	cout << "Destroyed" << endl;
};