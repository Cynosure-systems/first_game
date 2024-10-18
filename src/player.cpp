#include "player.h"

Player::Player() {
    shape = sf::RectangleShape(sf::Vector2f(50, 50));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(150,150);
}