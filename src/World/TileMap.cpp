#include "World/TileMap.hpp"
#include <stdlib.h>

TileMap::TileMap(SpriteSheet &sheet) : sheet(sheet)
{

    Tile *tile = new Tile(1, 1);
    Tile *tile2 = new Tile(-1, 30);
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            map[x][y] = tile;
        }
    }
    map[20][20] = tile2;
    map[21][20] = tile2;
    map[22][20] = tile2;
    map[23][20] = tile2;
    map[24][20] = tile2;
    map_texture.create(16 * WIDTH, 16 * HEIGHT);
    updateMap();
}

void TileMap::updateMap()
{
    map_texture.clear();
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            sheet.draw(map[x][y]->tile, sf::Vector2f(x * 16, y * 16), map_texture);
        }
    }
    map_texture.display();

    map_sprite.setTexture(map_texture.getTexture());
}

#include <iostream>
std::vector<std::vector<Node>> TileMap::navigate(sf::Vector2i start, short radius)
{
    std::vector<std::vector<int>> area;
    for (int x = start.x - radius / 2; x < start.x + radius / 2 + 1; x++)
    {
        if (x < 0 || x > 29)
        {
            area.push_back(std::vector<int>(radius * 2, -1));
            continue;
        }
        std::vector<int> v;
        for (int y = start.y - radius / 2; y < start.y + radius / 2 + 1; y++)
        {
            if (y < 0 || y > 29)
            {
                v.push_back(-1);
                continue;
            }
            // if((x - start.x) * (x - start.x) + (y - start.y) * (y - start.y) > (radius/2)*(radius/2)) {v.push_back(-1); continue;}
            v.push_back(map[x][y]->cost);
        }
        area.push_back(v);
    }
    return dijkstra(area, sf::Vector2i(radius / 2, radius / 2));
}

void TileMap::draw(sf::RenderWindow &window)
{
    window.draw(map_sprite);
}