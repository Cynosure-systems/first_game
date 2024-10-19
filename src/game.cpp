#include "game.h"

Game::Game() {
    sf::VideoMode vm;
    vm.height = 500;
    vm.width = 500;

    this->window = new sf::RenderWindow(vm, "First game", sf::Style::Titlebar | sf::Style::Close);
    this->terrain = new Terrain(0, sf::Vector2f(100, 100), sf::Vector2f(50, 50), sf::Color::Green); // Initialize Terrain for testing


    this->player = new Player();
}

Game::~Game() {
    delete this->window;
}

void Game::poll_events() {
    while(this->window->pollEvent(this->ev)) {
        switch(this->ev.type) {
            case sf::Event::Closed :
                this->window->close();
                break;
            default : 
                break;
        }
    }
}

void Game::check_collision(Entity& entity, Terrain& terrain) {
    auto tiles = terrain.get_tiles();
    auto hitbox = entity.get_hitbox().getGlobalBounds();

    int start_index = hitbox.left / 50;
    int end_index = ( hitbox.left + hitbox.width ) / 50;

    //std::cout << "start : " << start_index << std::endl;
    //std::cout << "end : " << end_index << std::endl;

    for (int i = start_index; i <= end_index; ++i) {
        auto tile = tiles[i].getGlobalBounds();
        if (hitbox.intersects(tile)) 
            entity.resolve_collision(tile); // Handle collision
    }
}

void Game::update() {
    this->poll_events();

    this->player->update();
    this->check_collision(*this->player, *this->terrain);
}

void Game::render() {
    this->window->clear(sf::Color::Black);

    this->player->render(*this->window);
    this->terrain->render(*this->window);

    this->window->display();
}