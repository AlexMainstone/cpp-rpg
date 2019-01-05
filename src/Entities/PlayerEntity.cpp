#include "Entities/PlayerEntity.hpp"
#include "Resources/SpriteSheet.hpp"

PlayerEntity::PlayerEntity() {
    animated_sprite = new AnimatedSprite(0, 7, .1, new SpriteSheet("../res/characters/running.png", 8, 1));
}

void PlayerEntity::update(float dt) {
    animated_sprite->update(dt);
}

void PlayerEntity::handleEvent(sf::Event e) {
    
}

void PlayerEntity::draw(sf::RenderTarget &target) {
    animated_sprite->draw(sf::Vector2f(100.0, 100.0), target);
}