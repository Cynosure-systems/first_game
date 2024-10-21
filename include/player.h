#pragma once

#include "entity.h"

/**
 * @brief The player is the entity of interest in the game
 * 
 */

class Player : public Entity {
public :
    Player();
    ~Player() = default;

    void update_input();
    void update() override;

    void render(sf::RenderWindow& window) override {window.draw(this->hitbox);};
    
private :
};