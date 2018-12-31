#include "Resources/SpriteSheet.hpp"


SpriteSheet::SpriteSheet(const char *path, int tiles_wide, int tiles_tall) {
    // Init variables
    this->tiles_wide = tiles_wide;
    this->tiles_tall = tiles_tall;

    // Load texture
    texture.loadFromFile(path);

    // Calculate the size of each tile
    sf::Vector2u size = texture.getSize();
    tile_width = size.x / tiles_wide;
    tile_height = size.y / tiles_tall;

    // Setup the sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, tile_width, tile_height));
}

void SpriteSheet::draw(int tile, sf::Vector2f pos, sf::RenderTarget &target) {
    // Set the position in the world
    sprite.setPosition(pos);

    // Set pos of sprite on texture
    sprite.setTextureRect(sf::IntRect((tile % tiles_wide) * tile_width, 
            (tile / tiles_wide) * tile_height,
            tile_width, tile_height));

    // Draw
    target.draw(sprite);
}