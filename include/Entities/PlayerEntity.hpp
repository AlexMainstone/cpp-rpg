#pragma once

#include "Entities/Entity.hpp"

#include "Components/AnimatedSprite.hpp"

class PlayerEntity : public Entity {
    public:
        PlayerEntity();
        void update(float dt);
        void handleEvent(sf::Event e);
        void draw(sf::RenderTarget &target);
    private:
        // Components
        AnimatedSprite *animated_sprite;
};