#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Console {
    public:
        Console(sf::Vector2f pos);
        void draw(sf::RenderTarget &target);
        void print(const char *t);
    private:
        sf::Vector2f position;
        sf::Font font;
        sf::Text text;
        std::vector<const char*> console_vector;
};