#pragma once

#include "Scene.hpp"

#include "../World/TileMap.hpp"

class Game : public Scene {
    public:
        Game(sf::RenderWindow &window);
        void handleEvent(sf::Event e);
        void draw();
        void update(float dt);
        void close();
    private:
        sf::RenderWindow &window;
        SpriteSheet sheet;
        TileMap *map;
};