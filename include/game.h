#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "terrain.h"

class Game {
public : 
    Game();
    ~Game();

    void update();
    void render();

    const bool is_running() const {
        return this->window->isOpen();
    }

    void poll_events();

private :
    sf::RenderWindow* window;
    sf::Event ev;
    Terrain* terrain; // While waiting for a proper scene object we add all object to the base game
};