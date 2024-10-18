#pragma once 

#include "sfml.h"
/**
 * @brief Terrain represents the terrain on which the entities evolve
 * 
 * The terrain is a collection of tiles representing the ground. The tiles are represented as a vector of int
 * which is the altitude of the ground tile. For a flat terrain, the ints are all the same for instance.
 * The tiles are sf::RectangleShapes. 
 */

class Terrain {
public:
    Terrain(int type, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color);
    ~Terrain();

    void set_type(int type);
    int get_type() const;

    void render(sf::RenderWindow& window);

    sf::RectangleShape shape; // This should be private and need to surchage draw for this class
    // no need to surcharge draw, we just create a "render" method that calls it for every tile of the terrain
private:
    int type; // Three types 0, 1 and 2 to define later
    sf::Color color;
    sf::Vector2f position;
    sf::Vector2f size;

    std::vector<int> tiles_y;
    std::vector<sf::RectangleShape> tiles;
};

