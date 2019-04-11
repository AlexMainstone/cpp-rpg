#include "Scenes/Game.hpp"

Game::Game(sf::RenderWindow &window) : window(window), sheet("../res/sheets/tilemap.png", 8, 15)
{
    map = new TileMap(sheet);
    camera = new Camera(window.getView());
    c = new Console(sf::Vector2f(5, 5));
    c->print("STARTED", sf::Color::Green);
    uiview = window.getView();

    party = new Party();
    party->addMember(new PlayerCharacter(map));
    party->addMember(new PlayerCharacter(map));
    party->addMember(new PlayerCharacter(map));
}

void Game::handleEvent(sf::Event e)
{
    party->handleEvent(e);
    camera->handleEventWithWindow(e, window);
}

void Game::draw()
{
    // Draw World
    window.setView(camera->getView());
    map->draw(window);

    party->draw(window);
    party->setCurrent(camera->getMousePosition());

    // Draw UI
    window.setView(uiview);
    c->draw(window);
}

void Game::update(sf::Time dt)
{
    camera->update(dt.asSeconds());
    party->update(dt.asSeconds());
}

void Game::close()
{
}