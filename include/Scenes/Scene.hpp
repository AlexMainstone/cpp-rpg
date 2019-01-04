#pragma once
#include <SFML/Graphics.hpp>

class Scene {
    public:
        virtual void handleEvent(sf::Event e) = 0;
        virtual void draw() = 0;
        virtual void update(sf::Time dt) = 0;
        virtual void close() = 0;
};