#include "player.h"
#include <iostream>

Player::Player() {
    this->position = sf::Vector2f(150, 150);
    this->velocity = sf::Vector2f(0,0);

    this->hitbox = sf::RectangleShape(sf::Vector2f(50, 50));
    this->hitbox.setFillColor(sf::Color::Blue);
    this->hitbox.setPosition(this->position);
}

void Player::update() {
    //std::cout << "test" << std::endl;
    float dt = 0.01;
    this->apply_gravity(dt);

    this->position += sf::Vector2f(this->velocity.x * dt, this->velocity.y * dt);
    this->hitbox.setPosition(this->position);
}