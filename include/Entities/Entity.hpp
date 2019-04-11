#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
    virtual void update(float dt) = 0;
    virtual void handleEvent(sf::Event e) = 0;
    virtual void draw(sf::RenderTarget &target) = 0;
};