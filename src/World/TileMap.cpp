#include "TileMap.hpp"
#include <stdlib.h>

TileMap::TileMap(SpriteSheet &sheet) : sheet(sheet) {

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            map[x][y] = rand() % (8 * 15);
        }
    }
}

void TileMap::draw(sf::RenderWindow &window) {
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            sheet.draw(map[x][y], sf::Vector2f(x * 16, y * 16), window);
        }
    }
}