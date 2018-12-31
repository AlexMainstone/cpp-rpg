#include "Scenes/Game.hpp"


Game::Game(sf::RenderWindow &window) : window(window), sheet("../res/tilemap.png", 8, 15) {
    map = new TileMap(sheet);
    camera = new Camera(window.getView());
}

void Game::handleEvent(sf::Event e) {
    camera->handleEvent(e);
}

void Game::draw() {
    window.setView(camera->getView());
    map->draw(window);
}

void Game::update(float dt) {

}

void Game::close() {

}