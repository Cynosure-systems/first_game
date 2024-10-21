#include "player.h"
#include <iostream>

Player::Player() {
    this->position = sf::Vector2f(150, 150);
    this->velocity = sf::Vector2f(0,0);
    this->is_on_ground = false;

    this->hitbox = sf::RectangleShape(sf::Vector2f(50, 50));
    this->hitbox.setFillColor(sf::Color::Blue);
    this->hitbox.setPosition(this->position);
}

void Player::update_input() { 
    /* Honestly not sure if the controls belong in this class 
    *  Maybe it belongs in the game class where the inputs control the player with getters and setters
    *  Although doing this might induce feature envy and long chain of calls... I dunno man
    */
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->position = sf::Vector2f(this->position.x - 1.f, this->position.y);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->position = sf::Vector2f(this->position.x + 1.f, this->position.y);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->is_on_ground) {
        this->velocity = sf::Vector2f(this->velocity.x, -30.f);
        this->is_on_ground = false;
    }
    
    this->hitbox.setPosition(this->position);
}

void Player::update() {
    this->update_input();
    float dt = 0.1;
    this->apply_gravity(dt);

    this->position += sf::Vector2f(this->velocity.x * dt, this->velocity.y * dt);
    this->hitbox.setPosition(this->position);

    
}