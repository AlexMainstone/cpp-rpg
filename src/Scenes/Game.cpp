#include "Scenes/Game.hpp"

Game::Game(sf::RenderWindow &window) : window(window), sheet("../res/sheets/tilemap.png", 8, 15) {
    map = new TileMap(sheet);
    camera = new Camera(window.getView());
    c = new Console(sf::Vector2f(5, 5));
    c->print("STARTED", sf::Color::Green);
    uiview = window.getView();

	entity = new PlayerCharacter(map);
}

void Game::handleEvent(sf::Event e) {
    camera->handleEventWithWindow(e, window);
    entity->handleEvent(e);
}

void Game::draw() {
    // Draw World
    window.setView(camera->getView());
    map->draw(window);
    entity->draw(window);

    entity->setCurrent(camera->getMousePosition());

    // Draw UI
    window.setView(uiview);
    c->draw(window);
}

void Game::update(sf::Time dt) {
    camera->update(dt.asSeconds());
    entity->update(dt.asSeconds());
}

void Game::close() {
}