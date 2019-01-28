#include "Components/AnimatedSprite.hpp"


AnimatedSprite::AnimatedSprite(int start, int end, float frametime, SpriteSheet *sheet) {
   this->start = start;
   this->end = end; 
   this->time_passed = 0;
   this->tile = 0;
   this->frame_time = frametime;

    paused = false;
   this->sheet = sheet;
    flipped = false;
}

void AnimatedSprite::update(float dt) {
    if (paused) return;
    time_passed += dt;
    if(time_passed  > frame_time) {
        tile++;
        time_passed = 0;
        if(tile > end - start) {
            tile = 0;
        }
    }
}

void AnimatedSprite::draw(sf::Vector2f pos, sf::RenderTarget &target) {
    sheet->draw(start + tile, pos, target, flipped);
}