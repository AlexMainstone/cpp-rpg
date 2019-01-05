#pragma once

#include <SFML/Graphics.hpp>
#include "Resources/SpriteSheet.hpp"

class AnimatedSprite {
    public:
        AnimatedSprite(int start, int end, float frametime, SpriteSheet *sheet);
        void update(float dt);
        void draw(sf::Vector2f pos, sf::RenderTarget &target);
    private:
        int start, end, tile;
        float time_passed, frame_time;

        // drawing
        SpriteSheet *sheet;
};