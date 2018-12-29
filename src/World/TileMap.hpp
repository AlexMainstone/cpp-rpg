#pragma once

#include "../Resources/SpriteSheet.hpp"

class TileMap {
    public:
        TileMap(SpriteSheet &sheet);
        void draw(sf::RenderWindow &window);
    private:
        const int WIDTH = 100;
        const int HEIGHT = 100;
        int map[100][100];
        SpriteSheet &sheet;

       
};