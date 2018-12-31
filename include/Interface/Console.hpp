#pragma once

#include <SFML/Graphics.hpp>

class Console {
    public:
        Console(sf::Vector2f pos);
        void draw(sf::RenderTarget &target);
        void print(const char *text);
    private:
        sf::Text text;
};