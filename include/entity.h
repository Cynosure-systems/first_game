#pragma once 

#include "sfml.h"

/**
 * @brief An entity is anything that is alive in the game
 * 
 */

class Entity {
public :
    Entity() {
        life_state = 1.;
        g = 9.8f;};

    ~Entity() = default;

    sf::RectangleShape get_hitbox() {return this->hitbox; };

    /**
     * @brief update : pure virtual function so every being updates as they please
     * 
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual as well since we don't know how the entity will be rendered
     * 
     * @param window the window in which the entity is rendered
     */
    virtual void render(sf::RenderWindow& window) = 0;

    /**
     * @brief a function to resolve the collision with an object
     * 
     * @param shape the shape with which the entity is in collision
     */
    void resolve_collision(sf::FloatRect& shape) {
        auto entity_shape = this->hitbox.getGlobalBounds();

        //collision on the left
        // TODO
        //collision on the right
        // TO DO
        //collision on the bottom
        if(entity_shape.top - entity_shape.height < shape.top) {
            this->velocity.y = 0.f;
            this->position.y -= this->position.y + entity_shape.height - shape.top;
            this->hitbox.setPosition(this->position);
        }
        //collision on the top
        // TO DO
    }
    
protected :
    void apply_gravity(float dt) {velocity.y += this->g * dt; }; // Just a function to update the acceleration of the entity

    float life_state; // life : a value between 0 (dead) and 1
    sf::RectangleShape hitbox; // The hitbox rectangle of the entity
    sf::Vector2f position; // The position of the entity;
    sf::Vector2f velocity; // The velocity of the entity

private :
    float g;
};