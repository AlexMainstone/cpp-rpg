#include "Scenes/Game.hpp"

Game::Game(sf::RenderWindow &window) : window(window), sheet("../res/sheets/tilemap.png", 8, 15) {
    map = new TileMap(sheet);
    camera = new Camera(window.getView());
    c = new Console(sf::Vector2f(5, 5));
    uiview = window.getView();

	entity = new PlayerEntity();
}

void Game::handleEvent(sf::Event e) {
    camera->handleEventWithWindow(e, window);
}

void Game::draw() {
    // Draw World
    window.setView(camera->getView());
    map->draw(window);
    entity->draw(window);

    // Draw UI
    window.setView(uiview);
    c->draw(window);
}

void Game::update(sf::Time dt) {
    entity->update(dt.asSeconds());
}

void Game::close() {
}