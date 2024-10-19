#pragma once

#include "sfml.h"
#include "terrain.h"
#include "player.h"
#include "entity.h"

/**
 * @brief The Game class is responsible to update the scene and render it
 * 
 */

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

    void check_collision(Entity& entity, Terrain& terrain);

private :
    sf::RenderWindow* window;
    sf::Event ev;
    Terrain* terrain; // While waiting for a proper scene object we add all object to the base game
    Player* player; // Kinda the same, it will need to be structured thanks to the Scene class
};