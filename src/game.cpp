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

void Game::update() {
    this->poll_events();
}

void Game::render() {
    this->window->clear(sf::Color::Black);
    this->window->draw(this->terrain->shape);
    this->player->render(*this->window);

    this->window->display();
}