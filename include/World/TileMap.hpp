#pragma once

#include "../Resources/SpriteSheet.hpp"

class TileMap {
    public:
        TileMap(SpriteSheet &sheet);
        void draw(sf::RenderWindow &window);
        void updateMap();
    private:
        const int WIDTH = 100;
        const int HEIGHT = 100;
        short map[100][100];
        SpriteSheet &sheet;

       sf::RenderTexture map_texture;
       sf::Sprite map_sprite;
};