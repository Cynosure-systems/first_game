//
// Created by doph on 10/12/24.
//
#include "terrain.h"
Terrain::Terrain(int type, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) : type(type), position(position), size(size), color(color) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}

Terrain::~Terrain() {

}

void Terrain::set_type(int type) {
    this->type = type;
}

int Terrain::get_type() const {
    return this->type;
}