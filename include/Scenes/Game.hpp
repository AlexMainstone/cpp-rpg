#pragma once

#include "Scene.hpp"

#include "Interface/Camera.hpp"
#include "World/TileMap.hpp"
#include "Interface/Console.hpp"

class Game : public Scene {
    public:
        Game(sf::RenderWindow &window);
        void handleEvent(sf::Event e);
        void draw();
        void update(sf::Time dt);
        void close();
    private:
        sf::RenderWindow &window;
        SpriteSheet sheet;
        TileMap *map;
        Camera *camera;

        Console *c;
        sf::View uiview;
};