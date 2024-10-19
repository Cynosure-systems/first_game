#pragma once 

#include "sfml.h"

class Entity {
public :
    Entity() {
        life_state = 1.;
        g = 9.8f;};

    ~Entity() = default;

    sf::RectangleShape get_hitbox() {return this->hitbox; };

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    void resolve_collision(sf::FloatRect& shape) {
        auto entity_shape = this->hitbox.getGlobalBounds();

        //collision on the left

        //collision on the right
        //collision on the bottom
        if(entity_shape.top - entity_shape.height < shape.top) {
            this->velocity.y = 0.f;
            this->position.y -= this->position.y + entity_shape.height - shape.top;
            this->hitbox.setPosition(this->position);
        }
        //collision on the top
    }
    
protected :
    void apply_gravity(float dt) {velocity.y += this->g * dt; };

    float life_state; // life : a value between 0 (dead) and 1
    sf::RectangleShape hitbox; // The hitbox rectangle of the entity
    sf::Vector2f position; // The position of the entity;
    sf::Vector2f velocity; // The velocity of the entity

private :
    float g;
};