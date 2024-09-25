#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

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
};