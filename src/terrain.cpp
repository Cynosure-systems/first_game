//
// Created by doph on 10/12/24.
//
#include "terrain.h"
Terrain::Terrain(int type, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) : type(type), position(position), size(size), color(color) {

    this->tiles_y = {400, 400, 400, 400, 400, 390, 380, 370, 370, 380};

    for(int i = 0; i<this->tiles_y.size(); ++i) {
        auto tile = sf::RectangleShape(sf::Vector2f(50, 5));
        tile.setFillColor(sf::Color::Green);
        tile.setPosition(50*i, tiles_y[i]);

        this->tiles.push_back(tile);
    }

}

Terrain::~Terrain() {

}

void Terrain::render(sf::RenderWindow& window) {
    for(auto& tile : this->tiles)
        window.draw(tile);
}

void Terrain::set_type(int type) {
    this->type = type;
}

int Terrain::get_type() const {
    return this->type;
}