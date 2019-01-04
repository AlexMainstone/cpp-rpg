#include "Scenes/Game.hpp"

Game::Game(sf::RenderWindow &window) : window(window), sheet("../res/sheets/tilemap.png", 8, 15) {
    map = new TileMap(sheet);
    camera = new Camera(window.getView());
    c = new Console(sf::Vector2f(5, 5));
    uiview = window.getView();
}

void Game::handleEvent(sf::Event e) {
    camera->handleEvent(e);
    c->print("yo");
}

void Game::draw() {
    // Draw World
    window.setView(camera->getView());
    map->draw(window);

    // Draw UI
    window.setView(uiview);
    c->draw(window);
}

void Game::update(sf::Time dt) {
}

void Game::close() {
}