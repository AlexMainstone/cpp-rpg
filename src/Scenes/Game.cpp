#include "Game.hpp"


Game::Game(sf::RenderWindow &window) : window(window), sheet("../res/tilemap.png", 8, 15) {
    map = new TileMap(sheet);
}

void Game::handleEvent(sf::Event e) {

}

void Game::draw() {
    map->draw(window);
}

void Game::update(float dt) {

}

void Game::close() {

}