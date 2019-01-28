#pragma once

#include "../Resources/SpriteSheet.hpp"
#include "System/Navigation.hpp"

#include<vector>

class TileMap {
    public:
        TileMap(SpriteSheet &sheet);
        void draw(sf::RenderWindow &window);
        int getCost(int x, int y);
        void updateMap();
        std::vector<std::vector<Node>> navigate(sf::Vector2i start, short radius);
    private:
        struct Tile {
            short cost;
            short tile;
            Tile(short cost, short tile) {
                this->cost = cost;
                this->tile = tile;
            }
        };

        const int WIDTH = 100;
        const int HEIGHT = 100;
        Tile *map[100][100];
        SpriteSheet &sheet;

        sf::RenderTexture map_texture;
        sf::Sprite map_sprite;
};