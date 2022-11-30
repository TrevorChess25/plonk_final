#include<iostream>
#include "game_state.h"
#include "main_menu.h"
using namespace std;

game_state core_state;

int main()
{
    //window is created
    sf::RenderWindow game_window(sf::VideoMode(900, 600), "Plonk");

    core_state.set_window(&game_window);
    core_state.set_state(new main_menu());
    
    //run program while window is open
    while (game_window.isOpen()) {
        //check window's events since last loop
        sf::Event event;
        while (game_window.pollEvent(event)) {
            //if user requests event "closed", close window
            if (event.type == sf::Event::Closed) {
                game_window.close();
            }
        }
        game_window.clear(sf::Color::Black);

        //destructor handles deletion of core_state
        core_state.Update();
        core_state.Render();
        game_window.display();
    }
    return 0;
}