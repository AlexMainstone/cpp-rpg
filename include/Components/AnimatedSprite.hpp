#pragma once

#include <SFML/Graphics.hpp>
#include "Resources/SpriteSheet.hpp"

class AnimatedSprite {
    public:
        AnimatedSprite(int start, int end, float frametime, SpriteSheet *sheet);
        void update(float dt);
        void draw(sf::Vector2f pos, sf::RenderTarget &target);

        void setPaused(bool p) { paused = p; }
        void flip(bool f = true) { flipped = f; }
    private:
        bool flipped;
        int start, end, tile;
        float time_passed, frame_time;

        bool paused;
        // drawing
        SpriteSheet *sheet;
};