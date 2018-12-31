#pragma once

#include <SFML/Graphics.hpp>

class SpriteSheet {
    public:
        SpriteSheet(const char *path, int tileW, int tileH);
        void draw(int tile, sf::Vector2f pos, sf::RenderTarget &target);
    private:
        int tiles_tall, tiles_wide;
        int tile_width, tile_height;

        // SFML sprite objects
        sf::Texture texture;
        sf::Sprite  sprite;
};