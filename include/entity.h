#pragma once 

#include "sfml.h"

class Entity {
public :
    Entity() {
        life_state = 1.;
        g = 9.8f;};

    ~Entity() = default;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    
protected :
    void apply_gravity(float dt) {velocity.y += this->g * dt; };

    float life_state; // life : a value between 0 (dead) and 1
    sf::Vector2f hitbox; // The hitbox rectangle of the entity
    sf::Vector2f position; // The position of the entity;
    sf::Vector2f velocity; // The velocity of the entity

private :
    float g;
};