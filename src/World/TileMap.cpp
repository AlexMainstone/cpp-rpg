#include "World/TileMap.hpp"
#include <stdlib.h>

TileMap::TileMap(SpriteSheet &sheet) : sheet(sheet) {

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            int grass[] = {11, 12, 8*8, 8*8+1};
            map[x][y] = grass[rand() % (sizeof(grass)/sizeof(*grass))];
        }
    }
    map_texture.create(16*WIDTH, 16*HEIGHT);
    updateMap();
}

void TileMap::updateMap() {
    map_texture.clear();
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            sheet.draw(map[x][y], sf::Vector2f(x * 16, y * 16), map_texture);
        }
    }
    map_texture.display();

    map_sprite.setTexture(map_texture.getTexture());
}

void TileMap::draw(sf::RenderWindow &window) {
    window.draw(map_sprite);
}