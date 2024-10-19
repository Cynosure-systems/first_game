#pragma once

#include "entity.h"

class Player : public Entity {
public :
    Player();
    ~Player() = default;

    void update() override;

    void render(sf::RenderWindow& window) override {window.draw(this->hitbox);};
    
private :
};