#include<iostream>
#include "game_state.h"
#include "test_state.h"
using namespace std;

game_state core_state;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "Plonk");

    core_state.set_window(&window);
    core_state.set_state(new test_state());
    //run program while window is open
    while (window.isOpen()) {
        //check window's events since last loop
        sf::Event event;
        while (window.pollEvent(event)) {
            //if user requests event "closed", close window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    core_state.Update();
    core_state.Render();
    //destructor handles deletion of core_state
    return 0;
}